#include "testaordenacao.h"

TestaOrdenacao::TestaOrdenacao()
{
}

Id* TestaOrdenacao::preencherrVetor(int tamanhoDoConjunto)
{
    int tam = tamanhoDoConjunto;
    Id* VET = new Id [tam];
    srand(time(NULL));
    for(int i=0; i<tam; i++)
    {
        VET[i].setChave(rand()%32001);
        VET[i].setNome("Nome "+QString::number(i));
    }
    return VET;
}
