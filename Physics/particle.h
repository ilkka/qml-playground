#ifndef PARTICLE_H
#define PARTICLE_H

#include <QtDeclarative/QDeclarativeItem>
#include <QPoint>
#include <QVector2D>

class Particle : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Particle)
    Q_PROPERTY(QVector2D position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QVector2D velocity READ getVelocity WRITE setVelocity NOTIFY velocityChanged)

public:
    explicit Particle(QDeclarativeItem *parent = 0);
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
     * Set particle position.
     * @param pos the position.
     */
    void setPosition(const QVector2D& pos);

    /**
     * Get the velocity of the particle.
     * @return the velocity of the particle.
     */
    QVector2D getVelocity() const;

    /**
     * Set particle velocity.
     * @param vel the velocity.
     */
    void setVelocity(const QVector2D& vel);

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

