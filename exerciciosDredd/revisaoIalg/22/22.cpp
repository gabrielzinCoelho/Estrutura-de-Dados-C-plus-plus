#include  <iostream>
#include <fstream>
#include <cstring>

void redimensionaArr(int &capacidade, int* &arr){

    int *novoArr = new int[capacidade + 5];
    std::memcpy(novoArr, arr, sizeof(int) * capacidade);

    delete[] arr;
    arr = novoArr;
    capacidade += 5;

}

void insereArr(int &tamanhoArr, int &capacidade, int *&arr, int num){

    if(tamanhoArr == capacidade)
        redimensionaArr(capacidade, arr);
    
    arr[tamanhoArr++] = num;

}

int main(){

    std::fstream arq;
    arq.open("dados.bin", std::ios::in);

    int capacidade{5}, tamArr{0};
    int *arr = new int[capacidade];

    int num;
    arq.read((char *) (&num), sizeof(int));
    while (num > 0){
        insereArr(tamArr, capacidade, arr, num);
        arq.read((char *) (&num), sizeof(int));
    }
    
    std::cin >> num;
    while (num > 0){
        insereArr(tamArr, capacidade, arr, num);
        std::cin >> num;
    }

    for(int i{0}; i<tamArr; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << "\n" << capacidade << "\n";
    std::cout << (capacidade/5 - 1) << "\n";

    arq.close();
    arq.open("dados.bin", std::ios::out);
    arq.write((const char*) arr, sizeof(int) * tamArr);

    delete[] arr;

    return 0;
}