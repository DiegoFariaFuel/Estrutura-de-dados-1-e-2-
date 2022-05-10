#include <iostream>
#include "fila.h"

using namespace std;

fila::fila()
{
    primeiro = 0;
    ultimo = 0;

    estrutura = new tipoitem[max_item];
}

fila::~fila()
{
    delete[] estrutura;
}

bool fila::estavazio()
{
    return (primeiro == ultimo);
}

bool fila::estacheio()
{
    return (ultimo - primeiro == max_item);
}

void fila::push(tipoitem item)
{
    if (estacheio())
    {
        cout << "Lista Cheia" << endl;
        cout << "Nao foi inserido" << endl;
    }
    else
    {
        estrutura[ultimo % max_item] = item;
        ultimo++;
    }
}

tipoitem fila::pop(){
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nenhum elemento foi removido!\n";
            return 0;
        } else{
            primeiro++;            
            return estrutura[(primeiro-1) % max_item];
        }
    }
    
void fila::print()
{
    cout << "Fila [";
    for (int i = primeiro; i < ultimo; i++)
    {
        cout << estrutura[i % max_item] << " ";
    }
    cout << "]";
}