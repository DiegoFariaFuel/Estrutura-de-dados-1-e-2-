#ifndef ORDENACAO_H
#define ORDENACAO_H
#include<item.h>

namespace ED2 {
class Ordenacao
{
public:
    static void selection(item **, long long);
    static void insertion(item **, long long);
    static void bubblesort(item **, long long);
    static void shellsort(item **, long long);

    static void mergesort(item **, int);
    static void mergesort(item **, item**, int, int);
    static void intercala(item **, item **, int, int, int);

    static int partition(int, int);
    static void quicksort(item **, int, int);

    static void heapsort(item **, long long);
};
}

#endif // ORDENACAO_H
