#include "timer.h"
#include <QDebug>

Timer::Timer():
    _interval(500),
    _running(true)
{

}

void Timer::run()
{
    while(_running){
        msleep(_interval);
        qDebug("ss");
        emit ticked();
    }
}
int Timer::interval() const
{
    return _interval;
}

void Timer::setInterval(int interval)
{
    _interval = interval;
}
bool Timer::running() const
{
    return _running;
}

void Timer::setRunning(bool running)
{
    _running = running;
}
