#include "worker.h"

Worker::Worker(QObject *parent) :
    QObject(parent)
{
    myTimer = new QTimer(this); // Don't forget to set parent of the timer!
//    myTimer = new QTimer();     // When you do this, parent of the timer is QObject(0x0), which is running on main thread!
    myTimer->setInterval(1000);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(repeatingTask()));
}

void Worker::doWork()
{
    myTimer->start();
}

void Worker::repeatingTask()
{
    qDebug() << "Done." << "Parent of the timer is:" << myTimer->parent();
}
