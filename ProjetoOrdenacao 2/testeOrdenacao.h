#ifndef TESTEORDENACAO_H
#define TESTEORDENACAO_H
#include<ordenacao.h>
#include<iostream>

namespace ED2 {
class TesteOrdenacao
{
private:
    long long tam;
    item ** vetor;
public:
    TesteOrdenacao();
    ~TesteOrdenacao();
    long long getTam()const;
    bool setTam(long long);
    void preencheVetor()const;
    QString mostraVetor(item **)const;
    item ** copiaVetor()const;
    void menu();
};
}

#endif // TESTEORDENACAO_H
