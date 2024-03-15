#include <iostream>
#include <stdexcept>

typedef int Dado;
const int INDEX_NULO{-1};

class FilaArr{
    private:
        int indexInicio, indexFim;
        unsigned int tamanho;
        const unsigned int capacidade;
        Dado *dadoArr;
    public:
        FilaArr(int capacidade = 10);
        ~FilaArr();
        void enfileira(const Dado &d);
        Dado desenfileira();
        Dado espiarInicio();
        void limparTudo();
        unsigned int getTamanho();
        bool vazia();
        bool cheia();
        void info();

};

FilaArr::FilaArr(int capacidade) : capacidade(capacidade) {
    indexInicio = indexFim = INDEX_NULO;
    dadoArr = new Dado[capacidade];
    tamanho = 0;
}

FilaArr::~FilaArr(){
    delete[] dadoArr;    
}

void FilaArr::enfileira(const Dado &d){

    if(cheia())
        throw std::runtime_error("Erro: fila cheia!");
    
    if(vazia())
        indexInicio = 0;
    indexFim = (indexFim + 1) % capacidade;

    dadoArr[indexFim] = d;

    tamanho++;

}

Dado FilaArr::desenfileira(){
    if(vazia())
        throw std::runtime_error("Erro: fila vazia!");

    Dado temp = dadoArr[indexInicio];
    tamanho--;

    if(vazia())
        indexInicio = indexFim = INDEX_NULO;
    else
        indexInicio = (indexInicio + 1) % capacidade;

    return temp;
    
}

Dado FilaArr::espiarInicio(){
    if(vazia())
        throw std::runtime_error("Erro: fila vazia!");

    return dadoArr[indexInicio];
    
}

void FilaArr::limparTudo(){
    indexInicio = indexFim = INDEX_NULO;
    tamanho = 0;
}

unsigned int FilaArr::getTamanho(){
    return tamanho;
}

bool FilaArr::vazia(){
    return !bool(tamanho);
}

bool FilaArr::cheia(){
    return (tamanho == capacidade);
}

void FilaArr::info(){

    std::cout << "tamanho=" << tamanho << " capacidade=" << capacidade << " inicio=" << indexInicio << " fim=" << indexFim << "\n";

    for(int i{0}; i<tamanho; i++)
        std::cout << dadoArr[(indexInicio + i)%capacidade] << " ";

    std::cout << "\n";
}

int main(){

    Dado d;
    char opcao;

    int n;
    std::cin >> n;

    FilaArr fila(n);

    do{

        try{

            std::cin >> opcao;

            switch(opcao){
                case 'e': // enfileirar elemento
                    std::cin >> d;
                    fila.enfileira(d);
                    break;
                case 'd': // desenfileirar elemento
                    d = fila.desenfileira();
                    std::cout << d << "\n";
                    break;
                case 'i':
                    fila.info();
                    break;
                case 't':
                    break;
                default:
                    std::cout << "opcao invalida\n";
            }


        }catch(std::runtime_error &err){
            std::cout << err.what() << "\n";
        }

    }while(opcao != 't');

    return 0;
}