#include <iostream>
#include <cstring>

void leituraArr(int *arr, int tamArr);

void printaUniao(int *arrA, int tamA, int *arrB, int tamB);

int main(){

    int tamA, tamB, *arrA, *arrB;
    
    std::cin >> tamA;
    arrA = new int[tamA];
    leituraArr(arrA, tamA);

    std::cin >> tamB;
    arrB = new int[tamB];
    leituraArr(arrB, tamB);

    printaUniao(arrA, tamA, arrB, tamB);

    delete[] arrA;
    delete[] arrB;

}

void leituraArr(int *arr, int tamArr){

    for(int i{0}; i<tamArr; i++)
        std::cin >> arr[i];
    
}

void printaUniao(int *arrA, int tamA, int *arrB, int tamB){


    int arrUniao[tamA + tamB];
    std::memcpy(arrUniao, arrA, sizeof(int) * tamA);

    int indexUniao{tamA};
    int j;

    for(int i{0}; i<tamB; i++){

        j = 0;
        while(j < tamA && arrB[i] != arrA[j]){
            j++;
        }

        if(j == tamA)
            arrUniao[indexUniao++] = arrB[i];

    }

    int indexMenor, ultimoMenor{-9999};
    
    for(int i{0}; i<indexUniao; i++){
        
        indexMenor = -1;

        for(int j{0}; j<indexUniao; j++){

            if(arrUniao[j] > ultimoMenor && ( indexMenor == -1 || arrUniao[j] < arrUniao[indexMenor]))
                indexMenor = j;

        }

        ultimoMenor = arrUniao[indexMenor]; 
        std::cout << arrUniao[indexMenor] << " ";

    }
}

// void printaUniao(int *arrA, int tamA, int *arrB, int tamB){

//     int indexA{0}, indexB{0};

//     while(indexA < tamA && indexB < tamB){

//         if(arrA[indexA] == arrB[indexB]){
//             std::cout << arrA[indexA] << " ";
//             indexA++;
//             indexB++;
//         }else if(arrA[indexA] < arrB[indexB])
//             std::cout << arrA[indexA++] << " ";
//         else
//             std::cout << arrB[indexB++] << " ";
        

//     }

//     while(indexA < tamA){

//         std::cout << arrA[indexA] << " ";
//         indexA++;
//     }

//     while(indexB < tamB){

//         std::cout << arrB[indexB] << " ";
//         indexB++;
//     }

// }