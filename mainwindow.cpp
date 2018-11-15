#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <huffmanencoder.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QFileDialog fd;
    QString path = fd.getOpenFileName();
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) return;
    bytes = f.readAll();
    ui->textEdit->setText("Loaded file " + path);
    f.close();
}

void MainWindow::on_pushButton_clicked()
{
    if (bytes.count() == 0){
        QMessageBox::information(this, "Error", "File wasn't loaded");
        return;
    }

    HuffmanTree ht(bytes);
    HuffmanCodes hc(ht.getHead());
    ui->textEdit->append("\nHuffman codes:\n" + hc.toString());

    QFileDialog fd;
    fd.setFileMode(fd.AnyFile);
    QString path = fd.getSaveFileName(this, "Comparessed file");

    HuffmanEncoder he(hc);
}
