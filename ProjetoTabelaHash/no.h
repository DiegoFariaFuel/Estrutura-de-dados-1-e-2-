#ifndef NO_H
#define NO_H
#include<aluno.h>

class No
{
private:
    No *proximo;
    Aluno *dado;
public:
    No();
    No* getProximo()const;
    void setProximo(No* valor);
    Aluno *getDado()const;
    void setDado(Aluno* valor);
    static No *montaNo(Aluno* aux);
    static Aluno *desmonstaNo(No* aux);
};

#endif // NO_H
