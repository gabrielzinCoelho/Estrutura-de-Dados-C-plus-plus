#include <iostream>

void obterVetor(float *arr, int tamArr){

    int fatorial{1};

    arr[0] = (2)/(1.75);

    for(int i{1}; i<tamArr; i++){
        fatorial *= i;
        arr[i] = (2 * fatorial + i) / (i*i + 1.75);
    }

}

int main(){

    int N;
    std::cin >> N;

    float *arr = new float[N];
    obterVetor(arr, N);

    int M;
    std::cin >> M;

    for(int i{M}; i<N; i++)
        std::cout << arr[i] << "\n";

    delete[] arr;

    return 0;
}