#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

ofstream arquivo("DadosAgenda.txt");//arquivo de saida

class Cliente
{
    private: // atributos
    string cpf;// buscar contato da agenda esse cpf pode não ser alterado somente os outros dados
    string nome;
    string telefone;
    string endereco;
    string email;
    public: // metodos
    void setCpf(string a) { cpf = a;}
    string getCpf() { return cpf;}
    void setNome(string a) { nome = a;}
    string getNome() { return nome;}
    void setTelefone(string a) { telefone = a;}
    string getTelefone() { return telefone;}
    void setEndereco(string a) { endereco = a;}
    string getEndereco() { return endereco;}
    void setEmail(string a) { email = a;}
    string getEmail() { return email;}

};

int main()
{
    		cout<<"Trabalho de TP2 Agenda de Contatos\n\n";
	        cout<<"1-(Adicionar Contato na agenda)\n";
	        cout<<"2-(Listar todos os contatos)\n";
	     	cout<<"3-(Buscar contato pelo CPF)\n";
			cout<<"4-(Ordenar Lista por nome)\n";//
			cout<<"5-(Alterar Contato)\n";
			cout<<"6-(Apagar Contato)\n";   // setCpf(elemento) cin>>elemento, dados[2].setCpf(elemento)
    		cout<<"0-(Finalizar Agenda)\n";
    		cout<<"Opcao=";
    int opcao;
    int tamanho=0;
    Cliente dados[1000];
    int i=0;
    string dados2[1000];
    cin>>opcao;
    while(opcao!=0)
    {
        //opcao = Escolhe();
        if(opcao ==1) // metodo de adicionar
        {
            string cpf;
            string nome;
            string telefone;
            string endereco;
            string email;

            cout<<"Digite o CPF: ";
            cin>>cpf;
            cout<<"Digite o Nome: ";
            cin.ignore();
            getline(cin,nome);
            cout<<"Digite o Telefone: ";
            getline(cin,telefone);
            cout<<"Digite o Endereco: ";
            getline(cin,endereco);
            cout<<"Digite o Email: ";
            cin>>email;

            dados[i].setCpf(cpf);
            dados[i].setNome(nome);
            dados[i].setTelefone(telefone);
            dados[i].setEndereco(endereco);
            dados[i].setEmail(email);

            dados2[i] ="CPF="+ dados[i].getCpf() + "  " +"Nome="+dados[i].getNome() +"  " +"Telefone="+ dados[i].getTelefone() + "  " +"Endereco="+ dados[i].getEndereco() + "  " +"Email="+ dados[i].getEmail();
            arquivo<<dados2[i]<<endl;
            i++;
            tamanho++;
        }

        if(opcao==2)// metodo de mostrar lista
        {
            if(tamanho==0){cout<<"Agenda Esta Vazia!";}
            else
                for(int j=0;j<tamanho;j++)
            {
                cout<<"\nCPF="<<dados[j].getCpf()<<"  ";
                cout<<"Nome="<<dados[j].getNome()<<"  ";
                cout<<"Telefone="<<dados[j].getTelefone()<<"  ";
                cout<<"Endereco="<<dados[j].getEndereco()<<"  ";
                cout<<"Email="<<dados[j].getEmail()<<endl;
            }
        }
        if(opcao==3) // metodo de buscarCpf
        {
            string elemento;
            cout<<"Digite o CPF do contato: ";
            cin>> elemento;
            for(int j=0;j<tamanho;j++)
            {
                if(elemento == dados[j].getCpf())
                {
                    cout<<"Contanto esta na posicao: "<<j<<endl;
                    cout<<"\n CPF="<<dados[j].getCpf()<<"\n Nome="<<dados[j].getNome()<<"\n Telefone="<<dados[j].getTelefone()<<"\n Endereco="<<dados[j].getEndereco()<<"\n Email="<< dados[j].getEmail()<<endl;
                }
            }
        }
        if(opcao==4) // metodo de ordenar selection sort
        {
            for(int i = 0; i < (tamanho-1); i++)
            {
                int m = i;
            for(int j = (i+1); j < tamanho; j++)
            {
            if(dados[j].getNome() < dados[m].getNome())
                m = j;
            }
            if(dados[i].getNome() != dados[m].getNome())
            {
                Cliente aux = dados[i];
                dados[i] = dados[m];
                dados[m] = aux;
            }
            }
            //==============================================//
            // mostrarLista()
            for(int j=0;j<tamanho;j++)
            {
                cout<<"\nCPF="<<dados[j].getCpf()<<"  ";
                cout<<"Nome="<<dados[j].getNome()<<"  ";
                cout<<"Telefone="<<dados[j].getTelefone()<<"  ";
                cout<<"Endereco="<<dados[j].getEndereco()<<"  ";
                cout<<"Email="<<dados[j].getEmail()<<endl;
            }

        }
        if(opcao==5)//nome
        {
            cin.ignore();
            string elemento, novonome, novoendero,novoEmail,novoTelefone;
            cout<<"Digite o CPF que deseja alterar: "; getline(cin,elemento);
            cout<<"Digite o novo Nome: "; getline(cin,novonome);
            cout<<"Digite o Telefone: ";
            getline(cin,novoTelefone);
            cout<<"Digite o Endereco: ";
            getline(cin,novoendero);
            cout<<"Digite o Email: ";
            getline(cin,novoEmail);
            for(int k = 0;k<tamanho;k++)
            {
                if(elemento == dados[k].getCpf())
                {
                    dados[k].setNome(novonome);
                    dados[k].setEndereco(novoendero);
                    dados[k].setTelefone(novoTelefone);
                    dados[k].setEmail(novoEmail);

                }
            }
        }
        if(opcao==0)
        {
            break;
        }
        if(opcao==6){
            cin.ignore();
            string elemento;
            cout<<"Digite o cpf que deseja alterar no contato: "; getline(cin,elemento);
            int aux=0;
            for(int j=0;j<tamanho;j++){
                if(elemento == dados[j].getCpf()){
                    aux = j;
                }
            }
           for (int i = aux; i < tamanho; ++i) {
                  dados[i].setNome(dados[i + 1].getNome());
                  dados[i].setCpf(dados[i + 1].getCpf());
                  dados[i].setEndereco(dados[i + 1].getEndereco());
                  dados[i].setTelefone(dados[i + 1].getTelefone());
                  dados[i].setEmail(dados[i + 1].getEmail());
                 }
           tamanho--;
            }



        	cout<<"Trabalho de TP2 Agenda de Contatos\n\n";
	        cout<<"1-(Adicionar Contato na agenda)\n";
	        cout<<"2-(Listar todos os contatos)\n";
	     	cout<<"3-(Buscar contato pelo CPF)\n";
			cout<<"4-(Ordenar Lista por nome)\n";//
			cout<<"5-(Alterar Contato)\n";
			cout<<"6-(Apagar Contato)\n";   // setCpf(elemento) cin>>elemento, dados[2].setCpf(elemento)
    		cout<<"0-(Finalizar Agenda)\n";
    		cout<<"Opcao=";
        	cin>>opcao;
        }
    }
