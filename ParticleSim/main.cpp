#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "particle.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // register custom types
    qmlRegisterType<Particle>("Physics", 1, 0, "ParticleImpl");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/particlesim/ParticleSim.qml"));
    viewer.showExpanded();

    return app.exec();
}
