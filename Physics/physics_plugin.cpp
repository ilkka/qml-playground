#include "physics_plugin.h"
#include "particle.h"
#include "simulation.h"

#include <QtDeclarative/qdeclarative.h>

void PhysicsPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<Particle>(uri, 1, 0, "Particle");
    qmlRegisterType<Simulation>(uri, 1, 0, "Simulation");
}

Q_EXPORT_PLUGIN2(Physics, PhysicsPlugin)

