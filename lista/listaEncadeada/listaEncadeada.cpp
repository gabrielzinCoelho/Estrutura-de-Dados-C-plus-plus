#include <iostream>

typedef int Dado;

class Noh{
    friend class Lista;
    private:
        Dado dado;
        Noh *proximo;
    public:
        Noh(const Dado &d) : proximo(nullptr), dado(d){}
};

class Lista{
    private:
        Noh *inicio, *fim;
        int tamanho;
    public:
        Lista();
        ~Lista();
};

int main(){

    std::cout << "test\n";

    return 0;
}