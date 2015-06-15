#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QThread>

class Timer : public QThread
{
    Q_OBJECT
public:
    Timer();
    virtual ~Timer();
    void run();

    int interval() const;
    void setInterval(int interval);

    bool running() const;
    void setRunning(bool running);

signals:
    void ticked();

private:
    int _interval;
    bool _running;
};

#endif // TIMER_H
