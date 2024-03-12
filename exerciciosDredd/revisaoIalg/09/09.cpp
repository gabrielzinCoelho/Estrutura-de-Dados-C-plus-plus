#include <iostream>

void procuraPecas(int tamMatriz, int matriz[][8], int linhaTorre, int colunaTorre, int direcaoX = 0, int direcaoY = -1);
bool posValida(int tamMatriz, int x, int y);

int main(){

    const int tamMatriz{8};
    int tabuleiro[tamMatriz][tamMatriz], linhaTorre, colunaTorre;

    for(int i{0}; i<tamMatriz; i++){
        for(int j{0}; j<tamMatriz; j++){
            std::cin >> tabuleiro[i][j];
            if(tabuleiro[i][j] == 1){
                linhaTorre = i;
                colunaTorre = j;
            }
        }
    }

    procuraPecas(tamMatriz, tabuleiro, linhaTorre, colunaTorre);
    procuraPecas(tamMatriz, tabuleiro, linhaTorre, colunaTorre, -1, 0);
    procuraPecas(tamMatriz, tabuleiro, linhaTorre, colunaTorre, 1, 0);
    procuraPecas(tamMatriz, tabuleiro, linhaTorre, colunaTorre, 0, 1);

    return 0;
}

bool posValida(int tamMatriz, int x, int y){
    return (x>=0 && x<tamMatriz && y>=0 && y<tamMatriz);
}

void procuraPecas(int tamMatriz, int matriz[][8], int linhaTorre, int colunaTorre, int direcaoX, int direcaoY){

    int i{linhaTorre + direcaoY}, j{colunaTorre + direcaoX};
    while(posValida(tamMatriz, i, j) && !(matriz[i][j])){
        i+= direcaoY;
        j+= direcaoX;
    }

    if(posValida(tamMatriz, i , j))
        std::cout << i << " " << j << "\n";

}