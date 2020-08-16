#ifndef BUTTONBOX_H
#define BUTTONBOX_H

#include <QObject>
#include <QtDebug>
#include <QQuickItem>
#include <QQuickView>
#include <QtCore>

class ButtonBox: public QObject
{
    Q_OBJECT
public:
    ButtonBox();

public slots:
    void cppSlot();
};

#endif // BUTTONBOX_H
