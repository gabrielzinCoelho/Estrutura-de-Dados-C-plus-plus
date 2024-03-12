#include <iostream>
#include <fstream>

void escreveSaidaRecursiva(int *arr, int indexArr, std::ifstream &arqEntrada, std::ofstream &arqSaida){

    if(arqEntrada >> arr[indexArr]){
        escreveSaidaRecursiva(arr, indexArr + 1, arqEntrada, arqSaida);
        arqSaida << arr[indexArr] << " ";
    }

}

int main(){

    std::ifstream arqEntrada("entrada.txt");
    std::ofstream arqSaida("saida.txt");

    int *arr = new int[100];

    escreveSaidaRecursiva(arr, 0, arqEntrada, arqSaida);

    delete[] arr;

    return 0;
}