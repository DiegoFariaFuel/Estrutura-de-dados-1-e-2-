typedef int tipoitem;
const int max_item=100;

class fila
{

private:
    int primeiro,ultimo;
    tipoitem* estrutura;
public:
    fila( );
    ~fila( );
    bool estavazio();
    bool estacheio();
    void push(tipoitem item);
    tipoitem pop();
    void print();
};
