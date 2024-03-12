#include <iostream>
#include <cstring>

void mostraMatriz(int tamMatriz, int matriz[][10]);

void trocaLinha(int tamMatriz, int matriz[][10], int linhaA, int linhaB);

void trocaColuna(int tamMatriz, int matriz[][10], int colunaA, int colunaB);

void trocaDiagonal(int tamMatriz, int matriz[][10]);

void linhaPorColuna(int tamMatriz, int matriz[][10], int linha, int coluna);

int main(){

    const int tamMatriz{10};

    int matriz[tamMatriz][tamMatriz];

    for(int i{0}; i<(tamMatriz*tamMatriz); i++)
        std::cin >> matriz[int(i/tamMatriz)][(i % tamMatriz)];
    
    std::cout << "1.\n";
    trocaLinha(tamMatriz, matriz, 2, 8);

    std::cout << "2.\n";
    trocaColuna(tamMatriz, matriz, 4, 10);

    std::cout << "3.\n";
    trocaDiagonal(tamMatriz, matriz);

    std::cout << "4.\n";
    linhaPorColuna(tamMatriz, matriz, 5, 10);

    return 0;
}

void mostraMatriz(int tamMatriz, int matriz[][10]){

     for(int i{0}; i<tamMatriz; i++){
        for(int j{0}; j<tamMatriz; j++){
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }

}

void trocaLinha(int tamMatriz, int matriz[][10], int linhaA, int linhaB){

    linhaA--;
    linhaB--;

    int matrizFinal[tamMatriz][10];
    std::memcpy(matrizFinal, matriz, (sizeof(int) * tamMatriz * tamMatriz));

    for(int i{0}; i<tamMatriz; i++){
        matrizFinal[linhaA][i] = matriz[linhaB][i];
        matrizFinal[linhaB][i] = matriz[linhaA][i];
    }
    mostraMatriz(tamMatriz, matrizFinal);
}

void trocaColuna(int tamMatriz, int matriz[][10], int colunaA, int colunaB){

    colunaA--;
    colunaB--;

    int matrizFinal[tamMatriz][10];
    std::memcpy(matrizFinal, matriz, (sizeof(int) * tamMatriz * tamMatriz));

    for(int i{0}; i<tamMatriz; i++){
        matrizFinal[i][colunaA] = matriz[i][colunaB];
        matrizFinal[i][colunaB] = matriz[i][colunaA];
    }
    mostraMatriz(tamMatriz, matrizFinal);
}

void trocaDiagonal(int tamMatriz, int matriz[][10]){

    int matrizFinal[tamMatriz][10];
    std::memcpy(matrizFinal, matriz, (sizeof(int) * tamMatriz * tamMatriz));

    for(int i{0}; i<tamMatriz; i++){
        matrizFinal[i][i] = matriz[i][(tamMatriz - 1 - i)];
        matrizFinal[i][(tamMatriz - 1 - i)] = matriz[i][i];
    }
    mostraMatriz(tamMatriz, matrizFinal);
}

void linhaPorColuna(int tamMatriz, int matriz[][10], int linha, int coluna){

    linha--;
    coluna--;

    int matrizFinal[tamMatriz][10];
    std::memcpy(matrizFinal, matriz, (sizeof(int) * tamMatriz * tamMatriz));

    for(int i{0}; i<tamMatriz; i++){
        matrizFinal[linha][i] = matriz[i][coluna];
        matrizFinal[i][coluna] = matriz[linha][i];
    }
    mostraMatriz(tamMatriz, matrizFinal);
}