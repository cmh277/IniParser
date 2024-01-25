#include <QCoreApplication>
#include "TestIni.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestIni tIni;
    tIni.TestReadIni();


    return a.exec();
}
