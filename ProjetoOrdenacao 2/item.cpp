#include "item.h"

namespace ED2 {
item::item()
{
}

item::item(long long ch, QString n)
{
    chave = ch;
    nome = n;
}

QString item::getItem() const
{
    QString aux = QString::number(chave);
    aux = aux + nome + "\n";
    return aux;
}

int item::getChave() const
{
    return chave;
}

void item::setChave(long long chave)
{
    this->chave = chave;
}

QString item::getNome() const
{
    return nome;
}

void item::setNome(QString nome)
{
    this->nome = nome;
}
}
