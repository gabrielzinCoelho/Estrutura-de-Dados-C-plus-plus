#include <iostream>
#include <fstream>

int main(){

    std::ifstream arqEntrada("entrada.txt");
    std::ofstream arqSaida("saida.txt");

    int quantidadeNum, num, j, indexArr{0};
    arqEntrada >> quantidadeNum;

    int *arr = new int[quantidadeNum];

    for(int i{0}; i<quantidadeNum; i++){
        arqEntrada >> num;
        j = 0;
        while(j < indexArr && arr[j] != num)
            j++;
        
        if(j == indexArr)
            arr[indexArr++] = num;
    }

    for(int i{0}; i<indexArr;i ++)
        arqSaida << arr[i] << " ";

    delete[] arr;

    return 0;
}