//pilha=stack

typedef int TipoItem;
const int MaxItens = 100;

class pilha
{
private:
    int tamanho;   
    TipoItem* estrutura;

public:
    pilha();//construtora da pilha
    ~pilha();//destrutora pilha
    bool estaCheia();//Verifica se a pilha esta cheia
    bool estaVazia();//Verifica se a pilha está vazia
    void inserir(TipoItem item);//Push
    TipoItem remover();//pop 
    void imprimir();//cout da pilha
    int qualTamanho(); //length  
};
