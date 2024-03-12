#include <iostream>

void leituraLista(int &tamLista, std::string *&lista);

int main(){

    int tamA, tamB;
    std::string *listaA, *listaB;

    leituraLista(tamA, listaA);
    leituraLista(tamB, listaB);

    int j;
    bool comprouTudo{true};

    for(int i{0}; i<tamA; i++){
        
        j = 0;
        while(j < tamB && listaA[i] != listaB[j])
            j++;
        
        if(j == tamB){
            std::cout << listaA[i] << "\n";
            comprouTudo = false;
        }

    }

    if(comprouTudo)
        std::cout << "NADA\n";

    return 0;
}

void leituraLista(int &tamLista, std::string *&lista){

    std::cin >> tamLista;
    lista = new std::string[tamLista];

    for(int i{0}; i<tamLista; i++)
        std::cin >> lista[i];

}