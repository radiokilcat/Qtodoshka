#include <QGuiApplication>
#include <QtQml/QQmlContext>
#include <QQmlApplicationEngine>

#include "session.h"
#include "taskmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<session>("session", 1, 0, "Session");

    QPointer<TaskModel> taskModel = new TaskModel();

    qmlRegisterType<TaskModel>("Tasks", 1, 0, "TaskModel");

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
