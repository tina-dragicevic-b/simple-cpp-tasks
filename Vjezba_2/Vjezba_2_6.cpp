#include <iostream>
#include <array>

//Definirati strukturu koja opisuje vektor.
// Struktura se sastoji od niza int elemenata, logičke i fizičke veličine niza.
// Fizička veličina je inicijalno init, a kada se ta veličina napuni vrijednostima,
// alocira se duplo.
//Napisati funkcije vector_new,vector_delete,vector_push_back,vector_pop_back,vector_front,vector_back i vector_size

typedef struct _Vector
{
    int* Array;
    int log_size = 0;   //stvarni broj el u nizu
    int phys_size = 8;  //ukupan br el koje niz moze zauzeti
}Vector;

void vector_new(Vector niz){
    //niz.phys_size = 10; 
    //niz.Array = (int*)malloc(sizeof(int));
    int a = niz.log_size;
    while(a < niz.phys_size){            //ako je fizicka velicina veca od 7, pukne nakon 7. unesenog el
        vector_push_back(niz);
        if(a == niz.phys_size){
            Vector temp;
            temp.Array = new int[niz.phys_size * 2];
            std::copy(niz.Array, niz.Array + niz.phys_size + 1, temp);
            delete [] niz.Array;
            niz.Array = temp.Array;
            a *= 2;
        }
    }
    //std::cout << niz.log_size << std::endl;
    return;
}

void vector_push_back(Vector niz){
    std::cout << "Unesi element: ";
    std::cin >> niz.Array[niz.log_size];
    int b =vector_size(niz);
    return;
}

int vector_size(Vector niz){
    niz.log_size++;
    return niz.log_size;
}

int vector_front(Vector niz){
    return niz.Array[0];
}
int vector_back(Vector niz){
    //int a = vector_size(niz);
    return niz.Array[niz.log_size - 1];
}
int* vector_pop_back(Vector niz){
    int a = niz.log_size;
    Vector newArr;
    newArr.Array  = new int[a - 1];
    for(int i = 0; i < a - 2; i++){
        newArr.Array[i] = niz.Array[i];
    }
    delete[]niz.Array;
    /* niz.Array[niz.log_size - 1] = {};
    niz.log_size -= 1; */
    return newArr.Array;
}
int* vector_delete(Vector niz){
    for(int i = (niz.log_size - 1); i > 0; i--){ 
        niz.Array[i] = {};
    }
    delete[]niz.Array;
    niz.Array = {};
    return niz.Array;
}


int main(){
    Vector niz;
    vector_new(niz);
    vector_push_back(niz);
    vector_pop_back(niz);
    vector_size(niz);
    vector_front(niz);
    vector_back(niz);
    vector_delete(niz);
    return 0;
}