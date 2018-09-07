#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.setWindowTitle("挖掘机液压心狗");
    w.show();



    return a.exec();
}
