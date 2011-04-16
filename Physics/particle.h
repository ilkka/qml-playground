#ifndef PARTICLE_H
#define PARTICLE_H

#include <QtDeclarative/QDeclarativeItem>

class Particle : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Particle)

public:
    Particle(QDeclarativeItem *parent = 0);
    ~Particle();
};

QML_DECLARE_TYPE(Particle)

#endif // PARTICLE_H

