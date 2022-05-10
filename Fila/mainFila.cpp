# include<iostream>
#include"fila.h"

using namespace std;

int main()
{
    fila fila1;
    int op;
    int item;

    cout<<"FILA";
    do
    {
    cout<<"OPCAO FINALIZA: 0 "<<endl;
    cout<<"OPCAO INSERIR: 1 "<<endl;    
    cout<<"OPCAO REMOVER: 2"<<endl;
    cout<<"OPCAO IMPRIMIR: 3"<<endl;
    cin>>op;

    if (op==1)
    {
        cout<<"DIGITE PARA INSERIR: ";
        cin>>item;
        fila1.pop(item);

    }
    else if (op==2)
    {   item=fila1.push(item);
        cout<<"O elemento foi removido: "<< item <<endl;
    }
    else if (op==3)
    {
    fila1.print();
    }

    } while (op!=0);
    
    return 0;

}