#ifndef PARTICLE_H
#define PARTICLE_H

#include <QtDeclarative/QDeclarativeItem>
#include <QPoint>
#include <QVector3D>

class Particle : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Particle)
    Q_PROPERTY(QVector3D velocity READ getVelocity WRITE setVelocity NOTIFY velocityChanged)

public:
    explicit Particle(QDeclarativeItem *parent = 0);
    ~Particle();

    /**
     * Paint the particle.
     * @overload QDeclarativeItem::paint().
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

    /**
     * Get the velocity of the particle.
     * @return the velocity of the particle.
     */
    QVector3D getVelocity() const;

    /**
     * Set particle velocity.
     * @param vel the velocity.
     */
    void setVelocity(const QVector3D& vel);

    /**
     * Cause particle to move according to the amount of time that passed.
     * @param time_elapsed number of seconds since last move.
     */
    void move(qreal time_elapsed);

signals:
    void velocityChanged();

private:
    QVector3D m_velocity;
};

QML_DECLARE_TYPE(Particle)

#endif // PARTICLE_H

