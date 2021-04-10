#include "vyu/mainwindow.h"
#include <Windows.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("D:/cygwin64/home/a2p1k02/Projects/c_cpp/vyu/src/vyu/icon/eye.png"));
    MainWindow w;
    w.show();
    FreeConsole();
    return a.exec();
}
