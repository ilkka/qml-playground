#ifndef SIMULATION_H
#define SIMULATION_H

#include <QDeclarativeItem>
#include <QTime>

class Simulation : public QDeclarativeItem
{
    Q_OBJECT
public:
    explicit Simulation(QDeclarativeItem *parent = 0);

signals:

private slots:
    void tick();

private:
    QTime m_time;
};

QML_DECLARE_TYPE(Simulation)

#endif // SIMULATION_H
