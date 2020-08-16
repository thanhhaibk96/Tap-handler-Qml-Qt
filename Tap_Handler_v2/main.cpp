#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlProperty>
#include "buttonbox.h"
#include <QObject>

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView();
    ButtonBox mybtn;
    view->setSource(QUrl::fromLocalFile(":/main.qml"));
    QObject *msg = dynamic_cast<QObject*>(view->rootObject());

    QObject::connect(msg, SIGNAL(qmlSignal()), &mybtn, SLOT(cppSlot()));

    view->show();

    return app.exec();
}
