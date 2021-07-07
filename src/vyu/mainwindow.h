#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool getFile(QString file);
private:
    Ui::MainWindow* ui;
    QString getFilePath();
    QPixmap* img;

    double scaleFactor = 1;
private slots:
    void showImage(QString filePath);
    void zoomImage(double factor);
    void zoomReset();
    void zoomIn();
    void zoomOut();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionAbout_triggered();
    void on_actionZoom_Reset_triggered();
};
#endif // MAINWINDOW_H
