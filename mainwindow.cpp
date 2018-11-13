#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QByteArray bytes = QByteArray::fromRawData("beep boop beer!", 15);
    HuffmanTree ht(bytes);
    QString str;
    HuffmanCode hc(ht.getHead(), str);
    ui->textEdit->setText(str);
}
