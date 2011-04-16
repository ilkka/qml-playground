#include "simulation.h"
#include <QTimer>
#include "particle.h"

Simulation::Simulation(QDeclarativeItem *parent) :
    QDeclarativeItem(parent),
    m_time()
{
    QTimer* timer = new QTimer(this);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    m_time.start();
    setFlag(ItemHasNoContents, false);
}

void Simulation::tick()
{
    qreal elapsed_secs = m_time.elapsed() * 1000.0;
    Q_FOREACH(QGraphicsItem* item, childItems()) {
        Particle* p = qobject_cast<Particle*>(item);
        if (p != 0) {
            p->move(elapsed_secs);
        }
    }
    m_time.restart();
}
