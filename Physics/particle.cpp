#include "particle.h"

#include <QtDeclarative/qdeclarative.h>
#include <QPainter>
#include <QDebug>

Particle::Particle(QDeclarativeItem *parent):
    QDeclarativeItem(parent),
     m_velocity(0, 0, 0)
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
    painter->drawEllipse(pos(), 10, 10);
}

QVector3D Particle::getVelocity() const
{
    return m_velocity;
}

void Particle::setVelocity(const QVector3D &vel)
{
    if (m_velocity != vel) {
        m_velocity = vel;
        emit velocityChanged();
    }
}

void Particle::move(qreal time_elapsed)
{
    QVector3D newpos(pos());
    newpos += m_velocity * time_elapsed;
    setPos(newpos.toPointF());
    qDebug() << "New position" << newpos.toPointF();
}
