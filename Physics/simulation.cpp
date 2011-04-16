#include "simulation.h"

#include <QTimer>
#include <QPainter>
#include <QBrush>
#include <QDebug>

#include "particle.h"

Simulation::Simulation(QDeclarativeItem *parent) :
    QDeclarativeItem(parent),
    m_time(), m_width(0), m_height(0)
{
    QTimer* timer = new QTimer(this);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start();
    m_time.start();
    setFlag(ItemHasNoContents, false);
}

void Simulation::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(QRect(pos().toPoint(), QSize(m_width, m_height)));
}

void Simulation::tick()
{
    qreal elapsed_secs = m_time.elapsed() * 1000.0;
    Q_FOREACH(QGraphicsItem* item, childItems()) {
        Particle* p = qobject_cast<Particle*>(item);
        if (p != 0) {
            p->move(elapsed_secs);
            QRectF bounds = p->boundingRect();
            bounds.moveTo(p->pos());
            qDebug() << "Scheduling update for" << bounds;
            update(bounds);
        }
    }
    m_time.restart();
}

void Simulation::setWidth(qreal width)
{
    if (width != m_width) {
        m_width = width;
        emit widthChanged();
    }
}

qreal Simulation::width() const
{
    return m_width;
}

void Simulation::setHeight(qreal height)
{
    if (height != m_height) {
        m_height = height;
        emit heightChanged();
    }
}

qreal Simulation::height() const
{
    return m_height;
}
