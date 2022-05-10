#ifndef ID_H
#define ID_H
#include <QString>

class Id
{
private:
    long long chave;
    QString nome;
public:
    Id();
    long long getChave() const;
    void setChave(long long newChave);
    const QString &getNome() const;
    void setNome(const QString &newNome);
};

#endif // ID_H
