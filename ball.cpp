#include "ball.h"
#include "paddle.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

short move_x = 10;
short move_y = -10;

Ball::Ball()
{
    setRect(0,0,10,10);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBall()));

    timer->start(50);
}

void Ball::moveBall()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    if (colliding_items.size() != 0)
    {
        if (typeid(*(colliding_items[0])) == typeid(Paddle))
        {
            move_x = move_x * -1; //causes ball to bounce off paddle
            setPos(x()+ move_x,y()+ move_y); // moves the ball
            return;
        }
    }
    if ( pos().x() < 0 ) //player missed the ball
    {
        qDebug() << "Game over";
        move_x = move_x * -1; //reset ball to move right
        delete this;
    }

    if (pos().x() > 790)
    {
        /* reverse x direction (right edge) */
        move_x = move_x * -1;
    }

    if ( (pos().y() < 0) || (pos().y() > 590) )
    {
        /* reverse y direction (top and bottom) */
        move_y = move_y * -1 ;
    }

    setPos(x()+ move_x,y()+ move_y);  //moves ball

    return;
}
