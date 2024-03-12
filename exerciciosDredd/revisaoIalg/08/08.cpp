#include <iostream>

int main(){

    const int tamMatriz{10};
    int matriz[tamMatriz][tamMatriz];

    int linhaMaior{0}, colunaMaior{0};

    for(int i{0}; i<tamMatriz; i++){
        for(int j{0}; j<tamMatriz; j++){

            std::cin >> matriz[i][j];
            if(matriz[i][j] > matriz[linhaMaior][colunaMaior]){
                linhaMaior = i;
                colunaMaior = j;
            }

        }
    }

    int colunaMenor{0};

    for(int i{0}; i<tamMatriz; i++){
        if(matriz[linhaMaior][i] < matriz[linhaMaior][colunaMenor])
            colunaMenor = i;
    }
    
    std::cout << matriz[linhaMaior][colunaMenor] << "\n";
    std::cout << linhaMaior << " " << colunaMenor << "\n";


    return 0;
}