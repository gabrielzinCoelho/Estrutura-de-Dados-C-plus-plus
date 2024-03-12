#include <iostream>
#include <fstream>

int calculaFib(int n){

    if(n <= 1)
        return n;
    return calculaFib(n-1) + calculaFib(n-2); 

}

int main(){

    std::string nomeArq;
    int n, fib;
    std::cin >> nomeArq >> n;

    std::ofstream arq(nomeArq);

    for(int i{0}; i<n; i++){
        fib = calculaFib(i);
        if(!(fib % 2))
            arq << fib << " ";
    }

    return 0;
}