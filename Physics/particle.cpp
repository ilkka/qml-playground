#include "particle.h"

#include <QtDeclarative/qdeclarative.h>
#include <QPainter>

Particle::Particle(QDeclarativeItem *parent):
    QDeclarativeItem(parent),
    m_position(0, 0),
    m_velocity(0, 0)
{
    setFlag(ItemHasNoContents, false);
}

Particle::~Particle()
{
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse(m_position.toPoint(), 10, 10);
}

QVector2D Particle::getPosition() const
{
    return m_position;
}

void Particle::setPosition(const QVector2D &pos)
{
    m_position = pos;
    emit positionChanged();
}

QVector2D Particle::getVelocity() const
{
    return m_velocity;
}

void Particle::setVelocity(const QVector2D &vel)
{
    m_velocity = vel;
    emit velocityChanged();
}

void Particle::move(qreal time_elapsed)
{
    m_position += m_velocity * time_elapsed;
    emit positionChanged();
}
