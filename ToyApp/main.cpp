#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeEngine>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QmlApplicationViewer viewer;
    QDir importPath(app.applicationDirPath());
    importPath.cd("imports");
    viewer.engine()->addImportPath(importPath.path());
    qDebug() << "Added import path" << importPath.path();

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/ToyApp/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
