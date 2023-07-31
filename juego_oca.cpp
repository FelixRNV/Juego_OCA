#include "juego_oca.h"
#include "ui_juego_oca.h"

Juego_OCA::Juego_OCA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego_OCA),m_music(this)
{
    ui->setupUi(this);
    ui->btnDado->setEnabled(false);
    m_music.setSource(QUrl::fromLocalFile(":/Resources/Sound/fondo1.wav"));
    m_music.setLoopCount(QSoundEffect::Infinite);
    m_music.setVolume(0.30f);
    m_music.play();

}

Juego_OCA::~Juego_OCA()
{
    delete ui;
}


void Juego_OCA::on_action_Nuevo_triggered()
{
    NewJuego ne(this);
    if(ne.exec()==QDialog::Accepted){
        p1=ne.p1();
        p2=ne.p2();
        p3=ne.p3();
        p4=ne.p4();
        m_level=ne.level();
        m_tema=ne.Tema();
        ui->ltxJugador->setText(p1->name());
        ui->btnDado->setEnabled(true);
        m_juegan=ne.jueg();
        qDebug() << "Juegan: " << m_juegan;
    }else {
        //return;
    }
    // Borro posiciones previas
    ui->widCasi_0->deseableAV(1);
    ui->widCasi_0->deseableAV(2);
    ui->widCasi_0->deseableAV(3);
    ui->widCasi_0->deseableAV(4);

    switch (m_juegan){
    case 0:
        activatedAv(0,1);
        //ui->widCasi_0->enableAV(p1->avatar()+1);
        ui->widCasi_0->enableAV(p2->avatar()+1);
        break;
    case 1:
        ui->widCasi_0->enableAV(p1->avatar()+1);
        ui->widCasi_0->enableAV(p2->avatar()+1);
        ui->widCasi_0->enableAV(p3->avatar()+1);
        break;
    case 2:
        ui->widCasi_0->enableAV(p1->avatar()+1);
        ui->widCasi_0->enableAV(p2->avatar()+1);
        ui->widCasi_0->enableAV(p3->avatar()+1);
        ui->widCasi_0->enableAV(p4->avatar()+1);
        break;
    }

    cargarPreguntas();
}


void Juego_OCA::on_action_Tem_ticas_triggered()
{
    NewTematica te(this);
    int res = te.exec();
    if (res== QDialog::Rejected)
        return;
}



