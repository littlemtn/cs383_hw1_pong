#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>

class Ball: public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Ball();
public slots:
    void moveBall();
};

#endif // BALL_H
