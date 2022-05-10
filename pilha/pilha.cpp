#include <iostream>
#include "pilha.h"

using namespace std;

pilha::pilha() //construtora da pilha
{
    tamanho = 0;
    estrutura = new TipoItem[MaxItens];
}

pilha::~pilha() //destrutora pilha
{
    delete[] estrutura;
}

bool pilha::estaCheia() //Verifica se a pilha esta cheia
{
    return (tamanho == MaxItens);
}

bool pilha::estaVazia() //Verifica se a pilha está vazia
{
    return (tamanho == 0);
}

void pilha::inserir(TipoItem item) //Push
{
    if (estaCheia())
    {
        cout << "A pilha está cheia" << endl;
        cout << "Não pode colocar" << endl;
    }
    else
    {
        estrutura[tamanho] = item;
        tamanho++;
    }
}

TipoItem pilha::remover() //pop
{
        if (estaVazia()){
            cout << "A pilha esta vazia!\n"; //throw
            cout << "Nao tem elemento para ser removido!\n";
            return 0;
        } else{
            tamanho--;
            return estrutura[tamanho];
        }
    }

void pilha::imprimir() //cout da pilha
{
    cout << "PILHA" << endl;
    cout << " [";
    for (int i = 0; i < tamanho; i++)
    {
        cout << " (" << estrutura[i] << ") ";
    }
    cout<<"]"<<endl;
}

int pilha::qualTamanho() //length
{
    return tamanho;
}