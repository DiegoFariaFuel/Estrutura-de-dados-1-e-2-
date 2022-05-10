#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <id.h>
#include <conjunto.h>
#include <testaordenacao.h>
#include <chrono>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOK_clicked();

private:
    Ui::MainWindow *ui;
    TestaOrdenacao *VetorTesta;
    Conjunto *Vetor;
};
#endif // MAINWINDOW_H
