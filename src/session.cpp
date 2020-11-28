#include "session.h"
#include <iostream>

#include "chrono"

#include "QTime"
#include "QDebug"

session::session(QObject *parent) :
    QObject(parent),
    clock_{new QTime(0,0)},
    timeString_{"0:00"}
{
    tmr = new QTimer(parent);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
}

QString session::getTime() const
{
    return timeString_;
}

void session::updateTime()
{
    *clock_ = clock_->addSecs(1);
    timeString_ = clock_->toString("m:ss");
    timeChanged();
}

void session::startTimer()
{
    tmr->start(1000);
}

void session::stopTimer()
{
    tmr->stop();
}

bool session::getRunning() const
{
    return running_;
}

void session::setRunning(bool running)
{
    if (running_ != running)
    {
        running_ = running;
        emit runningChanged();
        running_ ? startTimer() : stopTimer();
    }
}
