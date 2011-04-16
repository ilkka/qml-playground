#ifndef PHYSICS_PLUGIN_H
#define PHYSICS_PLUGIN_H

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class PhysicsPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT

public:
    void registerTypes(const char *uri);
};

#endif // PHYSICS_PLUGIN_H

