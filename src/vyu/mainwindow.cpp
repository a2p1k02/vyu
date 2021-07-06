#include <iostream>
#include <QFileDialog>
#include <QApplication>
#include <QScrollBar>
#include <QScrollArea>
#include <QMessageBox>
#include <QResizeEvent>
#include <QWidget>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->imageViewer->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->imageViewer->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::getFile(QString file) {
    if (file != "") {
        showImage(file);
        return true;
    }else {
        return false;
    }
}

void MainWindow::zoomIn() {
    zoomImage(1.15);
    std::cout << "Zoom In" << std::endl; //Debug function
}

void MainWindow::zoomOut() {
    zoomImage(0.87);
    std::cout << "Zoom Out" << std::endl; //Debug function
}

QString MainWindow::getFilePath() {
    return QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"), "C:/", QFileDialog::tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
}

void MainWindow::controlScrollBar(QScrollBar* scrollBar, double factor) {
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void MainWindow::showImage(QString filePath) {
    img = new QPixmap(filePath);
    ui->imageViewer->setPixmap(img->scaled(ui->imageViewer->width(), ui->imageViewer->height(), Qt::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
}

void MainWindow::zoomImage(double factor) {
    scaleFactor *= factor;
    ui->imageViewer->setPixmap(img->scaled(ui->imageViewer->width() * scaleFactor, ui->imageViewer->height() * scaleFactor, Qt::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
    controlScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
    controlScrollBar(ui->scrollArea->verticalScrollBar(), factor);
}

void MainWindow::zoomReset() {
    ui->imageViewer->setPixmap(img->scaled(ui->imageViewer->width(), ui->imageViewer->height(), Qt::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
    scaleFactor = 1.0;
}

void MainWindow::on_actionOpen_triggered() {
    showImage(getFilePath());
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

void MainWindow::on_actionZoom_Reset_triggered() {
    zoomReset();
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About vyu"), tr("<p><center>Vyu is Open Source lightweight image viewer was made with GPL V3 License by a2p1k02</center></p><br><a link href='https://github.com/a2p1k02/vyu'><center>Source Code</center></a>"));
}

