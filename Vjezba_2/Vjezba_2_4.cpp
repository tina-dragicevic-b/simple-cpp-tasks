#include <iostream>
#include <array>

//Napisi funkciju koja vraća niz int vrijednosti velićine n u kojem je svaki
//element zbroj svoja dva prethodnika. Prvi i drugi el u nizu su jedinice. 
//U main funkciji ispisati dobiveni niz i osloboditi memoriju.

int* Array(int n){
     int* arr_= new int[n + 1];

    for(int i = 0; i < (n + 1); i++){
        if(i == 0 || i == 1){
            arr_[i] = {1};
        }
        else{
            arr_[i] = arr_[i - 1] + arr_[i - 2];
        }
    }
    return arr_;
}

int main(){
    int* pointer; int n = 7;
    pointer = Array(n);
    for(int i = 0; i < n; i++){
        std::cout << pointer[i] << std::endl;
    }
    return 0;
}