#include <iostream>
#include <stdexcept>

typedef int Dado;

struct Elemento{
    int chave;
    Dado dado;
};

const Elemento INVALIDO = {-1, -1};
const Elemento REMOVIDO = {-2, -2};

bool operator==(const Elemento &elementoA, const Elemento &elementoB){
    return elementoA.chave == elementoB.chave;
}

bool operator!=(const Elemento &elementoA, const Elemento &elementoB){
    return elementoA.chave != elementoB.chave;
}

class HashEA{
    private:
        Elemento *tabela;
        int capacidade, tamanho;
        int funcaoHash(int chave);
        bool verificarOcorrencia(int chave);
    public:
        HashEA(int capacidade = 19);
        ~HashEA();
        void inserir(Elemento e);
        Dado remover(int chave);
        Dado buscar(int chave);
        void imprimir();
};

HashEA::HashEA(int capacidade){
    this->capacidade = capacidade;
    tamanho = 0;
    tabela = new Elemento[capacidade];

    for(int i{0}; i<capacidade; i++)
        tabela[i] = INVALIDO;
}

HashEA::~HashEA(){
    delete[] tabela;
}

int HashEA::funcaoHash(int chave){
    return chave % capacidade;
}

bool HashEA::verificarOcorrencia(int chave){

    int posFinal = funcaoHash(chave);
    int pos = posFinal;

    do{

        if(tabela[pos].chave == chave)
            return true;
        if(tabela[pos] == INVALIDO)
            return false;

        pos = (pos + 1) % capacidade;

    }while(pos != posFinal);
      
    return false;
}

void HashEA::inserir(Elemento e){
    
    if(tamanho == capacidade)
        throw std::runtime_error("Tabela Hash cheia.");
    
    if(e.chave < 0)
        throw std::runtime_error("Valor de chave invalida para insercao.");
    
    if(verificarOcorrencia(e.chave))
        throw std::runtime_error("Chave " + std::to_string(e.chave) + " já existente.");
    
    int pos = funcaoHash(e.chave);

    while(tabela[pos] != INVALIDO && tabela[pos] != REMOVIDO)
        pos = (pos + 1) % capacidade;
    
    tabela[pos] = e;
    tamanho++;

}
Dado HashEA::remover(int chave){

}
Dado HashEA::buscar(int chave){

    int posFinal = funcaoHash(chave);
    int pos = posFinal;

    do{

        if(tabela[pos].chave == chave)
            return tabela[pos].dado;
        if(tabela[pos] == INVALIDO)
            throw std::runtime_error("Chave " + std::to_string(chave) + " inexistente.");

        pos = (pos + 1) % capacidade;

    }while(pos != posFinal);
      
    throw std::runtime_error("Chave " + std::to_string(chave) + " inexistente.");

}
void HashEA::imprimir(){
    for(int i{0}; i<capacidade; i++)
        std::cout << tabela[i].chave << (i == capacidade - 1 ? "" : " - "); 
    std::cout << "\n";
}


int main(){

    return 0;
}