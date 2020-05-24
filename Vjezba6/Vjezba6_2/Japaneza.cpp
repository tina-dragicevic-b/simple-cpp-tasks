#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include "Japaneza.hpp"


Player::Player(){
    igrac = "igrac";
    leftHandSum = 0;
    rightHandSum = 0;
    SumOfPoints = 0;
}

void Player::print(){
    std::cout << igrac << std::endl;
    std::cout << leftHandSum << std::endl;
    std::cout << rightHandSum << std::endl;
    std::cout << SumOfPoints << std::endl;
    //std::cout << igrac << std::endl;

}

void Player::PodjelaKovanica(std::vector<int> &arr, std::vector<Player*>& vec){

    int j = 0;
    for(int i = 0; i < 6; i++){
        if(i < 3)
            lCoins[i] = arr[i];
        else
            rCoins[j++] = arr[i];
            //vec.push_back(rCoins[i])
    }
    

    /* for(int i = 0; i < vec.size(); i++){
        std:: cout << "vec " << *vec.at(i) << std::endl;
    }*/

    std::cout << "\n";
    for(int i = 0; i < 3; i++) std::cout << "leftHandCoins " << lCoins[i] << "  rightHandCoins " << rCoins[i] << "\n";

    
    for(int i = 0; i < 3; i++){
        if(lCoins[i] > 0){leftHandSum++;}
        if(rCoins[i] > 0){rightHandSum++;}
    }
    vec.push_back(new Player());
    std::cout << "\n" << "lijeva " << leftHandSum << " desna " << rightHandSum << std::endl;
    leftHandSum = 0; rightHandSum = 0;
    
}

/* void Player::CoinsPerHand(Game a){}*/


/* void Player::coinSum(){
    SumOfCoins += (coin1 +  coin2 + coin5);
    std::cout << "Sum of coins " << SumOfCoins << std::endl;} */

void Player::SumPoints(){
    if(true)
        SumOfPoints++;
}

Player::~Player(){}  


HumanPlayer::HumanPlayer(){
    SumOfPoints = 0;
}

void HumanPlayer::SumPoints(){
    if(true)
        SumOfPoints++;
}

HumanPlayer::~HumanPlayer(){}


Computer::Computer(){
    SumOfPoints = 0;
}

void Computer::SumPoints(){
    if(true)
        SumOfPoints++;
}

Computer::~Computer(){}


Game::Game(){}
/* 
Game::Game(int a, int b, int c, int MaxPoints){
    coin1 = 1;
    coin2 = 2;
    coin5 = 5;
    this->MaxPoints= MaxPoints;
    std::cout << a << ' ' << b << ' ' << c << ' ' << MaxPoints;
} */

Game::Game(int a){
    numbOfPlayers = a;
    std::cout << "Broj igraca " << numbOfPlayers << std::endl;
    VectorOfPlayers.push_back(new Player());
}

void Game::InputPlayers(Player& p, std::vector<int> &arr, std::vector<Player*>& vec){
    //for(int i = 1; i <= numbOfPlayers; i++){
    //    VectorOfPlayers.push_back(i);}

    //std::vector<Player*> vec;
    for(int i = 1; i <= numbOfPlayers; i++){
        for(int j = 0; j < 6; j++)
            std::cout << arr[j] << ' ';
        
        rand_shuffle(arr);
        std::cout << "\n";

        for(int k = 0; k < arr.size(); k++)
            std::cout << arr[k] << ' ';
        std::cout << "\n" << " Igrac " << i << std::endl;
        p.PodjelaKovanica(arr, vec);
        //std::cout << "\n" <<  leftHandSum << " ..." << std::endl;
       // vec.push_back(new Player(p));
    }
    /* for(int i = 0; i < vec.size(); i++){
        //std::cout << vec.at(i) << std::endl;
        std::cout << " Ispis vektora "<< std::endl;
        vec[i]->print();
    }  */
    
    
    

    /* for(int i = 0; i < numbOfPlayers; i++){
        vect.push_back(igrac);
        vect.push_back(i);
        PodjelaKovanica();
        std::copy(&lCoins[0], &lCoins[3], std::back_inserter(vect));
    } */
    //PodjelaKovanica
}

/* void Game::P(int &a[], int &b[]){

} */


void Game::print(){
    std::cout << numbOfPlayers << std::endl;
}

Game::~Game(){

    for(int i = 0; i < VectorOfPlayers.size(); i++)
        delete VectorOfPlayers[i];
    VectorOfPlayers.clear();
}



void rand_shuffle(std::vector<int> &arr){

    srand(unsigned(time(0)));
    std::random_shuffle(arr.begin(), arr.end());
} 