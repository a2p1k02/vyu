#include "vyu/mainwindow.h"
#include <Windows.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("FIX THIS"));
    MainWindow w;
    w.show();
    FreeConsole();
    return a.exec();
}
