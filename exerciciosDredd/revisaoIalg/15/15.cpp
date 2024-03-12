#include <iostream>
#include <fstream>

int main(){

    const std::string nomeArq{"Meu_Arquivo.txt"};
    std::ifstream arq(nomeArq);

    char c;
    int contador{0};

    while(arq >> c)
        if(c != 32)
            contador++;

    std::cout << contador << "\n";

    return 0;
}