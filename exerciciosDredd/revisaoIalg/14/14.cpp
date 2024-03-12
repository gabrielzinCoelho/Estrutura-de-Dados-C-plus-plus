#include <iostream>
#include <fstream>

struct Data{
    int dia, mes, ano;
};

struct Tarefa{
    char descricao[40];
    Data dataTarefa;
};

bool datasIguais(const Data &dataA,const Data &dataB){
    return (dataA.dia == dataB.dia && dataA.mes == dataB.mes && dataA.ano == dataB.ano);
}

int main(){

    std::string nomeArq{"o-que-tem-para-hoje"};
    std::ifstream arq(nomeArq);

    int numTarefas;
    arq.read((char *) (&numTarefas), sizeof(int));

    Data dataAtual;
    std::cin >> dataAtual.dia >> dataAtual.mes >> dataAtual.ano;

    Tarefa tarefa;

    for(int i{0}; i<numTarefas; i++){
        arq.read((char *) (&tarefa), sizeof(Tarefa));
        if(datasIguais(dataAtual, tarefa.dataTarefa))
            std::cout << tarefa.descricao << "\n";
    }

    return 0;
}