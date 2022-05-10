#ifndef ALUNO_H
#define ALUNO_H
#include<QString>

class Aluno
{
private:
    QString nome;
    QString mae;
    QString matricula;
    QString endereco;
    int ra;

public:
    Aluno();
    QString getNome()const;
    void setNome(QString valor);
    QString getMae()const;
    void setMae(QString valor);
    QString getMatricula()const;
    void setMatricula(QString valor);
    QString getEndereco()const;
    void setEndereco(QString valor);
    QString getAluno()const;

        Aluno(int r,QString n);
        int obterRa();
        QString obterNome();
};

#endif // ALUNO_H
