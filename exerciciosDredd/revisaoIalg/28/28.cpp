#include <iostream>
#include <cstring>

void leituraCadeias(int tam, char *c){

    for(int i{0}; i<tam; i++)
        std::cin >> c[i];

}

int main(){

    int tamA, tamB;
    char *arrA, *arrB, *arrC;

    std::cin >> tamA;
    arrA = new char[tamA];
    leituraCadeias(tamA, arrA);

    std::cin >> tamB;
    arrB = new char[tamB];
    leituraCadeias(tamB, arrB);

    int j, numRestantes{0};
    for(int i{0}; i<tamA; i++){
        j = 0;

        while(j < tamB && arrA[i] != arrB[j])
            j++;
            
        if(j == tamB){
            arrA[numRestantes++] = arrA[i];
        }    
    }

    arrC = new char[numRestantes];
    std::memcpy(arrC, arrA, sizeof(char) * numRestantes);

    for(int i{0}; i<numRestantes; i++)
        std::cout << arrC[i] << " ";

    delete[] arrA;
    delete[] arrB;
    delete[] arrC;

    return 0;
}