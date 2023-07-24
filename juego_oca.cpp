#include "juego_oca.h"
#include "ui_juego_oca.h"

Juego_OCA::Juego_OCA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego_OCA)
{
    ui->setupUi(this);
    ui->btnDado->setEnabled(false);

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
        ui->ltxNotifi->setText(tr("Lanza el dado"));
        ui->btnDado->setEnabled(true);
        m_juegan=ne.jueg();
        qDebug() << "Juegan: " << m_juegan;
    }
        // Borro posiciones previas
        ui->widCasi_0->deseableAV(1);
        ui->widCasi_0->deseableAV(2);
        ui->widCasi_0->deseableAV(3);
        ui->widCasi_0->deseableAV(4);

    switch (m_juegan){
    case 0:
        ui->widCasi_0->enableAV(p1->avatar()+1);
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
    QMessageBox::information(this, tr("Dado"), tr("Avanza : ")+ QString::number(dado) +tr(" Casilleros"));

    if(jug>m_juegan+2)
        jug=1;
    setJugador(jug);
    setCasilleros(jug);
    qDebug() << "Jugador: " << jug;
    if (jug==1){
        if (!casilleroSpe(dado,jug)){
            QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
            if  (respons==QMessageBox::Yes){
                if(pregu[1]=="V")
                   p1->setPosicion(dado+p1->posicion());
             } else {
                if(pregu[1]=="F")
                   p1->setPosicion(dado+p1->posicion());
               }
        }
    } else if (jug==2){
        if (!casilleroSpe(dado,jug)){
               QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
            if  (respons==QMessageBox::Yes){
                if(pregu[1]=="V")
                   p2->setPosicion(dado+p2->posicion());
             } else {
                if(pregu[1]=="F")
                   p2->setPosicion(dado+p2->posicion());
               }
        }
    } else if (jug==3){
        if (!casilleroSpe(dado,jug)){
            QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
            if  (respons==QMessageBox::Yes){
                if(pregu[1]=="V")
                   p3->setPosicion(dado+p3->posicion());
             } else {
                if(pregu[1]=="F")
                   p3->setPosicion(dado+p3->posicion());
               }
        }
    } else if (jug==4){
        if (!casilleroSpe(dado,jug)){
            QMessageBox::StandardButton respons = QMessageBox::question(this,tr("Pregunta"),pregu[0]);
            if  (respons==QMessageBox::Yes){
                if(pregu[1]=="V")
                   p4->setPosicion(dado+p4->posicion());
             } else {
                if(pregu[1]=="F")
                   p4->setPosicion(dado+p4->posicion());
               }
        }
    }
    jug++;
    setTimer(2);


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

void Juego_OCA::moveSpace(int avan, int jug)
{
    switch(avan){
    case 1:
        ui->widCasi_1->enableAV(jug);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    }
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
               ap=ap/total;
               ap=ap+1;
               if(((ap*total)-11)>=0){
                   for (int j = 0;j<ap*4;j++){
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
               ap=ap/total;
               ap=ap+1;
               if(((ap*total)-11)>=0){
                   for (int j = 0;j<ap*4;j++){
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
               ap=ap/total;
               ap=ap+1;
               if(((ap*total)-11)>=0){
                   for (int j = 0;j<ap*4;j++){
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
    bool lo = false;
    bool tu3 = false;
    bool res= false;
    QVector<int> ocas = {5,9,14,18,23,27,32,36,41,45,50,54,59,63};
    QVector<int> puente={6,12};
    QVector<int> dados={26,56}; //Se suma 9 a lo sacado
    switch (jug){
    case 1:
        a=avan + p1->posicion();

        break;
    case 2:
        a=avan + p2->posicion();
        break;
    case 3:
        a=avan + p3->posicion();
        break;
    case 4:
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
    }else if(puente.contains(a)){
        res=true;
        if (a==6)
            a=12;
        else
            a=6;
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
    }

    switch (jug){
    case 1:
        p1->setPosicion(a);
        p1->setLost(lo);
        p1->setM_3t(tu3);

        break;
    case 2:
        p2->setPosicion(a);
        p2->setLost(lo);
        p2->setM_3t(tu3);
        break;
    case 3:
        p3->setPosicion(a);
        p3->setLost(lo);
        p3->setM_3t(tu3);
        break;
    case 4:
        p4->setPosicion(a);
        p4->setLost(lo);
        p4->setM_3t(tu3);
        break;
    }
    setCasilleros(jug);
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

