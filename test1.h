#ifndef TEST1_H
#define TEST1_H

#include <QObject>

class test1 : public QObject
{
    Q_OBJECT
public:
    explicit test1(QObject *parent = nullptr);
    void emitSignal(int i);

signals:
    void customSignal(int i);
};

#endif // TEST1_H
