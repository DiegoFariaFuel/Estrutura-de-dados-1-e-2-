#include "id.h"

Id::Id():
chave(0),
nome("")
{
}

long long Id::getChave() const
{
    return chave;
}

void Id::setChave(long long newChave)
{
    chave = newChave;
}

const QString &Id::getNome() const
{
    return nome;
}

void Id::setNome(const QString &newNome)
{
    nome = newNome;
}
