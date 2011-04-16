#ifndef PARTICLE_H
#define PARTICLE_H

#include <QtDeclarative/QDeclarativeItem>
#include <QPoint>
#include <QVector2D>

class Particle : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Particle)
    Q_PROPERTY(QVector2D position READ getPosition NOTIFY positionChanged)
    Q_PROPERTY(QVector2D velocity READ getVelocity NOTIFY velocityChanged)

public:
    Particle(QVector2D position, QVector2D velocity, QDeclarativeItem *parent = 0);
    ~Particle();

    /**
     * Paint the particle.
     * @overload QDeclarativeItem::paint().
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

    /**
     * Get the particle position.
     * @return the position of the particle.
     */
    QVector2D getPosition() const;

    /**
     * Get the velocity of the particle.
     * @return the velocity of the particle.
     */
    QVector2D getVelocity() const;

    /**
     * Cause particle to move according to the amount of time that passed.
     * @param time_elapsed number of seconds since last move.
     */
    void move(qreal time_elapsed);

signals:
    void positionChanged();
    void velocityChanged();

private:
    QVector2D m_position;
    QVector2D m_velocity;
};

QML_DECLARE_TYPE(Particle)

#endif // PARTICLE_H

