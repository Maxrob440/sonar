#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <cmath>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->addEllipse(0-3/2,0-3/2,3,3, QPen(Qt::green));

    scene->addEllipse(0-maxR,0-maxR,maxR*2,maxR*2,QPen(Qt::green));

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::addPoint);

    timer->start(20); // interval in milliseconds
}

void MainWindow::addPoint(){
    int distance = robot.getDistance();
    int x = 0;
    int y = 0;
    double r = 2;

    robot.directionReader.moveDirection(10);

    double newx = x+distance*cos(robot.getDirection());
    double newy = y+distance*sin(robot.getDirection());

    QGraphicsEllipseItem* point = scene->addEllipse(newx - r/2, newy - r/2, r, r,
                                                    QPen(Qt::NoPen), QBrush(Qt::red));
    auto *effect = new QGraphicsOpacityEffect();
    point->setGraphicsEffect(effect);
    auto *fade = new QPropertyAnimation(effect, "opacity");

    fade->setDuration(10000);        // fade over 2 seconds
    fade->setStartValue(1.0);
    fade->setEndValue(0.0);
    fade->setEasingCurve(QEasingCurve::OutQuad);


    QObject::connect(fade, &QPropertyAnimation::finished, [=]() {
        scene->removeItem(point);
        delete point;
    });


    double outsideX = x+maxR*cos(robot.getDirection());
    double outsideY = y+maxR*sin(robot.getDirection());

    if (!headingLine){
        QPen pen(Qt::blue);
        pen.setWidth(2);

        headingLine = scene->addLine(0, 0, outsideX, outsideY, pen);
        headingLine -> setOpacity(0.5);
    }
    else{
        headingLine->setLine(0,0,outsideX,outsideY);
    }

    fade->start(QAbstractAnimation::DeleteWhenStopped);
    // scene->addEllipse(newx - r/2, newy - r/2, r, r);
}


void MainWindow::on_pushButton_2_clicked()
{
    if (timer->isActive()){
        timer->stop();
    }
}

