#include <QApplication>
#include "paddle.h"
//#include "ball.h"
#include <QGraphicsScene>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    //QApplication help(argc, argv);
    QApplication pong(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    Paddle * ppaddle = new Paddle();
    ppaddle->setRect(0,0,10,100);

    scene->addItem(ppaddle);

    ppaddle->setFlag(QGraphicsItem::ItemIsFocusable);
    ppaddle->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);

    scene->setSceneRect(0,0,800,600);

    /* sets paddle to middle left of scene */
    ppaddle->setPos(0,view->height()/2 - ppaddle->rect().height()/2 );

    return pong.exec();
}
