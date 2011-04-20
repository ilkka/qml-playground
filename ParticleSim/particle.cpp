#include "particle.h"

#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QDebug>

Particle::Particle(QDeclarativeItem *parent) :
    QDeclarativeItem(parent),
    m_xvel(0), m_yvel(0), m_radius(10), m_color(QColor::fromRgb(0, 0, 0))
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/)
{
    qDebug() << "Painting particle at" << x() << "," << y();
    QBrush brush(m_color);
    QPen pen(m_color);
    pen.setWidth(1);
    painter->setPen(pen);
    painter->setBrush(brush);
    if (smooth()) {
        painter->setRenderHint(QPainter::Antialiasing, true);
    }
    painter->drawEllipse(x(), y(), m_radius, m_radius);
}

void Particle::move(qreal time_elapsed)
{
    setX(x() + m_xvel * time_elapsed);
    setY(y() + m_yvel * time_elapsed);
    qDebug() << "Moved to " << x() << "," << y();
    update();
}
