#include "testeOrdenacao.h"

namespace ED2 {
TesteOrdenacao::TesteOrdenacao()
{
    tam = 2;
    vetor = nullptr;
}

TesteOrdenacao::~TesteOrdenacao()
{
    item* aux = nullptr;
    if(vetor != nullptr) {
        for(long long i = 0; i < tam; i++) {
            aux = vetor[i];
            vetor[i] = nullptr;
            delete aux;
        }
        delete [] vetor;
    }
}

long long TesteOrdenacao::getTam() const
{
    return tam;
}

bool TesteOrdenacao::setTam(long long aux)
{
    if(aux <= 1) return false;
    tam = aux;
    vetor = new item*[tam];
    for(long long i = 0; i < tam; i++) {
        vetor[i] = nullptr;
    }
    return true;
}

void TesteOrdenacao::preencheVetor() const
{
    int aux = 0;
    srand(17);
    for(int i = 0; i < tam; i++){
        aux = rand();
        aux = (aux+131)%tam+1;
        this->vetor[i] = new item;
        this->vetor[i]->setChave(aux);
    }
}

QString TesteOrdenacao::mostraVetor(item ** aux) const
{
    for(int i = 0; i < tam; i++)
        aux[i]->getItem();
}

item **TesteOrdenacao::copiaVetor() const
{
    if(vetor == nullptr) return nullptr;
    item **copia = new item*[tam];
    for(long long i = 0; i < tam; i++){
        copia[i] = vetor[i];
    }
    return copia;
}

void TesteOrdenacao::menu()
{
    std::cout<<"GABRIEL TEIXEIRA COELHO & DIEGO DA SILVA VELOSO DE FARIA\n\n";
    ED2::TesteOrdenacao *obj;
    int opcao, valor=0;
    std::cout<<"Trabalho - Projeto Ordenacao de Vetores\n";
    std::cout<<"(0) Fim\n";
    std::cout<<"(1) Insertion\n";
    std::cout<<"(2) Selection\n";
    std::cout<<"(3) Bubblesort\n";
    std::cout<<"(4) Shellsort\n";
    std::cout<<"(5) Mergesort\n";
    std::cout<<"(6) Quicksort\n";
    std::cout<<"(7) Heapsort\n";
    std::cout<<"Escolha entre:\n";
    std::cin>>opcao;
    while (opcao != 0) {
        switch (opcao) {
            case 1:
                std::cout<<"Digite o valor de insercao: ";
                std::cin>>valor;
                Ordenacao::insertion(vetor, valor);
                break;
            case 2:
                std::cout<<"Responda: ";
                Ordenacao::selection(vetor, valor);
                break;
            case 3:
                // ??
                break;
            case 4:
                // ??
                break;
            default:
                std::cout<<"Nao tem opcao!\n";
        }
        std::cout<<"Escolha uma opcao: ";
        std::cin>>opcao;
    }
}
}
