#ifndef LISTA_H
#define LISTA_H
#include<no.h>

class Lista
{
private:
    No *inicio;
    No *fim;
public:
    Lista();
    bool estaVazia()const;
    bool insere(Aluno *valor);
    Aluno *retira(Aluno *valor);
    Aluno *consulta(Aluno *aux);
    QString getLista()const;
};

#endif // LISTA_H
