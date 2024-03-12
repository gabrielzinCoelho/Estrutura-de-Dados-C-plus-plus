#include <iostream>

void leituraLista(std::string *lista, int tamLista);

bool procuraLista(const std::string &palavra, std::string *lista, int tamLista);

int main(){

    int tamA, tamB, tamC;
    std::string *listaA, *listaB, *listaC;

    std::cin >> tamA;
    listaA = new std::string[tamA];
    leituraLista(listaA, tamA);

    std::cin >> tamB;
    listaB = new std::string[tamB];
    leituraLista(listaB, tamB);

    std::cin >> tamC;
    listaC = new std::string[tamC];
    leituraLista(listaC, tamC);

    int contadorPalavra;

    for(int i{0}; i<tamC; i++){

        contadorPalavra = 0;
        contadorPalavra += procuraLista(listaC[i], listaA, tamA);
        contadorPalavra += procuraLista(listaC[i], listaB, tamB);

        std::cout << contadorPalavra << " ";

    }

    delete[] listaA;
    delete[] listaB;
    delete[] listaC;

    return 0;
}

bool procuraLista(const std::string &palavra, std::string *lista, int tamLista){

    int j{0};

    while(j < tamLista && lista[j] != palavra)
        j++;
    
    return !(j == tamLista);
    

}


void leituraLista(std::string *lista, int tamLista){

    for(int i{0}; i<tamLista; i++)
        std::cin >> lista[i];

}