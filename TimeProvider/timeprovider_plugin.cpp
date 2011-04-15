#include "timeprovider_plugin.h"
#include "timeprovider.h"

#include <QtDeclarative/qdeclarative.h>
#include <QDebug>

void TimeProviderPlugin::registerTypes(const char *uri)
{
    qDebug() << "TimeProviderPlugin registering types";
    qmlRegisterType<TimeProvider>(uri, 1, 0, "TimeProvider");
}

Q_EXPORT_PLUGIN2(TimeProvider, TimeProviderPlugin)

