#ifndef TEST2_H
#define TEST2_H

#include <QObject>

class test2 : public QObject
{
    Q_OBJECT
public:
    explicit test2(QObject *parent = nullptr);

signals:

public slots:
    void customeSot(int i);
    void customeSot2(int i);
};

#endif // TEST2_H
