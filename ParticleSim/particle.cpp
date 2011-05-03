#include "particle.h"

#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QDebug>

Particle::Particle(QDeclarativeItem *parent) :
    QDeclarativeItem(parent),
    m_xvel(0), m_yvel(0), m_radius(10), m_color(QColor::fromRgb(0, 0, 0)), m_penwidth(1.0)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/)
{
    QBrush brush(m_color);
    QPen pen(m_color);
    pen.setWidth(m_penwidth);
    painter->setPen(pen);
    painter->setBrush(brush);
    if (smooth()) {
        painter->setRenderHint(QPainter::Antialiasing, true);
    }
    painter->drawEllipse(x(), y(), m_radius, m_radius);
}

void Particle::move(qreal time_elapsed)
{
    moveBy(m_xvel * time_elapsed, m_yvel * time_elapsed);
    update();
}

QRectF Particle::boundingRect() const
{
    return QRectF(-m_radius - m_penwidth / 2.0, -m_radius - m_penwidth / 2.0,
                  (2.0 * m_radius) + m_penwidth, (2.0 * m_radius) + m_penwidth);
}
