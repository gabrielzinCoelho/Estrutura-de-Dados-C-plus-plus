#include <iostream>
#include <utility>

bool procuraHorizontal(char **matriz, int tamMatriz, const std::string &palavraBuscada, std::pair<int, int>  indexMatriz){

    int tamPalavra{palavraBuscada.length()};

    if(tamPalavra > (tamMatriz - indexMatriz.second))
        return false;
    
    int i{0};
    while(i < tamPalavra && matriz[indexMatriz.first][i + indexMatriz.second] == palavraBuscada[i])
        i++;
    
    return (i == tamPalavra);

}

bool procuraVertical(char **matriz, int tamMatriz, const std::string &palavraBuscada, std::pair<int, int>  indexMatriz){

    int tamPalavra{palavraBuscada.length()};

    if(tamPalavra > (tamMatriz - indexMatriz.first))
        return false;
    
    int i{0};
    while(i < tamPalavra && matriz[i + indexMatriz.first][indexMatriz.second] == palavraBuscada[i])
        i++;
    
    return (i == tamPalavra);

}

int main(){

    int n;
    std::cin >> n;

    char **matriz{new char*[n]};
    for(int i{0}; i<n; i++)
        matriz[i] = new char[n];
    

    for(int i{0}; i<n; i++)
        for(int j{0}; j<n; j++)
            std::cin >> matriz[i][j];
    
    int m;
    std::cin >> m;
    std::string palavra;

    int k;

    for(int i{0}; i<m; i++){
        std::cin >> palavra;

        k = 0;
        while(
            k < n*n && 
            !procuraHorizontal(matriz, n, palavra, std::make_pair(int(k/n), (k%n))) &&
            !procuraVertical(matriz, n, palavra, std::make_pair(int(k/n), (k%n)))
        ){
            k++;
        }

        if(k == n*n){
            std::cout << "-1 -1\n";
        }else{
            std::cout << int(k/n) << " " << (k%n) << "\n";
        }

    }

    for(int i{0}; i<n; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}