#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <huffmantree.h>
#include <huffmancodes.h>
#include <QFileDialog>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray bytes;
    HuffmanCodes hc;
};

#endif // MAINWINDOW_H
