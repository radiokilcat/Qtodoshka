#pragma once

#include <QTime>
#include <QTimer>
#include <QObject>

class session : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString time READ getTime NOTIFY timeChanged)
    Q_PROPERTY(bool running READ getRunning WRITE setRunning NOTIFY runningChanged)

public:
    explicit session(QObject *parent = nullptr);

    QString getTime() const;

    bool getRunning() const;
    void setRunning(bool running);

public slots:
    void updateTime();

signals:
    void timeChanged();
    void runningChanged();

private:
    QTimer* tmr;
    QTime* clock_;
    QString timeString_;

    void startTimer();
    void stopTimer();
    bool running_ = false;
};
