#include <iostream>

int main(){

    const int numCompetidores{8};
    float *arrTempos{new float[numCompetidores]}, *arrDiferencas{new float [numCompetidores]};

    int indexMenor{0};

    for(int i{0}; i<numCompetidores; i++){

        std::cin >> arrTempos[i];
        if(arrTempos[i] < arrTempos[indexMenor])
            indexMenor = i;
    }

    for(int i{0}; i<numCompetidores; i++){
        arrDiferencas[i] = arrTempos[i] - arrTempos[indexMenor];

        std::cout << (i != indexMenor ? arrDiferencas[i] : arrTempos[i]);
        std::cout << "\n";
    }
    

    delete[] arrTempos;
    delete[] arrDiferencas;

    return 0;
}