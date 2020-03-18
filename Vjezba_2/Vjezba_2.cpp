#include <iostream>
#include <array>

//Napisati funkciju koja računa najveći i najmanji broj u nizu od n prirodnih brojeva. 
//Funkcija vraća tražene brojeve pomoću referenci.

void minMax(int& a, int&b, int* arr, int size){
    
    //std::cout << "\nbefore-- " << size << std::endl;
    //std::cout << arr[5] << std::endl;
    --size;
    //std::cout << "\nafter-- " << size <<std::endl;
    while(size){
        if(arr[size] < a){a = arr[size];}
        if(arr[size] > b){b = arr[size];}
        size--;
    }
    //std::cout << a << b << std::endl;
}

int main(){
    int arr[] = {8,2,4,8,22,11,9,0,0,3};
    int size = sizeof(arr) / sizeof(int);
    int min = arr[0], max = arr[0];
    int& a = min; int& b = max;
    minMax(a, b, arr, size);
    std::cout << a << " " << b << std::endl;
    return 0;
}