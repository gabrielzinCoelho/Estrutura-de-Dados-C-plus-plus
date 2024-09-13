#include <iostream>
#include <stdexcept>

typedef int DadoInfo;

class Dado{
    private:
        DadoInfo dadoInfo;
    public:
        Dado(){};
        Dado(const DadoInfo &dadoInfo) : dadoInfo(dadoInfo) {}
        int getChave() const {return dadoInfo;}
        bool operator<(const Dado &dado) { return getChave() < dado.getChave();}
        bool operator>(const Dado &dado) { return getChave() > dado.getChave();} 
};

std::ostream& operator<<(std::ostream &output, const Dado &dado){
    return output << dado.getChave();
}

class Noh{
    friend class ABB;
    private:
        Dado dado;
        Noh *esq, *dir;
    public:
        Noh(const Dado &dado) : dado(dado), esq(nullptr), dir(nullptr) {};
};

class ABB{
    private:
        Noh *raiz;
        void auxDestrutor(Noh *nohAtual);
        Noh* auxInsere(Noh *nohAtual, const Dado &dado);
        Noh* auxBusca(Noh *nohAtual, int chaveBusca);
        void imprimeAux(Noh* nohAtual);
        Noh* minimoAux(Noh *nohAtual);
        Noh* maximoAux(Noh *nohAtual);
    public:
        ABB() : raiz(nullptr) {};
        ~ABB();
        void imprime();
        void insere(const Dado &umDado);
        Dado busca(int chaveBusca);
        Dado minimo();
        Dado maximo();
};

ABB::~ABB(){
    auxDestrutor(raiz);
}

void ABB::auxDestrutor(Noh *nohAtual){
    if(nohAtual){
        auxDestrutor(nohAtual->esq);
        auxDestrutor(nohAtual->dir);
        delete nohAtual;
    }
}

void ABB::insere(const Dado &dado){
    raiz = auxInsere(raiz, dado);
}

Noh* ABB::auxInsere(Noh *nohAtual, const Dado &dado){

    if(nohAtual){

        if(nohAtual->dado < dado)
            nohAtual->dir = auxInsere(nohAtual->dir, dado);
        else if(nohAtual->dado > dado)
            nohAtual->esq = auxInsere(nohAtual->esq, dado);
        else
            throw std::runtime_error("A chave deve ser um valor unico.\n");
    
        return nohAtual;
    }else
        return new Noh(dado);
}

Dado ABB::busca(int chaveBusca){
    Noh* nohBusca = auxBusca(raiz, chaveBusca);
    return nohBusca->dado;
}

Noh* ABB::auxBusca(Noh *nohAtual, int chaveBusca){
    if(!nohAtual)
        throw std::runtime_error("Elemento com a chave indicada nao encontrado.\n");
    
    int chaveAtual = nohAtual->dado.getChave(); 

    if(chaveAtual == chaveBusca)
        return nohAtual;
    if(chaveAtual < chaveBusca)
        return auxBusca(nohAtual->dir, chaveBusca);
    return auxBusca(nohAtual->esq, chaveBusca);
}

void ABB::imprime(){
    imprimeAux(raiz);
    std::cout << "\n";
}

void ABB::imprimeAux(Noh *nohAtual){

    if(nohAtual){
        imprimeAux(nohAtual->esq);
        std::cout << nohAtual->dado << " ";
        imprimeAux(nohAtual->dir);
    }
}

Dado ABB::minimo(){
    if(!raiz)
        throw std::runtime_error("Arvore Vazia.\n");
    return minimoAux(raiz)->dado;
}

Noh* ABB::minimoAux(Noh *nohAtual){
    while(nohAtual->esq)
        nohAtual = nohAtual->esq;
    return nohAtual;
}

Dado ABB::maximo(){
    if(!raiz)
        throw std::runtime_error("Arvore Vazia.\n");
    return maximoAux(raiz)->dado;
}

Noh* ABB::maximoAux(Noh *nohAtual){
    while(nohAtual->dir)
        nohAtual = nohAtual->dir;
    return nohAtual;
}

int main(){

    ABB abb;
    char op;
    DadoInfo dadoInfo;
    Dado d;
    int chave;

    do{

        try{

            std::cin >> op;
            switch(op){

                case 'i': // inserir
                    std::cin >> dadoInfo;
                    d = Dado(dadoInfo);
                    abb.insere(d);
                    break;
                case 'b': // buscar
                    std::cin >> chave;
                    d =  abb.busca(chave);
                    std::cout << d << "\n";
                    break;
                case 'm': // imprimir
                    d =  abb.minimo();
                    std::cout << d << "\n";
                    break;
                case 'n': // imprimir
                    d =  abb.maximo();
                    std::cout << d << "\n";
                    break;
                case 'p': // imprimir
                    abb.imprime();
                    break;
                case 'f':
                    break;
                default:
                    std::cout << "Comando Invalido\n";
            }
        }catch(std::runtime_error &e){
            std::cout << e.what() << "\n";
        }

    }while(op != 'f');


    return 0;
}