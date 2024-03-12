#include <iostream>
#include <cstring>

struct Aluno{
    char nome[100];
    float mediaNota;
    int numFaltas;
};

bool operator<(const Aluno &alunoA, const Aluno &alunoB){
    return alunoA.mediaNota < alunoB.mediaNota;
}

int main(){

    int n, numAlunos{0};
    std::cin >> n;

    Aluno *alunos = new Aluno[n];
    Aluno aluno;

    int j;

    for(int i{0}; i<n; i++){
        std::cin >> aluno.nome >> aluno.mediaNota >> aluno.numFaltas;

        j = 0;
        while(j < numAlunos && aluno < alunos[j]){
            j++;
        }

        if(j != numAlunos)
            std::memcpy((alunos + j + 1), alunos + j, sizeof(Aluno) * (numAlunos - j));
        

        alunos[j] = aluno;
        numAlunos++;
    }

    for(int i{0}; i<numAlunos; i++)
        std::cout << alunos[i].nome << "\n";

    delete[] alunos;

    return 0;
}