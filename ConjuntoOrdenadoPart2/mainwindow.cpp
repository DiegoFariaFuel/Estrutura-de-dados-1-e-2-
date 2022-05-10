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


void MainWindow::on_pushButtonOK_clicked()
{
    try {
        int tamanho = ui->lineEditTamanhoConjt->text().toInt();
        float conv = 0.000001;
        Vetor = new Conjunto(tamanho);
        auto inicio = std::chrono::high_resolution_clock::now();
        Vetor->preencherVetor();
        QString saida = Vetor->getVetor();
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        ui->textEditConjunto->setText(saida);
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        QString tempo = QString::number(microseconds*conv);
        ui->lineEditTempoConjunto->setText(tempo);
        //=========================================//
        inicio = std::chrono::high_resolution_clock::now();
        Vetor->mergeSort(0, tamanho-1);
        saida = Vetor->getVetor1();
        resultado = std::chrono::high_resolution_clock::now() - inicio;
        ui->lineEditMergeSort->setText(saida);
        microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        tempo = QString::number(microseconds*conv);
        ui->lineEditTempoMerge->setText(tempo);
        //=========================================//
        inicio = std::chrono::high_resolution_clock::now();
        Vetor->heapSort(tamanho);
        saida = Vetor->getVetor2();
        resultado = std::chrono::high_resolution_clock::now() - inicio;
        ui->lineEditHeapSort->setText(saida);
        microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        tempo = QString::number(microseconds*conv);
        ui->lineEditTempoHeap->setText(tempo);
        //=========================================//
        inicio = std::chrono::high_resolution_clock::now();
        Vetor->quickSort(0,tamanho-1);
        saida = Vetor->getVetor3();
        inicio = std::chrono::high_resolution_clock::now();
        ui->lineEditQuickSort->setText(saida);
        microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        tempo = QString::number(microseconds*conv);
        ui->lineEditTempoQuick->setText(tempo);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro do Sistema",erro);
    }
}
