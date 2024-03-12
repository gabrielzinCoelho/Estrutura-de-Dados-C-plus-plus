#include <iostream>

struct Aluno{
    int matricula, notaA, notaB;
    float media;
};

// bool operator<(const Aluno &alunoA, const Aluno &alunoB){
//     float mediaA{(alunoA.notaA + alunoA.notaB)/2.0};
//     float mediaB{(alunoB.notaA + alunoB.notaB)/2.0};

//     return mediaA < mediaB;
// }

bool operator<(const Aluno &alunoA, const Aluno &alunoB){
    
    return alunoA.media < alunoB.media;
}

void selectionSort(Aluno ***matrizAlunos, int tamMatriz, int indexColuna){

    int indexMenor;
    Aluno *aux;

    for(int i{0}; i<(tamMatriz - 1); i++){

        indexMenor = i;
        for(int j{indexMenor + 1}; j<tamMatriz; j++){

            if((*matrizAlunos[j][indexColuna]) < (*matrizAlunos[indexMenor][indexColuna])){
                indexMenor = j;
            }

        }

        if(indexMenor != i){
            aux = matrizAlunos[i][indexColuna];
            matrizAlunos[i][indexColuna] = matrizAlunos[indexMenor][indexColuna];
            matrizAlunos[indexMenor][indexColuna] = aux;
        }


    }


}

int main(){

    int n;
    std::cin >> n;

    Aluno ***matrizAlunos = new Aluno**[n];
    for(int i{0}; i<n; i++)
        matrizAlunos[i] = new Aluno*[n];

    for(int i{0}; i<n; i++){
        for(int j{0}; j<n; j++){

            matrizAlunos[i][j] = new Aluno;
            std::cin >> matrizAlunos[i][j]->matricula >> matrizAlunos[i][j]->notaA >> matrizAlunos[i][j]->notaB;
            matrizAlunos[i][j]->media = (matrizAlunos[i][j]->notaA + matrizAlunos[i][j]->notaB)/2.0;
        }
    }

    for(int i{0}; i<n; i++)
        selectionSort(matrizAlunos, n, i);


    for(int i{0}; i<n; i++){
        for(int j{0}; j<n; j++){

            std::cout << matrizAlunos[i][j]->matricula << " ";
        }

        std::cout << "\n";
    }


    for(int i{0}; i<n; i++)
        delete[] matrizAlunos[i];
    delete[] matrizAlunos;

    return 0;
}