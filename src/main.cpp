#include "vyu/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication vyu(argc, argv);

    QApplication::setApplicationName(QString("vyu"));
    QApplication::setApplicationDisplayName(QString("Image Viewer"));
    QApplication::setApplicationVersion(QString("0.5"));

    QIcon icon;
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(16, 16));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(24, 24));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(32, 32));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(48, 48));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(64, 64));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(96, 96));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(128, 128));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(256, 256));
    icon.addFile(QString(":/app/icon/src/vyu/icon/eye.svg"), QSize(512, 512));
    vyu.setWindowIcon(icon);

#ifdef _WIN32
    #include <Windows.h>
    FreeConsole();
#endif

    MainWindow vyu_window;
    vyu_window.show();
    return vyu.exec();
}
