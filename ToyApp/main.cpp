#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDir pluginPath(app.applicationDirPath());
    pluginPath.mkdir("plugins");
    pluginPath.cd("plugins");
    qDebug() << "Adding plugin path" << pluginPath.path();
    app.addLibraryPath(pluginPath.path());

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/ToyApp/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
