#include "aluno.h"

Aluno::Aluno()
   {
       ra = -1;
       nome = " ";
   }

   Aluno::Aluno(int r, QString n)
   {
       ra = r;
       nome = n;
   }

   int Aluno::obterRa()
   {
       return ra;
   }

   QString Aluno::obterNome()
   {
       return nome;
   }
