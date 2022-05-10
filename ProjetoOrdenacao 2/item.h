#ifndef ITEM_H
#define ITEM_H
#include<QString>

namespace ED2 {
class item
{
private:
    long long chave;
    QString nome;
public:
    item();
    item(long long, QString);
    QString getItem()const;
    int getChave()const;
    void setChave(long long);
    QString getNome()const;
    void setNome(QString);
};
}

#endif // ITEM_H