void Juego_OCA::on_btnDado_released()
{
    int dado;

    QStringList pregu=preguntas.pop().split(";");

    dado = QRandomGenerator::system()->bounded(1,6);
    setDado(dado);
    if (gana==1||gana==2||gana==3||gana==4){
        ui->ltxNotifi->setText(gnj);
        return;
    }

    qDebug() << "Jugador: " << jug;
    if (jug==1){
        if (!p1->lost()){
            if (!p1->getM_3t()){
                if (!casilleroSpe(dado,jug)){
                    QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
                    if  (respons==QMessageBox::Yes){

                        if(pregu[1]=="V"){
                            qDebug() << "Posicion: " << p1->posicion();
                            ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                            ui->ltx_resp->setText("Respuesta Correcta");
                            disactivatedAv(p1->posicion(),1);
                            p1->setPosicion(dado+p1->posicion());
                            activatedAv(p1->posicion(),1);
                        }
                    } else {
                        if(pregu[1]=="F"){
                            qDebug() << "Falso";
                            ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                            ui->ltx_resp->setText("Respuesta Correcta");
                            disactivatedAv(p1->posicion(),1);
                            p1->setPosicion(dado+p1->posicion());
                            activatedAv(p1->posicion(),1);
                        }
                    }
                } else{
                    ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/cancel.png);");
                    ui->ltx_resp->setText("Respuesta Incorrecta");
                    jug=jug_n-1;}

            }else {
                if(turno<3){
                    turno++;
                }else {
                    p1->setM_3t(false);
                }
            }}} else if (jug==2){
            if (!casilleroSpe(dado,jug)){
                QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
                if  (respons==QMessageBox::Yes){
                    if(pregu[1]=="V"){
                        ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                        ui->ltx_resp->setText("Respuesta Correcta");
                        disactivatedAv(p2->posicion(),2);
                        p2->setPosicion(dado+p2->posicion());
                        activatedAv(p2->posicion(),2);
                    }} else {
                    if(pregu[1]=="F"){
                        ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                        ui->ltx_resp->setText("Respuesta Correcta");
                        disactivatedAv(p2->posicion(),2);
                        p2->setPosicion(dado+p2->posicion());
                        activatedAv(p2->posicion(),2);
                    }
                }
            } else{
                ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/cancel.png);");
                ui->ltx_resp->setText("Respuesta Incorrecta");
                jug=jug_n-1;
            }
        } else if (jug==3){
            if (!casilleroSpe(dado,jug)){
                QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
                if  (respons==QMessageBox::Yes){
                    if(pregu[1]=="V"){
                        ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                        ui->ltx_resp->setText("Respuesta Correcta");
                        disactivatedAv(p3->posicion(),3);
                        p3->setPosicion(dado+p3->posicion());
                        activatedAv(p3->posicion(),3);
                    }} else {
                    if(pregu[1]=="F"){
                        ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                        ui->ltx_resp->setText("Respuesta Correcta");
                        disactivatedAv(p3->posicion(),3);
                        p3->setPosicion(dado+p3->posicion());
                        activatedAv(p3->posicion(),3);
                    }
                }
            } else{
                ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/cancel.png);");
                ui->ltx_resp->setText("Respuesta Incorrecta");
                jug=jug_n-1;
            }
        } else if (jug==4){
            if (!casilleroSpe(dado,jug)){
                QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
                if  (respons==QMessageBox::Yes){
                    if(pregu[1]=="V"){
                        ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                        ui->ltx_resp->setText("Respuesta Correcta");
                        disactivatedAv(p4->posicion(),4);
                        p4->setPosicion(dado+p4->posicion());
                        activatedAv(p4->posicion(),4);
                    }} else {
                    if(pregu[1]=="F"){
                        ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/checked.png);");
                        ui->ltx_resp->setText("Respuesta Correcta");
                        disactivatedAv(p4->posicion(),4);
                        p4->setPosicion(dado+p4->posicion());
                        activatedAv(p4->posicion(),4);
                    }
                }
            } else{
                ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/cancel.png);");
                ui->ltx_resp->setText("Respuesta Incorrecta");
                jug=jug_n-1;
            }
        }

        jug++;
        if(jug>m_juegan+2)
            jug=1;
        setTimer(2);
        //ui->ltx_ICON->setStyleSheet("border-image: url(:/Resources/Untitled.png);");
        //ui->ltx_resp->setText("");
        setJugador(jug);
        setCasilleros(jug);
    }


    void Juego_OCA::on_action_Reglas_triggered()
    {
        // Cargar el archivo PDF desde el recurso de Qt
        QFile pdfFile(ARCHIVO);

        // Verificar si el archivo PDF se puede abrir correctamente
        if (!pdfFile.open(QIODevice::ReadOnly))
        {
            qDebug() << "Error al abrir el archivo PDF.";
            return;
        }

        // Obtener la ruta temporal para guardar el archivo
        QString tempFilePath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/reglamento_temp.pdf";

        // Crear un archivo temporal para guardar el contenido del PDF
        QFile tempFile(tempFilePath);
        if (!tempFile.open(QIODevice::WriteOnly))
        {
            qDebug() << "Error al guardar el archivo PDF temporalmente.";
            pdfFile.close();
            return;
        }

        // Leer el contenido del PDF desde el recurso y escribirlo en el archivo temporal
        tempFile.write(pdfFile.readAll());

        // Cerrar ambos archivos
        pdfFile.close();
        tempFile.close();

        // Abrir el archivo PDF usando el visor de PDF predeterminado del sistema
        QDesktopServices::openUrl(QUrl::fromLocalFile(tempFilePath));
    }

    void Juego_OCA::on_actionA_cerca_de_triggered()
    {
        Acercade ventanaAcercaDe;
        ventanaAcercaDe.exec();
    }

    void Juego_OCA::on_action_Salir_triggered()
    {
        close();
    }

    void Juego_OCA::activatedAv(int casil, int jug)
    {
        Jugadores *pa= new Jugadores;
        switch (jug){
        case 1:
            pa->setJuga(p1->name(),p1->posicion(),p1->avatar()+1);
            break;
        case 2:
            pa->setJuga(p2->name(),p2->posicion(),p2->avatar()+1);
            break;
        case 3:
            pa->setJuga(p3->name(),p3->posicion(),p3->avatar()+1);
            break;
        case 4:
            pa->setJuga(p4->name(),p4->posicion(),p4->avatar()+1);
            break;
        }


        switch (casil){
        case 0:
            ui->widCasi_0->enableAV(pa->avatar());
            break;
        case 1:
            ui->widCasi_1->enableAV(pa->avatar());
            break;
        case 2:
            ui->widCasi_2->enableAV(pa->avatar());
            break;
        case 3:
            ui->widCasi_3->enableAV(pa->avatar());
            break;
        case 4:
            ui->widCasi_4->enableAV(pa->avatar());
            break;
        case 5:
            ui->widCasi_5->enableAV(pa->avatar());
            break;
        case 6:
            ui->widCasi_6->enableAV(pa->avatar());
            break;
        case 7:
            ui->widCasi_7->enableAV(pa->avatar());
            break;
        case 8:
            ui->widCasi_8->enableAV(pa->avatar());
            break;
        case 9:
            ui->widCasi_9->enableAV(pa->avatar());
            break;
        case 10:
            ui->widCasi_10->enableAV(pa->avatar());
            break;
        case 11:
            ui->widCasi_11->enableAV(pa->avatar());
            break;
        case 12:
            ui->widCasi_12->enableAV(pa->avatar());
            break;
        case 13:
            ui->widCasi_13->enableAV(pa->avatar());
            break;
        case 14:
            ui->widCasi_14->enableAV(pa->avatar());
            break;
        case 15:
            ui->widCasi_15->enableAV(pa->avatar());
            break;
        case 16:
            ui->widCasi_16->enableAV(pa->avatar());
            break;
        case 17:
            ui->widCasi_17->enableAV(pa->avatar());
            break;
        case 18:
            ui->widCasi_18->enableAV(pa->avatar());
            break;
        case 19:
            ui->widCasi_19->enableAV(pa->avatar());
            break;
        case 20:
            ui->widCasi_20->enableAV(pa->avatar());
            break;
        case 21:
            ui->widCasi_21->enableAV(pa->avatar());
            break;
        case 22:
            ui->widCasi_22->enableAV(pa->avatar());
            break;
        case 23:
            ui->widCasi_23->enableAV(pa->avatar());
            break;
        case 24:
            ui->widCasi_24->enableAV(pa->avatar());
            break;
        case 25:
            ui->widCasi_25->enableAV(pa->avatar());
            break;
        case 26:
            ui->widCasi_26->enableAV(pa->avatar());
            break;
        case 27:
            ui->widCasi_27->enableAV(pa->avatar());
            break;
        case 28:
            ui->widCasi_28->enableAV(pa->avatar());
            break;
        case 29:
            ui->widCasi_29->enableAV(pa->avatar());
            break;
        case 30:
            ui->widCasi_30->enableAV(pa->avatar());
            break;
        case 31:
            ui->widCasi_31->enableAV(pa->avatar());
            break;
        case 32:
            ui->widCasi_32->enableAV(pa->avatar());
            break;
        case 33:
            ui->widCasi_33->enableAV(pa->avatar());
            break;
        case 34:
            ui->widCasi_34->enableAV(pa->avatar());
            break;
        case 35:
            ui->widCasi_35->enableAV(pa->avatar());
            break;
        case 36:
            ui->widCasi_36->enableAV(pa->avatar());
            break;
        case 37:
            ui->widCasi_37->enableAV(pa->avatar());
            break;
        case 38:
            ui->widCasi_38->enableAV(pa->avatar());
            break;
        case 39:
            ui->widCasi_39->enableAV(pa->avatar());
            break;
        case 40:
            ui->widCasi_40->enableAV(pa->avatar());
            break;
        case 41:
            ui->widCasi_41->enableAV(pa->avatar());
            break;
        case 42:
            ui->widCasi_42->enableAV(pa->avatar());
            break;
        case 43:
            ui->widCasi_43->enableAV(pa->avatar());
            break;
        case 44:
            ui->widCasi_44->enableAV(pa->avatar());
            break;
        case 45:
            ui->widCasi_45->enableAV(pa->avatar());
            break;
        case 46:
            ui->widCasi_46->enableAV(pa->avatar());
            break;
        case 47:
            ui->widCasi_47->enableAV(pa->avatar());
            break;
        case 48:
            ui->widCasi_48->enableAV(pa->avatar());
            break;
        case 49:
            ui->widCasi_49->enableAV(pa->avatar());
            break;
        case 50:
            ui->widCasi_50->enableAV(pa->avatar());
            break;
        case 51:
            ui->widCasi_51->enableAV(pa->avatar());
            break;
        case 52:
            ui->widCasi_52->enableAV(pa->avatar());
            break;
        case 53:
            ui->widCasi_53->enableAV(pa->avatar());
            break;
        case 54:
            ui->widCasi_54->enableAV(pa->avatar());
            break;
        case 55:
            ui->widCasi_55->enableAV(pa->avatar());
            break;
        case 56:
            ui->widCasi_56->enableAV(pa->avatar());
            break;
        case 57:
            ui->widCasi_57->enableAV(pa->avatar());
            break;
        case 58:
            ui->widCasi_58->enableAV(pa->avatar());
            break;
        case 59:
            ui->widCasi_59->enableAV(pa->avatar());
            break;
        case 60:
            ui->widCasi_60->enableAV(pa->avatar());
            break;
        case 61:
            ui->widCasi_61->enableAV(pa->avatar());
            break;
        case 62:
            ui->widCasi_62->enableAV(pa->avatar());
            break;
        case 63:
            ui->widCasi_63->enableAV(pa->avatar());
            break;
        }
        delete pa;
    }

    void Juego_OCA::disactivatedAv(int casil, int jug)
    {
        Jugadores *pa= new Jugadores;
        switch (jug){
        case 1:
            pa->setJuga(p1->name(),p1->posicion(),p1->avatar()+1);
            break;
        case 2:
            pa->setJuga(p2->name(),p2->posicion(),p2->avatar()+1);
            break;
        case 3:
            pa->setJuga(p3->name(),p3->posicion(),p3->avatar()+1);
            break;
        case 4:
            pa->setJuga(p4->name(),p4->posicion(),p4->avatar()+1);
            break;
        }
        qDebug() << "pa postion: " <<pa->posicion()<<"pa avatar: "<<pa->avatar();
        switch (casil){
        case 0:
            ui->widCasi_0->deseableAV(pa->avatar());
            qDebug() << "Se eliminó en la casilla 0 al avatar" << pa->avatar();
            break;
        case 1:
            ui->widCasi_1->deseableAV(pa->avatar());
            break;
        case 2:
            ui->widCasi_2->deseableAV(pa->avatar());
            break;
        case 3:
            ui->widCasi_3->deseableAV(pa->avatar());
            break;
        case 4:
            ui->widCasi_4->deseableAV(pa->avatar());
            break;
        case 5:
            ui->widCasi_5->deseableAV(pa->avatar());
            break;
        case 6:
            ui->widCasi_6->deseableAV(pa->avatar());
            break;
        case 7:
            ui->widCasi_7->deseableAV(pa->avatar());
            break;
        case 8:
            ui->widCasi_8->deseableAV(pa->avatar());
            break;
        case 9:
            ui->widCasi_9->deseableAV(pa->avatar());
            break;
        case 10:
            ui->widCasi_10->deseableAV(pa->avatar());
            break;
        case 11:
            ui->widCasi_11->deseableAV(pa->avatar());
            break;
        case 12:
            ui->widCasi_12->deseableAV(pa->avatar());
            break;
        case 13:
            ui->widCasi_13->deseableAV(pa->avatar());
            break;
        case 14:
            ui->widCasi_14->deseableAV(pa->avatar());
            break;
        case 15:
            ui->widCasi_15->deseableAV(pa->avatar());
            break;
        case 16:
            ui->widCasi_16->deseableAV(pa->avatar());
            break;
        case 17:
            ui->widCasi_17->deseableAV(pa->avatar());
            break;
        case 18:
            ui->widCasi_18->deseableAV(pa->avatar());
            break;
        case 19:
            ui->widCasi_19->deseableAV(pa->avatar());
            break;
        case 20:
            ui->widCasi_20->deseableAV(pa->avatar());
            break;
        case 21:
            ui->widCasi_21->deseableAV(pa->avatar());
            break;
        case 22:
            ui->widCasi_22->deseableAV(pa->avatar());
            break;
        case 23:
            ui->widCasi_23->deseableAV(pa->avatar());
            break;
        case 24:
            ui->widCasi_24->deseableAV(pa->avatar());
            break;
        case 25:
            ui->widCasi_25->deseableAV(pa->avatar());
            break;
        case 26:
            ui->widCasi_26->deseableAV(pa->avatar());
            break;
        case 27:
            ui->widCasi_27->deseableAV(pa->avatar());
            break;
        case 28:
            ui->widCasi_28->deseableAV(pa->avatar());
            break;
        case 29:
            ui->widCasi_29->deseableAV(pa->avatar());
            break;
        case 30:
            ui->widCasi_30->deseableAV(pa->avatar());
            break;
        case 31:
            ui->widCasi_31->deseableAV(pa->avatar());
            break;
        case 32:
            ui->widCasi_32->deseableAV(pa->avatar());
            break;
        case 33:
            ui->widCasi_33->deseableAV(pa->avatar());
            break;
        case 34:
            ui->widCasi_34->deseableAV(pa->avatar());
            break;
        case 35:
            ui->widCasi_35->deseableAV(pa->avatar());
            break;
        case 36:
            ui->widCasi_36->deseableAV(pa->avatar());
            break;
        case 37:
            ui->widCasi_37->deseableAV(pa->avatar());
            break;
        case 38:
            ui->widCasi_38->deseableAV(pa->avatar());
            break;
        case 39:
            ui->widCasi_39->deseableAV(pa->avatar());
            break;
        case 40:
            ui->widCasi_40->deseableAV(pa->avatar());
            break;
        case 41:
            ui->widCasi_41->deseableAV(pa->avatar());
            break;
        case 42:
            ui->widCasi_42->deseableAV(pa->avatar());
            break;
        case 43:
            ui->widCasi_43->deseableAV(pa->avatar());
            break;
        case 44:
            ui->widCasi_44->deseableAV(pa->avatar());
            break;
        case 45:
            ui->widCasi_45->deseableAV(pa->avatar());
            break;
        case 46:
            ui->widCasi_46->deseableAV(pa->avatar());
            break;
        case 47:
            ui->widCasi_47->deseableAV(pa->avatar());
            break;
        case 48:
            ui->widCasi_48->deseableAV(pa->avatar());
            break;
        case 49:
            ui->widCasi_49->deseableAV(pa->avatar());
            break;
        case 50:
            ui->widCasi_50->deseableAV(pa->avatar());
            break;
        case 51:
            ui->widCasi_51->deseableAV(pa->avatar());
            break;
        case 52:
            ui->widCasi_52->deseableAV(pa->avatar());
            break;
        case 53:
            ui->widCasi_53->deseableAV(pa->avatar());
            break;
        case 54:
            ui->widCasi_54->deseableAV(pa->avatar());
            break;
        case 55:
            ui->widCasi_55->deseableAV(pa->avatar());
            break;
        case 56:
            ui->widCasi_56->deseableAV(pa->avatar());
            break;
        case 57:
            ui->widCasi_57->deseableAV(pa->avatar());
            break;
        case 58:
            ui->widCasi_58->deseableAV(pa->avatar());
            break;
        case 59:
            ui->widCasi_59->deseableAV(pa->avatar());
            break;
        case 60:
            ui->widCasi_60->deseableAV(pa->avatar());
            break;
        case 61:
            ui->widCasi_61->deseableAV(pa->avatar());
            break;
        case 62:
            ui->widCasi_62->deseableAV(pa->avatar());
            break;
        case 63:
            ui->widCasi_63->deseableAV(pa->avatar());
            break;
        }
        delete pa;
    }

    void Juego_OCA::cargarPreguntas()
    {
        QString path = "Resources/Temas/"+m_tema+".oca";
        // Abre el archivo de preguntas y carga las preguntas necesarias

        QFile preg(path);
        if (!preg.exists()){
            //QMessageBox::warning(this,"Error Fatal","No se encuentra el tema");
            return;
        }

        //Se asegura de que la pila este vacía antes de ser llenada
        preguntas.clear();
        //Cuento el número de preguntas
        if(preg.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&preg);
            QString all= in.readAll();
            QStringList linea = all.split("\n");
            int total = all.count("\n");
            // Se llena la pila
            switch (m_level){
            case 0:
                if (total >15){
                    for (int j = 0;j<3;j++){
                        for (int i=0;i<15;i++)
                        {
                            preguntas.append(linea[i]);
                        }
                    }
                }else {
                    int ap=15-total;
                    ap=45/ap;
                    ap=ap+1;
                    if(((ap*total)-11)>=0){
                        for (int j = 0;j<ap;j++){
                            for (int i=0;i<total;i++)
                            {
                                preguntas.append(linea[i]);
                            }
                        }
                    }

                }
                break;
            case 1:
                if (total >15){
                    for (int j = 0;j<3;j++){
                        for (int i=0;i<30;i++)
                        {
                            preguntas.append(linea[i]);
                        }
                    }
                }else {
                    int ap=15-total;
                    ap=45/ap;
                    ap=ap+1;
                    if(((ap*total)-11)>=0){
                        for (int j = 0;j<ap;j++){
                            for (int i=0;i<total;i++)
                            {
                                preguntas.append(linea[i]);
                            }
                        }
                    }
                }
                break;
            case 2:
                if (total >15){
                    for (int j = 0;j<3;j++){
                        for (int i=0;i<45;i++)
                        {
                            preguntas.append(linea[i]);
                        }
                    }
                }else {
                    int ap=15-total;
                    ap=45/ap;
                    ap=ap+1;
                    if(((ap*total)-11)>=0){
                        for (int j = 0;j<ap;j++){
                            for (int i=0;i<total;i++)
                            {
                                preguntas.append(linea[i]);
                            }
                        }
                    }

                }
                break;
            }

        }

    }

    bool Juego_OCA::casilleroSpe(int avan, int jug)
    {
        int a=0;
        int b=0;
        bool lo = false;
        bool tu3 = false;
        bool res= false;
        QVector<int> ocas = {5,9,14,18,23,27,32,36,41,45,50,54,59,63};
        QVector<int> puente={6,12};
        QVector<int> dados={26,56}; //Se suma 9 a lo sacado
        switch (jug){
        case 1:
            b=p1->posicion();
            a=avan + p1->posicion();
            break;
        case 2:
            b=p2->posicion();
            a=avan + p2->posicion();
            break;
        case 3:
            b=p3->posicion();
            a=avan + p3->posicion();
            break;
        case 4:
            b=p4->posicion();
            a=avan + p4->posicion();
            break;
        }

        if(ocas.contains(a)){
            res=true;
            int indice;
            for(int i=0;i<ocas.length();i++){
                if(ocas[i] == a)
                    indice=i;
            }
            if (ocas[indice]==63)
                a=ocas[indice];
            else
                a=ocas[indice+1];
            jug_n=jug;
        }else if(puente.contains(a)){
            res=true;
            if (a==6){
                disactivatedAv(a,jug);
                a=12;
                activatedAv(a,jug);
            }else{
                disactivatedAv(a,jug);
                a=6;
                activatedAv(a,jug);
            }
        }else if(dados.contains(a)){ //Si cae en dados
            res=true;
            a=9+a;
        }else if(a==20){ //Posada
            res=true;
            lo=true;
            a=20;
        }else if(a==42){ //Laberinto
            res=true;
            a=30;
        }else if(a==58){ //Calavera
            res=true;
            a=0;
        }else if(a==52 || a==31){ //Pozo o cárcel
            res=true;
            lo=true;
            tu3=true;
        }else{
            return false;
        }

        disactivatedAv(b,jug);
        QString str;
        switch (jug){
        case 1:
            str = "El jugador " + p1->name() + " ha sido el GANADOR";
            if (a==63){
                QMessageBox::information(this,"Ganador",str);
                gana=1;
            }
            p1->setPosicion(a);
            p1->setLost(lo);
            p1->setM_3t(tu3);

            break;
        case 2:
            str = "El jugador " + p2->name() + " ha sido el GANADOR";
            if (a==63){
                QMessageBox::information(this,"Ganador",str);
                gana=2;
            }
            p2->setPosicion(a);
            p2->setLost(lo);
            p2->setM_3t(tu3);
            break;
        case 3:
            str = "El jugador " + p3->name() + " ha sido el GANADOR";
            if (a==63){
                QMessageBox::information(this,"Ganador",str);
                gana=3;
            }
            p3->setPosicion(a);
            p3->setLost(lo);
            p3->setM_3t(tu3);
            break;
        case 4:
            str = "El jugador " + p4->name() + " ha sido el GANADOR";
            if (a==63){
                QMessageBox::information(this,"Ganador",str);
                gana=4;
            }
            p4->setPosicion(a);
            p4->setLost(lo);
            p4->setM_3t(tu3);
            break;
        }
        activatedAv(a,jug);
        setCasilleros(jug);
        str=gnj;
        return res;

    }

    void Juego_OCA::setJugador(int jug)
    {
        switch (jug){
        case 1:
            ui->ltxJugador->setText(p1->name());
            break;
        case 2:
            ui->ltxJugador->setText(p2->name());
            break;
        case 3:
            ui->ltxJugador->setText(p3->name());
            break;
        case 4:
            ui->ltxJugador->setText(p4->name());
            break;
        }
    }

    void Juego_OCA::setCasilleros(int jug)
    {
        QString str;
        switch (jug){
        case 1:
            str.setNum(p1->posicion());
            break;
        case 2:
            str.setNum(p2->posicion());
            break;
        case 3:
            str.setNum(p3->posicion());
            break;
        case 4:
            str.setNum(p4->posicion());
            break;
        }
        qDebug() << "La posición es:" <<str;
        ui->ltxCasillero->setText(str);
    }

    // Agregar la definición de setTimer en el archivo de implementación (juego_oca.cpp)
    void Juego_OCA::setTimer(int seg)
    {
        // Deshabilitar el botón de lanzar dado mientras se realiza el retraso
        ui->btnDado->setEnabled(false);

        // Crear una instancia de QTimer
        QTimer* timer = new QTimer(this);

        // Conectar el evento timeout del QTimer con una función lambda que manejará el movimiento de las fichas
        connect(timer, &QTimer::timeout, this, [this]() {
            // Realizar el movimiento de las fichas aquí (llamar a la función moveSpace)

            // Habilitar nuevamente el botón de lanzar dado
            ui->btnDado->setEnabled(true);
        });

        // Establecer el intervalo del timer en "seg" segundos (convertidos a milisegundos)
        timer->setInterval(seg * 1000);

        // Iniciar el timer
        timer->start();

        /*
     * // Llamar a setTimer para crear una espera de 0.35 segundos
        setTimer(0.35);
        llamarlo cuando se quiera crear el retraso en segundos
*/
    }

    void Juego_OCA::setDado(int val)
    {
        switch (val) {
        case 1:
            ui->ltxNotifi->setStyleSheet("border-image: url(:/Resources/tablero partes/dado_1.png);");
            break;
        case 2:
            ui->ltxNotifi->setStyleSheet("border-image: url(:/Resources/tablero partes/dado_2.png);");
            break;
        case 3:
            ui->ltxNotifi->setStyleSheet("border-image: url(:/Resources/tablero partes/dado_3.png);");
            break;
        case 4:
            ui->ltxNotifi->setStyleSheet("border-image: url(:/Resources/tablero partes/dado_4.png);");
            break;
        case 5:
            ui->ltxNotifi->setStyleSheet("border-image: url(:/Resources/tablero partes/dado_5.png);");
            break;
        case 6:
            ui->ltxNotifi->setStyleSheet("border-image: url(:/Resources/tablero partes/dado_6.png);");
            break;
        }
    }

