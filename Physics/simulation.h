#ifndef SIMULATION_H
#define SIMULATION_H

#include <QDeclarativeItem>

class Simulation : public QDeclarativeItem
{
    Q_OBJECT
public:
    explicit Simulation(QDeclarativeItem *parent = 0);

signals:

public slots:

};

QML_DECLARE_TYPE(Simulation)

#endif // SIMULATION_H
