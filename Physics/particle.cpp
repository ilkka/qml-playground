#include "particle.h"

#include <QtDeclarative/qdeclarative.h>

Particle::Particle(QDeclarativeItem *parent):
        QDeclarativeItem(parent)
{
    setFlag(ItemHasNoContents, false);
}

Particle::~Particle()
{
}

