#include "timeprovider_plugin.h"
#include "timeprovider.h"

#include <QtDeclarative/qdeclarative.h>

void TimeProviderPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<TimeProvider>(uri, 1, 0, "TimeProvider");
}

Q_EXPORT_PLUGIN2(TimeProvider, TimeProviderPlugin)

