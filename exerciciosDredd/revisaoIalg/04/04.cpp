#include <iostream>
#include <cstring>

int main(){

    const int numElementos = 8;

    int arr[numElementos], num,  j;

    std::cin >> arr[0];
    std::cout << arr[0] << "\n";
    
    for(int i{1}; i<numElementos; i++){

        std::cin >> num;

        j = 0;
        while(j <= i && arr[j] < num){
            j++;
        }

        if(j <= i)
            std::memcpy(arr + j + 1, arr + j, sizeof(int) * (i - j + 1));
        
        arr[j] = num;


        for(j = 0; j<=i; j++)
            std::cout << arr[j] << " ";
        std::cout << "\n";

    }

    return 0;
}