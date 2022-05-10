#include <QCoreApplication>
#include<complex>
#include <cmath>

#include<iostream>
using namespace std;

class complexos{
private:
    int real,imaginario;

public:
    complexos(int real, int imaginario){
        this->real =real;
        this->imaginario = imaginario;
    }

    complexos operator+(complexos  c){
        return complexos(this->real + c.real,this->imaginario + c.imaginario);
    }
    complexos operator-(complexos  c){
        return complexos(this->real - c.real,this->imaginario - c.imaginario);
    }
    complexos operator*(complexos  c){
       return complexos (this->real * c.real - this->imaginario * c.imaginario,
                         this->real * c.imaginario + this->imaginario * c.real);
        }
    complexos operator/(complexos c){
        return complexos ((this->real * c.real + this->imaginario * c.imaginario)/((pow(c.real,2)+pow(c.imaginario,2))),
                          (this->imaginario * c.real - this->real*c.imaginario)/(pow(c.real,2)+pow(c.imaginario,2)));
    }

    string mostra(){
        string result;
        if(imaginario < 0){result = std::to_string(this->real)+std::to_string(this->imaginario);}
        else
             result = std::to_string(this->real)+'+'+std::to_string(this->imaginario);
        return result;
    }
};

int main(){
    int real1,imag1,real2,imag2,opcao;
    setlocale(LC_ALL,"");
    cout<<"Digite o primeiro numero Complexo: "<<endl;
    cout<<"Digite o primeiro numero real: ";
    cin>>real1;
    cout<<"Digite o primeiro numero imaginario: ";
    cin>>imag1;
    complexos c1(real1,imag1);
    cout<<endl;
    cout<<"Digite o segundo numero Complexo: "<<endl;
    cout<<"Digite o segundo numero real: ";
    cin>>real2;
    cout<<"Digite o segundo numero imaginario: ";
    cin>>imag2;
    complexos c2(real2,imag2);

   do{
       cout<<endl;
       cout<<"1.Soma."<<endl;
       cout<<"2.Subtracao."<<endl;
       cout<<"3.Multipicacao."<<endl;
       cout<<"4.Divisao."<<endl;
       cout<<"5.Sair."<<endl;
       cout<<"\nDigite a opcao: ";
       cin>>opcao;
       while(opcao < 0 || opcao > 5){cout<<"Numero Invalido. Digite um opcao de 1 a 5: "; cin>>opcao;}
       switch(opcao) {
       case 1:  {cout<<endl;
           complexos soma = c1.operator+(c2);        
           if(imag1 > 0&&imag2 > 0) { cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "+"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 > 0) { cout<<"("<<real1<<imag1<<"i"<<")"<<  "+"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 > 0&&imag2 <0) {cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "+"  <<"("<<real2<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 <0) {cout<<"("<<real1<<imag1<<"i"<<")"<<  "+"  <<"("<<real2<<imag2<<"i"<<") = ";}
           cout<<"Soma: "<<"("<<soma.mostra()<<"i"<<")"<<endl;break;}

       case 2: {cout<<endl;
           complexos subtracao = c1.operator-(c2);
           if(imag1 > 0&&imag2 > 0) { cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "-"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 > 0) { cout<<"("<<real1<<imag1<<"i"<<")"<<  "-"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 > 0&&imag2 <0) {cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "-"  <<"("<<real2<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 <0) {cout<<"("<<real1<<imag1<<"i"<<")"<<  "-"  <<"("<<real2<<imag2<<"i"<<") = ";}
           cout<<"Subtaracao: "<<"("<<subtracao.mostra()<<"i"<<")"<<endl;break;}

       case 3:  {cout<<endl;
           complexos multiplicacao = c1.operator*(c2);
           if(imag1 > 0&&imag2 > 0) { cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "*"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 > 0) { cout<<"("<<real1<<imag1<<"i"<<")"<<  "*"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 > 0&&imag2 <0) {cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "*"  <<"("<<real2<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 <0) {cout<<"("<<real1<<imag1<<"i"<<")"<<  "*"  <<"("<<real2<<imag2<<"i"<<") = ";}
           cout<<"Multipicacao: "<<"("<<multiplicacao.mostra()<<"i"<<")"<<endl;break;}

       case 4:  {cout<<endl;
           complexos divisao = c1.operator/(c2);
           if(imag1 > 0&&imag2 > 0) { cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "/"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 > 0) { cout<<"("<<real1<<imag1<<"i"<<")"<<  "/"  <<"("<<real2<<"+"<<imag2<<"i"<<") = ";}
           if(imag1 > 0&&imag2 <0) {cout<<"("<<real1<<"+"<<imag1<<"i"<<")"<<  "/"  <<"("<<real2<<imag2<<"i"<<") = ";}
           if(imag1 < 0&&imag2 <0) {cout<<"("<<real1<<imag1<<"i"<<")"<<  "/"  <<"("<<real2<<imag2<<"i"<<") = ";}
           cout<<"Divisao: "<<"("<<divisao.mostra()<<"i"<<")"<<endl;break;}

       case 5:  break;
       }
   }while(opcao != 5);
}
