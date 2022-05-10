#include "conjunto.h"

Conjunto::Conjunto(int tamanhoDoConjunto):
    tamanho(0),
    arrayMerge(0),
    arrayHeap(0),
    arrayQuick(0),
    aux(0)
{
    if (tamanhoDoConjunto<=0)
        throw QString("Tamanho nao pode ser <= 0");
    try
    {
        tamanho = tamanhoDoConjunto;
        arrayMerge = new Id[tamanho];
        arrayHeap = new Id[tamanho];
        arrayQuick = new Id[tamanho];

    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Conjunto nao alocado.");
    }
}

void Conjunto::merge(int inicio, int meio, int fim)
{
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while(i <= meio && j <= fim)
    {
        if(arrayMerge[i].getChave() < arrayMerge[j].getChave())
        {
            aux[k] = arrayMerge[i];
            i++;
        }
        else
        {
            aux[k] = arrayMerge[j];
            j++;
        }
        k++;
    }

    while(i <= meio)
    {
        aux[k] = arrayMerge[i];
        i++;
        k++;
    }

    while(j <= fim)
    {
        aux[k] = arrayMerge[j];
        j++;
        k++;
    }

    for(int p = inicio; p <= fim; p++)
        arrayMerge[p] = aux[p];
}



void Conjunto::mergeSort(int inicio, int fim)
{
    if(fim == inicio){
        return;
    }
    else
    {
        int meio = (inicio + fim) / 2;
        mergeSort(inicio, meio);
        mergeSort(meio + 1, fim);
        if(inicio==0 && fim==0)
        {
        merge(inicio, meio, fim);
        }
        return;
    }
}
//=============================================================================//
void Conjunto::heapify(int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arrayHeap[l].getChave() > arrayHeap[largest].getChave())
    {
        largest = l;
    }
    if(r<n && arrayHeap[r].getChave() > arrayHeap[largest].getChave())
    {
        largest = r;
    }
    if(largest!=i)
    {
        Id aux = arrayHeap[i];
        arrayHeap[i] = arrayHeap[largest];
        arrayHeap[largest] = aux;
        heapify(n, largest);
    }
}
void Conjunto::heapSort(int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        Id aux = arrayHeap[0];
        arrayHeap[0] = arrayHeap[i];
        arrayHeap[i] = aux;
        heapify( i, 0);
    }
}
//=============================================================================//
void Conjunto::quickSort(int left, int right)
{
    int x, i, j;
    Id y;
    i = left;
    j = right;
    x = arrayQuick[(left + right) / 2].getChave();

    while(i <= j) {
        while(arrayQuick[i].getChave() < x && i < right)
        {
            i++;
        }
        while(arrayQuick[j].getChave() > x && j > left)
        {
            j--;
        }
        if(i <= j)
        {
            y = arrayQuick[i];
            arrayQuick[i] = arrayQuick[j];
            arrayQuick[j] = y;
            i++;
            j--;
        }
    }

    if(j > left)
    {
        quickSort(left, j);
    }
    if(i < right)
    {
        quickSort( i, right);
    }
}

QString Conjunto::getVetor() const
{
    QString saida;
    for(int i = 0; i < tamanho; i++ )
    {
       saida+= QString::number(array[i].getChave())+"  "+array[i].getNome()+"\n";
    }
    return saida;
}

QString Conjunto::getVetor1()const
{
    QString saida;
    for(int i = 0; i < tamanho; i++ )
    {
       saida+= QString::number(arrayMerge[i].getChave())+"  "+arrayMerge[i].getNome()+"\n";
    }
    return saida;
}

QString Conjunto::getVetor2()const
{
    QString saida;
    for(int i = 0; i < tamanho; i++ )
    {
       saida+= QString::number(arrayHeap[i].getChave())+"  "+arrayHeap[i].getNome()+"\n";
    }
    return saida;
}
QString Conjunto::getVetor3()const
{
    QString saida;
    for(int i = 0; i < tamanho; i++ )
    {
       saida+= QString::number(arrayQuick[i].getChave())+"  "+arrayQuick[i].getNome()+"\n";
    }
    return saida;
}

void Conjunto::preencherVetor()
{
    TestaOrdenacao * aux1 = 0;
    array = aux1->preencherrVetor(tamanho);
    arrayMerge = array;
    arrayHeap = array;
    arrayQuick = array;
}

Conjunto::~Conjunto()
{
    delete[]arrayMerge;
    delete[]arrayHeap;
    delete[]arrayQuick;
}
