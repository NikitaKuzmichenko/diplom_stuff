#include "test1.h"

test1::test1(QObject *parent) : QObject(parent)
{

}

void test1::emitSignal(int i){
    emit customSignal(i);
}
