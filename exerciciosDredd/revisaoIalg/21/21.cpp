#include <iostream>
#include <fstream>

float procuraMenor(float *arr, int numElementos){

    if(numElementos == 1)
        return (*arr);

    float menorRestante = procuraMenor(arr + 1, numElementos - 1);
    return (arr[0] < menorRestante) ? arr[0] : menorRestante;

}

int main(){

    const int numElementos{10};
    std::ifstream arqDat("menor.bin");

    float *arr = new float[numElementos];
    arqDat.read((char *) arr, sizeof(float) * numElementos);

    std::cout << procuraMenor(arr, numElementos) << "\n";

    return 0;

}