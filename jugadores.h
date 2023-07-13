#ifndef JUGADORES_H
#define JUGADORES_H

#include <QString>
class Jugadores
{
private:
    QString m_name;
    int m_posicion;
    int m_avatar;
public:
    Jugadores();
    Jugadores(const QString &name, int posicion, int avatar);
    const QString &name() const;
    int posicion() const;
    int avatar() const;
};

#endif // JUGADORES_H
