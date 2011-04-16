#ifndef SIMULATION_H
#define SIMULATION_H

#include <QDeclarativeItem>
#include <QTime>

class Simulation : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(qreal width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged)
public:
    explicit Simulation(QDeclarativeItem *parent = 0);

    qreal width() const;
    void setWidth(qreal width);
    qreal height() const;
    void setHeight(qreal height);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* options, QWidget* widget = 0);

signals:
    void widthChanged();
    void heightChanged();

private slots:
    void tick();

private:
    QTime m_time;
    qreal m_width;
    qreal m_height;
};

QML_DECLARE_TYPE(Simulation)

#endif // SIMULATION_H
