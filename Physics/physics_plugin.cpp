#include "physics_plugin.h"
#include "particle.h"

#include <QtDeclarative/qdeclarative.h>

void PhysicsPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<Particle>(uri, 1, 0, "Particle");
}

Q_EXPORT_PLUGIN2(Physics, PhysicsPlugin)

