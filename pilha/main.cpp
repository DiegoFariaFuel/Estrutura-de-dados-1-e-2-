#include<iostream>
#include"pilha.h"

using namespace std;

int main()
{
    pilha pilha1;
    TipoItem item;
    int opcao;

    cout << "Programa Gerador de Pilha" << endl;

    do
    {
        cout << "Digite 0 para parar o programa" << endl;
        cout << "Digite 1 para inserir um elemento" << endl;
        cout << "Digite 2 para remover um elemento" << endl;
        cout << "Digite 3 para imprimir a pilha" << endl;
        cin >> opcao;
    
    
    if (opcao == 1)
        {
            cout << "Digite elememento a ser inserir" << endl;
            cin >> item;
            pilha1.inserir(item);
        }
        else if (opcao == 2)
        {
            pilha1.remover();
            cout << "Elemento removido " << item << endl;
        }
        else if (opcao == 3)
        {
            pilha1.imprimir();
        }
    
    } 
    while (opcao != 0);


}