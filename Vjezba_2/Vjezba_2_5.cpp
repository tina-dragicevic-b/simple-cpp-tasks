#include <iostream>
#include <array>


//Napisati funkciju za unos pozitivnih cijelih brojeva.
// Korisnik unosi brojevesve dok ne unese nulu. Funkcija inicijalno
// alocira memoriju za 10 elemenata.Svaki put kad veličina niza dosegne 
//alociranu veličinu, alocira se duplo. U main funkciji ispisati dobiveni niz 
//i osloboditi memoriju.

void alloc(int* rx, int rSize){
    int* temp = new int[rSize * 2];
    for(int i = 0; i < rSize; i++){
        temp[i] = rx[i];
    }
    delete [] rx;
    rx = temp;
/*     std::copy(rx, rx + (rSize - 1), temp);
    delete [] rx;
    rx = temp;
    rx = new int [2 * rSize]; */
}

int* intArray(int* rx, int rSize){
    int count = 1; int i = 0;
    std::cout  << "Unesi prvi broj: ";
    std::cin >> rx[0];
    //std::cout << rx[0];
   //std::cout << "\nrsize " << rSize;
    while(rx[i] != 0){
        std::cout << "Unesi broj: ";
        std::cin >> rx[i+1];
        i++;
        count++;
        //std::cout << "\ncount " << count;
        if(count == (rSize)){
            alloc(rx, rSize);
            rSize = rSize * 2; //rSize *= 2;
        }
    }
    return rx;
}

int main(){
    int x[10]; //int& rx;
    int startSize = 10;
    //int& rSize = startSize;
    intArray(x, startSize);
    /* delete [] x;
    x == 0 */;
    return 0;
}