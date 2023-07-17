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
public:
    Jugadores();
    Jugadores(const QString &name, int posicion, int avatar);
    const QString &name() const;
    int posicion() const;
    int avatar() const;
    int Puntaje() const;
    void setPuntaje(int newPuntaje);
    void setJuga(QString name, int pos, int av);
};

#endif // JUGADORES_H
