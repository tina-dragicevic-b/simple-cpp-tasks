#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include "Japaneza.hpp"

/* 
void rand_shuffle(std::vector<int> &arr){

    srand(unsigned(time(0)));
    std::random_shuffle(arr.begin(), arr.end());
}  */



int main(){
    //određivanje kombinacije kovanica
    int a[] = {1,2,5,0,0,0};
    std::vector<int> arr(a, a + 6);

    /* for(int i = 0; i < 6; i++)
        std::cout << arr[i] << ' ';

    rand_shuffle(arr);
    std::cout << "\n";
    
    for(int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ' '; */    

    //p.PodjelaKovanica(arr);

    int brojIgraca = 3;
    Game game(brojIgraca);
    Player p;
    std::vector<Player*> vec;
    game.InputPlayers(p, arr, vec);
    /* for(int i = 0; i < vec.size(); i++){
        vec[i]->print();
    } */


    /*for(int i = 0; i < brojIgraca; i++){
         
        game.InputPlayers(p, arr);
        //Player p;
        //p.PodjelaKovanica(arr);}  */  
    
    //Game game(1,0,5,a);
    //game.coinSum();
    //InputCoins(game);
    //game.Points();


}