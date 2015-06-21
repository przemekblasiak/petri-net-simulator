#include "timer.h"
#include <QDebug>

Timer::Timer():
    _interval(1000),
    _running(true)
{

}

Timer::~Timer()
{
    _running = false;
}

void Timer::run()
{
    while(_running){
        msleep(_interval);
        emit ticked();
    }
}
int Timer::interval() const
{
    return _interval;
}

void Timer::setInterval(int seconds)
{
    _interval = seconds;
}
bool Timer::running() const
{
    return _running;
}

void Timer::setRunning(bool running)
{
    _running = running;
}
