#include <iostream>
#include <array>

//Funkcija vraca referencu na neki element iz niza. Koristeci povratnu vrijednost funkcije
//kao lvalue uvecajte i-ti element niza za jedan.

int& elementPP(int* arr, int& r_index){

    //std::cout << arr[r_index] << std::endl;
    //arr[r_index] += 1;
    return (arr[r_index]);
}

int main(){
    int arr[] = {8,2,4,8,22,11,9,0,0,3};
    int size = sizeof(arr) / sizeof(int);
    int index = 5;
    int& r_index = index;
    //std::cout << (elementPP(arr, r_index) += 1) << std::endl;
    (elementPP(arr, r_index) += 1);
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}