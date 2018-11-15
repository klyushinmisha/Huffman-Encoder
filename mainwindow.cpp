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
    QFile* f = new QFile(path);
    if (!f->open(QIODevice::ReadOnly)){
        return;
    }

    //t = new std::thread(&MainWindow::loadFile, this, f);
    loadFile(f);

    ui->textEdit->setText("Loaded file " + path);
    f->close();
}

void MainWindow::on_pushButton_clicked()
{
    if (bytes.count() == 0){
        QMessageBox::information(this, "Error", "File wasn't loaded");
        return;
    }

    t = new std::thread(&MainWindow::genCodes, this);

    // -*- Do it with mutex

    /*  QFileDialog fd;
     *  fd.setFileMode(fd.AnyFile);
     *  QString path = fd.getSaveFileName(this, "Comparessed file");
     */

    //move to another thread
    /*
     * HuffmanEncoder he(hc);
     */
}

void MainWindow::loadFile(QFile* f)
{
    bytes = f->readAll();
}

void MainWindow::genCodes()
{
    HuffmanTree ht(bytes);
    HuffmanCodes hc(ht.getHead());
    ui->textEdit->append("\nHuffman codes:\n" + hc.toString());
}
