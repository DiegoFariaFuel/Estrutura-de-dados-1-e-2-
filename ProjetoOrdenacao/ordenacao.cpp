#include "ordenacao.h"

namespace ED2 {
void Ordenacao::selection(item ** V, long long n)
{
    if (V == nullptr)
        return;
    item * T = nullptr;
    for (int i=0; i<n-1; i++) {
        int imin = i;
        for (int j=i+1; j<n; j++)
            if (V[imin]->getChave() > V[j]->getChave())
                imin = j;
        if (i != imin) {
            T = V[i];
            V[i] = V[imin];
            V[imin] = T;
        }
    }

}

void Ordenacao::insertion(item ** V, long long n)
{
    long int i, j;
    item * T = nullptr;
    if (V != nullptr) {
        for (j=1; j<n; j++) {
            T = V[j];
            i = j - 1;
            while (i >= 0 && V[i]->getChave() > T->getChave()) {
                V[i+1] = V[i];
                i--;
            }
            V[i+1] = T;
        }
    }
}

void Ordenacao::bubblesort(item ** A, long long n)
{
    if (A == nullptr)
        return;
    int Lsup, bolha, j;
    item * Aux = nullptr;
    Lsup = n - 1;
    do {
        bolha = 0;
        for (j=0; j<Lsup; j++)
            if (A[j]->getChave() > A[j+1]->getChave()) {
                Aux = A[j];
                A[j] = A[j+1];
                A[j+1] = Aux;
                bolha = j;
            }
        Lsup = bolha;
    } while (Lsup > 0);
}

void Ordenacao::shellsort(item **, long long)
{

}

void Ordenacao::mergesort(item ** A, int tam)
{
    if (A) {
        item **B = new item*[tam];
        int ini = 0;
        int fim = tam - 1;
        mergesort(A, B, ini, fim);
        delete [] B;
    }
}

void Ordenacao::mergesort(item **A, item **B, int ini, int fim)
{
    if (fim == ini)
        return;
    else {
        int meio = (ini + fim) / 2;
        mergesort(A, B, ini, meio);
        mergesort(A, B, meio + 1, fim);
        intercala(A, B, ini, meio, fim);
        return;
    }
}

void Ordenacao::intercala(item **A, item **B, int ini, int meio, int fim)
{
    int i = ini;
    int j = meio + 1;
    int k = ini;
    while (i < meio + 1 && j < fim + 1) {
        if (A[i]->getChave() < A[j] ->getChave()) {
            B[k] = A[i];
            i++;
            k++;
        }
        else {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i < meio + 1) { // copia restante da 1a. metade.
        B[k] = A[i];
        k++;
        i++;
    }
    while(j < fim + 1) { // copia restante da 2a. metade.
        B[k] = A[j];
        k++;
        j++;
    }
    for(k=ini; k<fim+1; k++) // copia de volta para A
        A[k] = B[k];
}

int Ordenacao::partition(int esq, int dir)
{

}

void Ordenacao::quicksort(item **A, int esq, int dir)
{
    int i;
    if (dir > esq) {
        i = partition(esq, dir);
        quicksort(A, esq, i-1);
        quicksort(A, i+1, dir);
    }
}

void Ordenacao::heapsort(item **, long long)
{

}

}
