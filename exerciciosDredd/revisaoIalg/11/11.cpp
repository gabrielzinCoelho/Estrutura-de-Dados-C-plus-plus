#include <iostream>
#include <algorithm>
#include <utility>

struct familia{
    std::string sobrenome;
    int idadePai, idadeMae, idadeFilho;
};

class ContadorIdades{
    public:
        int tamanhoArr, capacidadeArr;
        std::pair<int, int> *arr;
        ContadorIdades() : tamanhoArr(0), capacidadeArr(5), arr(new std::pair<int, int>[5]) {}
        ~ContadorIdades(){
            delete[] arr;
        }
        void adicionaIdade(int x){

            int i{0};
            while(i < tamanhoArr && arr[i].first != x)
                i++;
            
            if(i == tamanhoArr){
                redimensionaArr();
                arr[tamanhoArr++] = std::make_pair(x, 1);
            }else{
                arr[i].second++;
            }

        }
    private:
        void redimensionaArr(){
            if(tamanhoArr == capacidadeArr){
                std::pair<int, int> *novoArr = new std::pair<int, int>[capacidadeArr + 5];
                std::copy(arr, arr + tamanhoArr, novoArr);
                delete[] arr;
                arr = novoArr;
                capacidadeArr += 5;
            }
        }
};

void redimensionaArr(int &capacidade, familia* &arr){

    familia *familiaMaior = new familia[capacidade + 3];
    std::copy(arr, arr + capacidade, familiaMaior);
    delete[] arr;
    arr = familiaMaior;

    capacidade += 3;

    std::cout << capacidade << "\n";
}

int main(){

    ContadorIdades contador;

    int numFamilias{0}, capacidadeArr{3};
    familia *familias = new familia[capacidadeArr];

    std::string sobrenomeFamilia;

    std::cin >> sobrenomeFamilia;

    while (sobrenomeFamilia != "FIM"){

        if(numFamilias + 1 == capacidadeArr)
            redimensionaArr(capacidadeArr, familias);
        
        familias[numFamilias].sobrenome = sobrenomeFamilia;
        std::cin >> familias[numFamilias].idadePai >> familias[numFamilias].idadeMae >> familias[numFamilias].idadeFilho;

        contador.adicionaIdade(familias[numFamilias].idadeFilho);

        numFamilias++;

        std::cin >> sobrenomeFamilia;

    }

    bool encontrou{false};

    for(int i{0}; i<contador.tamanhoArr; i++){

        if(contador.arr[i].second > 1){

            encontrou = true;

            for(int j{0}; j<numFamilias; j++)
                if(familias[j].idadeFilho == contador.arr[i].first)
                    std::cout << familias[j].sobrenome << "\n";

        }

    }

    if(!encontrou)
        std::cout << "NENHUM\n";

    delete[] familias;

    return 0;
}