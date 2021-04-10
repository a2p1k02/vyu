#include "mainwindow.h"
#include "./ui_mainwindow.h"

QString MainWindow::getFilePath()
{
    QString fileName = QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"), "C:/", QFileDialog::tr("Image Files (*.png *.jpg *.bmp)"));
    return fileName;
}

void MainWindow::showImage()
{
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(QPixmap(getFilePath()));
    ui->imageView->setScene(scene);
    //ui->imageView->scale(0.20, 0.20);
    ui->imageView->show();
}

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
