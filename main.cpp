#include "unittestdata.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UnitTestData w;
    w.show();

    return a.exec();
}
