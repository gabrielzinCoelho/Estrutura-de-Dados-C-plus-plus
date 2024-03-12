#include <iostream>

bool ehPrimo(int x);

int main(){

    const int numElementos{9};
    int arr[numElementos];

    for(int i{0}; i<numElementos; i++)
        std::cin >> arr[i];

    for(int i{0}; i<numElementos; i++)
        if(ehPrimo(arr[i]))
            std::cout << arr[i] << "  " << i << "\n";

}

bool ehPrimo(int x){
    int i{2};

    while(i < x){
        if(!(x % i))
            return false;
        i++;
    }

    return true; 

}