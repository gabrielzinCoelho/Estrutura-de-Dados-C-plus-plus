#include <iostream>
#include <fstream>
#include <cstring>

void alocadorMatriz(int **&matriz, int tamMatriz){

    matriz = new int*[tamMatriz];
    for(int i{0}; i<tamMatriz; i++)
        matriz[i] = new int[tamMatriz];
    
}

void destrutorMatriz(int **matriz, int tamMatriz){

    for(int i{0}; i<tamMatriz; i++)
        delete[] matriz[i];
    delete[] matriz;

}

void lerMatriz(int **matriz, int tamMatriz, std::ifstream &arq){

    for(int i{0}; i<tamMatriz; i++){
        for(int j{0}; j<tamMatriz; j++){
            arq >> matriz[i][j];
        }
    }

}

int contabilizaNavios(int **matriz, int tamMatriz){

    int capacidade{10}, numNavios{0};
    int *idNavios{new int[capacidade]};

    int k;

    for(int i{0}; i<tamMatriz; i++){
        for(int j{0}; j<tamMatriz; j++){

            if(matriz[i][j]){

                k = 0;
                while(k<numNavios && idNavios[k] != matriz[i][j]){
                    k++;
                }

                if(k == numNavios){

                    if(numNavios == capacidade){
                        capacidade += 10;
                        int *aux = new int[capacidade];
                        std::memcpy(aux, idNavios, sizeof(int) * numNavios);
                        delete[] idNavios;
                        idNavios = aux;
                    }

                    idNavios[numNavios++] = matriz[i][j];

                }

            }

        }
    }

    return numNavios;

}

void realizaDisparos(int **matrizNavios, int **matrizDisparos, int tamMatriz){

    for(int i{0}; i<tamMatriz; i++){
        for(int j{0}; j<tamMatriz; j++){

            if(matrizDisparos[i][j]){
                matrizNavios[i][j] = 0;
            }

        }
    }

}

int main(){

    std::ifstream arq("BatalhaNaval.txt");
    int tamMatriz;
    int **matrizNavios, **matrizDisparos;

    arq >> tamMatriz;

    alocadorMatriz(matrizNavios, tamMatriz);
    lerMatriz(matrizNavios, tamMatriz, arq);

    alocadorMatriz(matrizDisparos, tamMatriz);
    lerMatriz(matrizDisparos, tamMatriz, arq);

    int naviosInicias{contabilizaNavios(matrizNavios, tamMatriz)};
    realizaDisparos(matrizNavios, matrizDisparos, tamMatriz);
    int naviosFinais{contabilizaNavios(matrizNavios, tamMatriz)};

    std::cout << (naviosInicias - naviosFinais) << "\n";

    destrutorMatriz(matrizNavios, tamMatriz);
    destrutorMatriz(matrizDisparos, tamMatriz);

    return 0;
}