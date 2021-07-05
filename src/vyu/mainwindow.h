#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
private:
    Ui::MainWindow* ui;
    QString getFilePath();
    QPixmap* img;
private slots:
    void showImage();
    void zoomIn();
    void zoomOut();
    void keyboardZoom(QKeyEvent* event);
    void createAboutDialog();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionAbout_triggered();
};
#endif // MAINWINDOW_H
