#include "test2.h"
#include "QDebug"

test2::test2(QObject *parent) : QObject(parent){

}

void test2::customeSot(int i){
    qInfo() << i;
}

void test2::customeSot2(int i)
{
    qInfo() << i+10;
}
