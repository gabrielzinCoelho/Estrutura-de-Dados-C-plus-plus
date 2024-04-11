#include <iostream>
#include <stdexcept>

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
        void inserirListaVazia(const Dado &d);
        Noh* iteradorBuscaValor(const Dado &d);
        Noh* iteradorBuscaPosicao(int pos);
    public:
        Lista();
        ~Lista();
        void limparLista();
        bool vazia();
        Dado removerInicio();
        Dado removerFim();
        Dado removerValor();
        Dado removerPosicao();
        void inserirInicio(const Dado &d);
        void inserirFim(const Dado &d);
        void inserirPosicao(const Dado &d, int pos);
        Dado buscaValor();
        Dado buscaPosicao();
};

Lista::Lista() : inicio(nullptr), fim(nullptr), tamanho(0) {}

Lista::~Lista(){
    limparLista();
}

void Lista::limparLista(){
    while(!vazia())
        removerInicio();
}

bool Lista::vazia(){
    return !tamanho;
}

Noh* Lista::iteradorBuscaPosicao(int pos){
    if(pos < 0 || pos > (tamanho - 1))
        throw std::runtime_error("Erro: posição de busca invalida.\n");
    
    int indexBusca{0};
    Noh* aux{inicio};

    while(indexBusca <= pos){
        indexBusca++;
        aux = aux->proximo;
    }

    return aux;
}

Noh* Lista::iteradorBuscaValor(const Dado &d){

    Noh* aux{inicio}, *anterior{nullptr};

    while(aux != nullptr && aux->dado != d){
        anterior = aux;
        aux = aux->proximo;
    }

    return aux == nullptr ? nullptr : anterior;
}

void Lista::inserirListaVazia(const Dado& d){

    Noh *novo = new Noh(d);
    inicio = fim = novo;
    tamanho = 1;

}

void Lista::inserirInicio(const Dado& d){
    if(vazia())
        inserirListaVazia(d);
    
    Noh *novo = new Noh(d);
    novo->proximo = inicio;
    inicio = novo;
    tamanho++;
}

void Lista::inserirFim(const Dado& d){
    if(vazia())
        inserirListaVazia(d);
    
    Noh *novo = new Noh(d);
    fim->proximo = novo;
    fim = novo;
    tamanho++;
}

void Lista::inserirPosicao(const Dado& d, int pos){
    
    if(pos < 0 || pos > tamanho)
        throw std::runtime_error("Erro: posição de insercao invalida.\n");
    
    if(pos == 0)
        inserirInicio(d);
    else if(pos == tamanho)
        inserirFim(d);
    else{
        Noh *novo = new Noh(d);
        Noh* anteriorPos = iteradorBuscaPosicao(pos - 1);
        novo->proximo = anteriorPos->proximo;
        anteriorPos->proximo = novo;
    }
}

Dado Lista::removerInicio(){
    if(vazia())
        throw std::runtime_error("Erro: Lista Vazia.\n");

    Noh* aux = inicio;
    Dado temp{inicio->dado};

    inicio = inicio->proximo;
    delete aux;
    tamanho--;

    if(vazia())
        fim = nullptr;

    return temp;
}

Dado Lista::removerFim(){
    if(vazia())
        throw std::runtime_error("Erro: Lista Vazia.\n");

    Dado temp{fim->dado};
    Noh *aux;
    if(tamanho == 1){
        inicio = aux = nullptr;
    }else{
        aux = iteradorBuscaPosicao(tamanho - 2);
        aux->proximo = nullptr;
    }

    delete fim;
    fim = aux;
    tamanho--;

    return temp;
}

int main(){

    std::cout << "test\n";

    return 0;
}