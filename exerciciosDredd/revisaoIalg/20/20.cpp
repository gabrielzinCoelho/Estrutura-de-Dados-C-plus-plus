#include <iostream>
#include <fstream>

struct Aluno{
    char nome[100];
    int matricula;
    float nota;
};

int main(){

    std::fstream arqDat;
    arqDat.open("alunos.bin", std::ios::out);

    int n, matriculaBusca, novaMatricula;
    std::cin >> n;
    Aluno aluno;

    for(int i{0}; i<n; i++){
        std::cin >> aluno.nome >> aluno.matricula >> aluno.nota;
        arqDat.write((const char *) (&aluno), sizeof(Aluno));
    }

    std::cin >> matriculaBusca >> novaMatricula;

    arqDat.close();
    arqDat.open("alunos.bin", std::ios::in);

    int posInicial{0}, posFinal{n - 1}, posMeio, indexAluno{-1};

    while(posInicial <= posFinal){

        posMeio = (posInicial + posFinal)/2;

        arqDat.seekg(posMeio * sizeof(Aluno));
        arqDat.read((char *) (&aluno), sizeof(Aluno));

        if(matriculaBusca == aluno.matricula){
            indexAluno = posMeio;
            posInicial = posFinal + 1;
        }else if(matriculaBusca < aluno.matricula)
            posFinal = posMeio - 1;
        else
            posInicial = posMeio + 1;

    }

    int novoIndex, i{novaMatricula >= matriculaBusca ? indexAluno : 0};
    Aluno *alunos = new Aluno[n];

    do{

        arqDat.seekg(i * sizeof(Aluno));
        arqDat.read((char *) (&aluno), sizeof(Aluno));
        i++;

    }while(i < n && novaMatricula >= aluno.matricula);
    
    novoIndex = i -1;

    if(novoIndex != indexAluno){

        arqDat.seekg(indexAluno * sizeof(Aluno));
        arqDat.read((char *) (&aluno), sizeof(Aluno));

        if(novoIndex > indexAluno){

            arqDat.seekg((indexAluno + 1) * sizeof(Aluno));
            arqDat.read((char *) alunos, (novoIndex - indexAluno) * sizeof(Aluno));

            arqDat.close();
            arqDat.open("alunos.bin", std::ios::out);
            arqDat.seekp((indexAluno) * sizeof(Aluno));
            arqDat.write((const char*) alunos, (novoIndex - indexAluno) * sizeof(Aluno));

        }else{

            arqDat.seekg(novoIndex * sizeof(Aluno));
            arqDat.read((char *) alunos, (indexAluno - novoIndex) * sizeof(Aluno));

            arqDat.close();
            arqDat.open("alunos.bin", std::ios::out);
            arqDat.seekp((novoIndex + 1) * sizeof(Aluno));
            arqDat.write((const char*) alunos, (indexAluno - novoIndex) * sizeof(Aluno));

        }

        aluno.matricula = novaMatricula;
        arqDat.seekp(novoIndex * sizeof(Aluno));
        arqDat.write((const char*) (&aluno), sizeof(Aluno));

    }

    arqDat.close();
    arqDat.open("alunos.bin", std::ios::in);

    for(int i{0}; i<n; i++){
        arqDat.read((char *) (&aluno), sizeof(Aluno));
        std::cout << aluno.nome << " " << aluno.nota << "\n";
    }

    delete[] alunos;

    return 0;
}