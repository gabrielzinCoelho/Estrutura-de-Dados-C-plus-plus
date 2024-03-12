#include <iostream>
#include <utility>

std::pair<int, int> buscaMatriz(int numLinhas, int numColunas, int **matriz, int numProcurado){

    for(int i{0}; i<numLinhas; i++)
        for(int j{0}; j<numColunas; j++)
            if(matriz[i][j] == numProcurado)
                return std::make_pair(i, j);
    
    return std::make_pair(-1, -1);

}

int main(){

    int numLinhas, numColunas;
    std::cin >> numLinhas >> numColunas;

    int **matriz = new int*[numLinhas];
    for(int i{0}; i<numLinhas; i++)
        matriz[i] = new int[numColunas];
    
    for(int i{0}; i<numLinhas; i++)
        for(int j{0}; j<numColunas; j++)
            std::cin >> matriz[i][j];

    int numProcurado;
    std::cin >> numProcurado;

    auto [indexLinha, indexColuna] = buscaMatriz(numLinhas, numColunas, matriz, numProcurado);
    
    std::cout << (indexLinha != -1 ? (std::to_string(indexLinha) + " " + std::to_string(indexColuna) + "\n") : "ausente\n"); 


    for(int i{0}; i<numLinhas; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}