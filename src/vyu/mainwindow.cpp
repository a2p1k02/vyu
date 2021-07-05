#include <iostream>
#include <QFileDialog>
#include <QApplication>
#include <QKeyEvent>
#include <QMessageBox>
#include <QResizeEvent>
#include <QWidget>
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::zoomIn() {

    std::cout << "Zoom In" << std::endl; //Debug function
}

void MainWindow::zoomOut() {

    std::cout << "Zoom Out" << std::endl; //Debug function
}

void MainWindow::keyboardZoom(QKeyEvent* event) {
    if (event->key() == Qt::Key_Control && event->key() == Qt::Key_Plus)
        zoomIn();
    else if (event->key() == Qt::Key_Control && event->key() == Qt::Key_Minus)
        zoomOut();
}

QString MainWindow::getFilePath() {
    return QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"), "C:/", QFileDialog::tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
}

void MainWindow::showImage() {
    img = new QPixmap(getFilePath());
    ui->imageViewer->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->imageViewer->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->imageViewer->setPixmap(img->scaled(ui->imageViewer->width(), ui->imageViewer->height(), Qt::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
}

void MainWindow::createAboutDialog() {
    QMessageBox::about(this, tr("About vyu"), tr("<p>This application was made with GPL V3 License by a2p1k02</p> <p>https://github.com/a2p1k02</p>"));
}

void MainWindow::on_actionOpen_triggered() {
    showImage();
}

void MainWindow::on_actionExit_triggered() {
    qApp->quit();
}

void MainWindow::on_actionZoom_In_triggered() {
    zoomIn();
}

void MainWindow::on_actionZoom_Out_triggered() {
    zoomOut();
}

void MainWindow::on_actionAbout_triggered() {
    createAboutDialog();
}

