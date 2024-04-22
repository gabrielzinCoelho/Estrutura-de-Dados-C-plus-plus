#include <iostream>
#include <stdexcept>

typedef int Dado;

struct Elemento{
    int chave;
    Dado dado;
};

class Noh{
    friend class Lista;
    friend class Hash;
    private:
        Noh *proximo;
        Elemento elemento;
    public:
        Noh(Elemento e) : elemento(e), proximo(nullptr) {}
};

class Lista{
    private:
        Noh *inicio;
        int tamanho;
        void apagaLista();
        bool vazia();
    public:
        Lista();
        ~Lista();
        int getTamanho();
        void insereLista(Elemento e);
        Dado removeDado(int chave);
        Dado buscaDado(int chave);
        bool verificaOcorrencia(int chave);
};

Lista::Lista() : inicio(nullptr), tamanho(0){}

Lista::~Lista(){
    apagaLista();
}

bool Lista::vazia(){
    return tamanho == 0;
}

void Lista::apagaLista(){
    Noh* aux{inicio}, *temp{nullptr};
    while(aux != nullptr){
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    tamanho = 0;
    inicio = nullptr;
}

int Lista::getTamanho(){
    return tamanho;
}

void Lista::insereLista(Elemento e){ // insercao inicio devido evita necessidade do ponteiro fim
    Noh* novo = new Noh(e);
    
    if(!vazia())
        novo->proximo = inicio;
    inicio = novo;

    tamanho++;
}

Dado Lista::removeDado(int chave){

    Noh* aux{inicio}, *anterior{nullptr};
    Dado temp;

    while(aux != nullptr && aux->elemento.chave != chave){
        anterior = aux;
        aux = aux->proximo;
    }

    if(aux == nullptr)
        throw std::runtime_error("Elemento não encontrado na lista.");
    
    if(aux == inicio) // remocao inicio, inclusive lista com apenas 1 elemento
        inicio = inicio->proximo;
    else if(aux->proximo == nullptr) // remocao fim (necessariamente existe anterior)
        anterior->proximo = nullptr;
    else // remocao meio
        anterior->proximo = aux->proximo;
    
    temp = aux->elemento.dado;
    delete aux;

    return temp;

}
Dado Lista::buscaDado(int chave){

    Noh* aux{inicio};

    while(aux != nullptr && aux->elemento.chave != chave)
        aux = aux->proximo;
    
    if(aux == nullptr)
        throw std::runtime_error("Elemento não encontrado na lista.");
    
    return aux->elemento.dado;
    
}
bool Lista::verificaOcorrencia(int chave){
    
    Noh* aux{inicio};

    while(aux != nullptr && aux->elemento.chave != chave)
        aux = aux->proximo;
    
    return aux != nullptr;
}

class Hash{
    private:
        Lista *tabela;
        int capacidade;
        int funcaoHash(int chave);
    public:
        Hash(int capacidade = 19);
        ~Hash();
        void insere(Elemento e);
        Dado remove(int chave);
        Dado busca(int chave);
};

Hash::Hash(int capacidade){
    this->capacidade = capacidade;
    tabela = new Lista[capacidade]; 
}


Hash::~Hash(){
    delete[] tabela;
}

int Hash::funcaoHash(int chave){
    return chave % capacidade;
}

void Hash::insere(Elemento e){

    Lista* listaPtr = tabela + funcaoHash(e.chave);

    if(listaPtr->verificaOcorrencia(e.chave))
        throw std::runtime_error("Elemento já existente na tabela hash.");

    listaPtr->insereLista(e);
}
Dado Hash::remove(int chave){

    try{
        tabela[funcaoHash(chave)].removeDado(chave);
    }catch(std::runtime_error &e){
        throw std::runtime_error("Elemento não encontrado na tabela hash.");
    }

}
Dado Hash::busca(int chave){
    try{
        return tabela[funcaoHash(chave)].buscaDado(chave);
    }catch(std::runtime_error &e){
        throw std::runtime_error("Elemento não encontrado na tabela hash.");
    }
}

int main(){

    return 0;
}