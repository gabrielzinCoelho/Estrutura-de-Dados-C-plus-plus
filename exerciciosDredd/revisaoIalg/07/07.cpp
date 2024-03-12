#include <iostream>

int main(){

    int matrizA[4][5], matrizB[5][2], matrizC[4][2];

    for(int i{0}; i<4; i++)
        for(int j{0}; j<5; j++)
            std::cin >> matrizA[i][j];

    for(int i{0}; i<5; i++)
        for(int j{0}; j<2; j++)
            std::cin >> matrizB[i][j];

    int soma;

    for(int i{0}; i<4; i++){
        for(int j{0}; j<2; j++){

            soma = 0;
            for(int k{0}; k<5; k++)
                soma += matrizA[i][k] * matrizB[k][j];
            
            matrizC[i][j] = soma;

        }
    }
    
    for(int i{0}; i<4; i++){
        for(int j{0}; j<2; j++){
            std::cout << matrizC[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}