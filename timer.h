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
    void setInterval(int seconds);

    bool running() const;
    void setRunning(bool running);

signals:
    // TODO Rename signal
    void ticked();

private:
    int _interval;
    bool _running;
};

#endif // TIMER_H
