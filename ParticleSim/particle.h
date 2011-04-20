#ifndef PARTICLE_H
#define PARTICLE_H

#include <QDeclarativeItem>
#include <QColor>

class Particle : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(qreal xvel READ xvel WRITE setXvel NOTIFY xvelChanged)
    Q_PROPERTY(qreal yvel READ yvel WRITE setYvel NOTIFY yvelChanged)
    Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
public:
    explicit Particle(QDeclarativeItem *parent = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void move(qreal time_elapsed);

    // getters
    qreal xvel() const { return m_xvel; }
    qreal yvel() const { return m_yvel; }
    qreal radius() const { return m_radius; }
    const QColor& color() const { return m_color; }

    // setters
    void setXvel(qreal xvel) {
        if (!qFuzzyCompare(xvel, m_xvel)) {
            m_xvel = xvel;
            emit xvelChanged();
        }
    }
    void setYvel(qreal yvel) {
        if (!qFuzzyCompare(yvel, m_yvel)) {
            m_yvel = yvel;
            emit yvelChanged();
        }
    }
    void setRadius(qreal radius) {
        if (!qFuzzyCompare(radius, m_radius)) {
            m_radius = radius;
            emit radiusChanged();
        }
    }
    void setColor(QColor color) {
        if (m_color != color) {
            m_color = color;
            emit colorChanged();
        }
    }

signals:
    void xvelChanged();
    void yvelChanged();
    void radiusChanged();
    void colorChanged();

private:
    qreal m_xvel;
    qreal m_yvel;
    qreal m_radius;
    QColor m_color;
};

QML_DECLARE_TYPE(Particle)

#endif // PARTICLE_H
