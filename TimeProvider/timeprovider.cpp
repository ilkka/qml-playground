#include "timeprovider.h"

#include <QtDeclarative/qdeclarative.h>
#include <QTimer>
#include <QString>
#include <QDateTime>

TimeProvider::TimeProvider(QDeclarativeItem *parent):
        QDeclarativeItem(parent)
{
    QTimer* timer = new QTimer(this);
    timer->setSingleShot(false);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeChanged()));
    timer->start();
}

TimeProvider::~TimeProvider()
{
}

void TimeProvider::timeChanged()
{
    emit timeNowChanged();
}

QString TimeProvider::getTimeNow() const
{
    QDateTime now = QDateTime::currentDateTime();
    return now.toString(Qt::SystemLocaleLongDate);
}
