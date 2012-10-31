#ifndef WORKER_H
#define WORKER_H

#include <QObject>

#include <QTimer> // for Repeating works.
#include <QDebug> // for Output string.

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    
signals:
    
public slots:
    void doWork(void);

private slots:
    void repeatingTask(void);

private:
    QTimer* myTimer; // for Repeating task.
};

#endif // WORKER_H
