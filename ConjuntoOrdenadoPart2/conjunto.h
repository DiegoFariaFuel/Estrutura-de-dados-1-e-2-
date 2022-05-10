#ifndef CONJUNTO_H
#define CONJUNTO_H
#include<QString>
#include<testaordenacao.h>

class Conjunto
{
private:
    int tamanho;
    Id* array;
    Id* arrayMerge;
    Id* arrayHeap;
    Id* arrayQuick;
    Id* aux;
public:
    Conjunto(int tamanhoDoConjunto);
    void merge(int inicio, int meio, int fim);
    void mergeSort(int inicio, int fim);
    void heapify(int n, int i);
    void heapSort(int n);
    void quickSort(int left, int right);
    QString getVetor()const;
    QString getVetor1()const;
    QString getVetor2()const;
    QString getVetor3()const;
    void preencherVetor();
    ~Conjunto();
};

#endif // CONJUNTO_H
