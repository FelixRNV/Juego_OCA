#include "jugadores.h"

const QString &Jugadores::name() const
{
    return m_name;
}

int Jugadores::posicion() const
{
    return m_posicion;
}

int Jugadores::avatar() const
{
    return m_avatar;
}

Jugadores::Jugadores()
{

}

Jugadores::Jugadores(const QString &name, int posicion, int avatar) : m_name(name),
    m_posicion(posicion),
    m_avatar(avatar)
{}
