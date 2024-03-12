#include <iostream>

int main(){

    int numLinhas, numColunas;
    std::cin >> numLinhas >> numColunas;

    int matriz[numLinhas][numColunas];

    for(int i{0}; i<numLinhas; i++)
        for(int j{0}; j<numColunas; j++)
            std::cin >> matriz[i][j];
    

    for(int j{0}; j<numColunas; j++){
        for(int i{0}; i<numLinhas; i++)
            std::cout << matriz[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}