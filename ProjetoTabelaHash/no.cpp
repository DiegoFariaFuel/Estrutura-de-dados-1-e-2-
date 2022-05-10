#include "no.h"

No::No():
    proximo(0),
    dado(0)
{
}

No *No::getProximo() const
{
    return proximo;
}

void No::setProximo(No* valor)
{
    this->proximo = valor;
}

Aluno *No::getDado() const
{
    return dado;
}

void No::setDado(Aluno *valor)
{
    this->dado = valor;
}

No *No::montaNo(Aluno *aux)
{
    if (aux == nullptr)
        return nullptr;
    else {
        No *valor = new No;
        valor->setProximo(nullptr);
        valor->setDado(aux);
        return valor;
    }
}

Aluno *No::desmonstaNo(No *aux)
{
    if (aux == nullptr)
        return nullptr;
    else {
        Aluno *valor = aux->getDado();
        delete aux;
        return valor;
    }
}
