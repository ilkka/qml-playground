#ifndef TIMEPROVIDER_H
#define TIMEPROVIDER_H

#include <QtDeclarative/QDeclarativeItem>
class QString;

class TimeProvider : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(TimeProvider)
    Q_PROPERTY(QString timeNow READ getTimeNow NOTIFY timeNowChanged)
public:
    TimeProvider(QDeclarativeItem *parent = 0);
    ~TimeProvider();

    virtual QString getTimeNow() const;

signals:
    void timeNowChanged();

private slots:
    void timeChanged();
};

QML_DECLARE_TYPE(TimeProvider)

#endif // TIMEPROVIDER_H

