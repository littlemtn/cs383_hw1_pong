#include "paddle.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "ball.h"

#include <QDebug>
void Paddle::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up)
    {
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space)
    {
        // create a pball
        Ball * pball = new Ball();
        pball->setPos(400,300); //spawns a ball in the middle of the scene
        scene()->addItem(pball);
     }
    else if (event->key() == Qt::Key_F1)
    {

    }
}
