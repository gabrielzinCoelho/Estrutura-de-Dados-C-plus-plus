#include <iostream>
#include <stdexcept>

typedef int Dado;

class Noh{
    
    //permite o acesso da pilha aos atributos privados do noh
    friend class PilhaEncadeada;

    public:
        Noh(const Dado &d) : dado(d), proximo(nullptr) {}
    
    // noh armazena um dado e um ponteiro para o proximo elemento
    private:
        Dado dado;
        Noh* proximo;
};

class PilhaEncadeada{

    public:
        PilhaEncadeada();
        ~PilhaEncadeada();
        Dado desempilhar();
        void empilhar(const Dado &d);
        Dado espiarTopo();
        bool vazia();
        void limparTudo();
        unsigned int getTamanho();

    // pilha armazena ponteiro para o topo e o tamanho da mesma
    private:
        Noh* topo;
        unsigned int tamanho;
};

PilhaEncadeada::PilhaEncadeada(){
    tamanho = 0;
    topo = nullptr;
}

PilhaEncadeada::~PilhaEncadeada(){
    limparTudo();
}

void PilhaEncadeada::limparTudo(){
    
    // apaga todos nós alocados dinamicamente
    while(!vazia())
        desempilhar();
}

void PilhaEncadeada::empilhar(const Dado &d){

    // cria novo nó, que passa a ser o topo da pilha

    Noh* novo = new Noh(d);
    novo->proximo = topo;
    topo = novo;
    
    tamanho++;
}

Dado PilhaEncadeada::desempilhar(){

    if(vazia())
        throw std::runtime_error("Erro: pilha vazia!");

    // remove o elemento do topo da pilha, e o novo topo passa a ser o proximo

    Noh *aux = topo;
    Dado temp = topo->dado;

    topo = topo->proximo;
    delete aux;

    tamanho--;

    return temp;

}

Dado PilhaEncadeada::espiarTopo(){
    if(vazia())
        throw std::runtime_error("Erro: pilha vazia!");

    return topo->dado;
}

bool PilhaEncadeada::vazia(){
    return !bool(topo);
}

unsigned int PilhaEncadeada::getTamanho(){
    return tamanho;
}

int main(){

    PilhaEncadeada pilha;
    
    std::string txt;
    std::getline(std::cin, txt);

    bool txtValido{true};
    int i{0};

    while(txtValido && i < int(txt.length()) ){

         if(txt[i] == '(')
            pilha.empilhar(i);
        else if(txt[i] == ')'){

            if(pilha.vazia())
                txtValido = false;
            else
                pilha.desempilhar();

        }

        i++;
    }

    if(txtValido){

        if(pilha.vazia())
            std::cout << "correto\n";
        else
            std::cout << pilha.espiarTopo() << "\n";

    }else{

        std::cout << (i - 1) << "\n";;

    }

    return 0;
}