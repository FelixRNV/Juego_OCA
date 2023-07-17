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

int Jugadores::Puntaje() const
{
    return m_puntaje;
}

void Jugadores::setPuntaje(int newPuntaje)
{
    m_puntaje = newPuntaje;
}

void Jugadores::setJuga(QString name, int pos, int av)
{
    m_name=name;
    m_posicion=pos;
    m_avatar=av;
}

Jugadores::Jugadores()
{

}

Jugadores::Jugadores(const QString &name, int posicion, int avatar) : m_name(name),
    m_posicion(posicion),
    m_avatar(avatar)
{}
