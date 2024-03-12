#include <iostream>
#include <fstream>

int main(){

    std::ifstream arqPalavras("palavras.txt"), arqNumeros("numeros.txt");
    std::ofstream arqSaida("frase.txt");
    std::string *palavras = new std::string[50];

    int i{0}, indexPalavra;

    while(arqPalavras >> palavras[i])
        i++;
    
    while(arqNumeros >> indexPalavra)
        arqSaida << palavras[indexPalavra - 1] << " ";

    delete[] palavras;

    return 0;
}