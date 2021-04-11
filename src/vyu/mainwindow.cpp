#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->openImage, SIGNAL(clicked()), this, SLOT(showImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getFilePath()
{
    QString fileName = QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"), "C:/", QFileDialog::tr("Image Files (*.png *.jpg *.bmp)"));
    return fileName;
}

void MainWindow::showImage()
{
    QPixmap* img = new QPixmap(getFilePath());
    ui->imageViewer->setScaledContents(true);
    ui->imageViewer->setPixmap(img->scaled(800, 600));
}
