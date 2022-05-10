#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Inserir_clicked()
{

}


void MainWindow::on_pushButton_Remover_clicked()
{

}


void MainWindow::on_pushButton_Consultar_clicked()
{

}


void MainWindow::on_pushButton_Imprimir_clicked()
{

}

