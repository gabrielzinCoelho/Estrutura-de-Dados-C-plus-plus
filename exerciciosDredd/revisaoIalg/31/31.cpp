#include <iostream>
#include <fstream>

void printNumeros(float *arr, int n){

    int indexInicio;

    if( !(n % 2)){
        indexInicio = n - 1;
    }else {
        indexInicio = n - 2;
        std::cout << arr[n - 1] << " ";
    }

    for(int i{indexInicio}; i>=0; i -= 2){
        std::cout << ((arr[i] + arr[i - 1])/2) << " ";
    }

}

int main(){

    std::string nomeArq;
    std::cin >> nomeArq;

    std::ifstream arq(nomeArq);

    int n;
    arq >> n;

    float *arr = new float[n];
    for(int i{0}; i<n; i++)
        arq >> arr[i];
    
    printNumeros(arr, n);

    delete[] arr;

    return 0;
}