#include <iostream>
#include <utility>
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
        std::pair<Noh*, Noh*> iteradorBuscaValor(const Dado &d);
        Noh* iteradorBuscaPosicao(int pos);
    public:
        Lista();
        ~Lista();
        void limparLista();
        bool vazia();

        Dado removerInicio();
        Dado removerFim();
        Dado removerValor(const Dado& d);
        Dado removerPosicao(int pos);

        void inserirInicio(const Dado &d);
        void inserirFim(const Dado &d);
        void inserirPosicao(const Dado &d, int pos);

        Dado buscaValor(const Dado &d);
        Dado buscaPosicao(int pos);

        void imprimirLista();
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

Noh* Lista::iteradorBuscaPosicao(int pos){ // retorna ponteiro para uma posição específica da lista
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

std::pair<Noh*, Noh*> Lista::iteradorBuscaValor(const Dado &d){ // retorna ponteiro para valor encontrado e sua posição anterior, caso exista

    Noh* aux{inicio}, *anterior{nullptr};

    while(aux != nullptr && aux->dado != d){
        anterior = aux;
        aux = aux->proximo;
    }

    if(aux == nullptr)
        throw std::runtime_error("Erro: valor não encontrado na lista.\n");

    return std::make_pair(anterior, aux);
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
        tamanho++;
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
    Noh *aux{fim};
    if(tamanho == 1){
        inicio = fim = nullptr;
    }else{
        fim = iteradorBuscaPosicao(tamanho - 2);
        fim->proximo = nullptr;
    }

    delete aux;
    tamanho--;

    return temp;
}

Dado Lista::removerPosicao(int pos){

    Dado temp;

    if(pos < 0 || pos >= tamanho)
        throw std::runtime_error("Erro: posição de remocao invalida.\n");

    if(pos == 0)
        temp = removerInicio();
    else if(pos == tamanho - 1)
        temp = removerFim();
    else{

        Noh* anterior{iteradorBuscaPosicao(pos - 1)}, *aux{anterior->proximo};

        temp = aux->dado;
        anterior->proximo = aux->proximo;
        delete aux;
        tamanho--;
    }

    return temp;

}

Dado Lista::removerValor(const Dado& d){
    if(vazia())
        throw std::runtime_error("Erro: Lista Vazia.\n");
    
    std::pair<Noh*, Noh*> buscaValor;

    try{
        buscaValor = iteradorBuscaValor(d);
    }catch(std::runtime_error &e){
        throw std::runtime_error("Erro: valor para remocao invalido.\n");
    }
        
    Noh* anterior{buscaValor.first}, *aux{buscaValor.second};
    Dado temp;

    if(inicio == aux)
        temp = removerInicio();
    else{
    
        temp = aux->dado;
        anterior->proximo = aux->proximo;
        delete aux;
        tamanho--;
    }

    return temp;
}

Dado Lista::buscaValor(const Dado &d){
    return iteradorBuscaValor(d).second->dado;
}
Dado Lista::buscaPosicao(int pos){
    return iteradorBuscaPosicao(pos)->dado;
}

void Lista::imprimirLista(){
    
    Noh *aux{inicio};
    while(aux != nullptr){
        std::cout << aux->dado << "\n";
        aux = aux->proximo;
    }
}

int main(){

    std::cout << "test\n";

    return 0;
}