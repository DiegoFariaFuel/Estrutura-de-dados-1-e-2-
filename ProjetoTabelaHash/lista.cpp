#include "lista.h"

Lista::Lista():
    inicio(0),
    fim(0)
{
    inicio = fim = nullptr;
}

bool Lista::estaVazia() const
{
    return (fim == 0);
}

bool Lista::insere(Aluno *valor)
{
    if (valor == 0)
        return false;
    No* x = No::montaNo(valor);
    if (estaVazia()) {
        inicio = fim = x;
        return true;
    }
    fim->setProximo(x);
    fim = x;
    return true;
}

Aluno *Lista::retira(Aluno *valor)
{
    if(valor == nullptr || estaVazia())
        return nullptr;
    No *p, *a;
    a = p = inicio;
    for(; p !=0 && p->getDado()->getNome()!=valor->getNome(); a = p, p = p->getProximo());
    if(p == nullptr)
        return nullptr;
    a->setProximo(p->getProximo());
    p->setProximo(nullptr);
    Aluno* x = No::desmonstaNo(p);
    return x;
}

Aluno *Lista::consulta(Aluno *aux)
{
    No *obj = inicio;
    while (obj != nullptr)
    {
        if ((aux->getNome() == obj->getDado()->getNome()) && (aux->getMae() == obj->getDado()->getMae()))
            break;
        else
            obj = obj->getProximo();
    }
    if (obj == nullptr)
        return nullptr;
    else
        return obj->getDado();
}

QString Lista::getLista() const
{
    if (estaVazia()) throw QString("Lista vazia!");
    QString aux = " ";
    No *p = fim;
    while (p != nullptr)
    {
        aux = aux + p->getDado()->getAluno();
        aux = aux + "\n";
    }
    return aux;
}
