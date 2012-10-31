#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QThread>   // for Worker thread.
#include "worker.h"  // for Worker object.
#include <QTimer>    // for QTimer::singleShot()

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;

    QThread* workerThread; // another thread for "task". Initialized when setupWork(), started when startWork().
    Worker* task;          // does heavy work on another thread. Initialized when setupWork().

    void setupWork(void);

private slots:
    void startWork(void);
};

#endif // WIDGET_H
