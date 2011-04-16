#include "particle.h"

#include <QtDeclarative/qdeclarative.h>
#include <QPainter>

Particle::Particle(QVector2D position, QVector2D velocity, QDeclarativeItem *parent):
    QDeclarativeItem(parent),
    m_position(position),
    m_velocity(velocity)
{
    setFlag(ItemHasNoContents, false);
}

Particle::~Particle()
{
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor::black());
    painter->setBrush(QBrush(QColor::black()));
    painter->drawEllipse(m_position.toPoint(), 10, 10);
}

QVector2D Particle::getPosition() const
{
    return m_position;
}

QVector2D Particle::getVelocity() const
{
    return m_velocity;
}

void Particle::move(qreal time_elapsed)
{
    m_position += m_velocity * time_elapsed;
    emit positionChanged();
}
