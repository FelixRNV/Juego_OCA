#ifndef JUGADORES_H
#define JUGADORES_H

#include <QString>
class Jugadores
{
private:
    QString m_name;
    int m_posicion;
    int m_avatar;
    int m_puntaje;
    bool m_lost;
    bool m_3t;
public:
    Jugadores();
    Jugadores(const QString &name, int posicion, int avatar);
    const QString &name() const;
    int posicion() const;
    int avatar() const;
    int Puntaje() const;
    void setPuntaje(int newPuntaje);
    void setJuga(QString name, int pos, int av);
    bool lost() const;
    void setLost(bool newLost);
    void setPosicion(int newPosicion);
    bool getM_3t() const;
    void setM_3t(bool newM_3t);
};

#endif // JUGADORES_H
