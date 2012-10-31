#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setupWork();
//    startWork(); // or when Button clicked.
    QTimer::singleShot(3000, this, SLOT(startWork()));
}

Widget::~Widget()
{
    delete ui;

    // don't have to delete workerThread and task.
    // Qt Object system automatically delete these objects when safely deleting them.
}

void Widget::setupWork()
{
    workerThread = new QThread();
    task = new Worker();

    task->moveToThread(workerThread);

    connect(workerThread, SIGNAL(started()), task, SLOT(doWork()));
}

void Widget::startWork()
{
    workerThread->start();
}
