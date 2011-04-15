#ifndef TIMEPROVIDER_PLUGIN_H
#define TIMEPROVIDER_PLUGIN_H

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class TimeProviderPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT

public:
    void registerTypes(const char *uri);
};

#endif // TIMEPROVIDER_PLUGIN_H

