#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "Class.h"

//compile: g++ -o main main.cpp Class.cpp
//run: ./main

// ispis onoga sto je komplicirano: std::cout << p.name[i] << p.combination[i].deck_[i].number << p.combination[i].deck_[i].zog << std::endl;


int main(){
    srand(unsigned(time(0)));       //omogucuje da shuffle ne izbaci uvik isti niz 
    int numberOfPlayers;
    std::vector<std::string> s;
    std::vector<mac> tmp;
    std::vector<unsigned int> point;
    int k = 0;
    //card k(3, "tina");
    //print(k);
    std::vector<int> deck;
    //mac d(deck);      def u createDeck
    createDeck(deck);
    std::vector<card> ndeck;
    mac novi(ndeck);

    /* assign_deck(deck, ndeck);        //ako se assign funkcija poziva ovdje, please mind the gap!!
    std::cout << "\nNew deck: \n";
    for(int i = 0; i < 40; i++){
        std::cout << ndeck[i].number << " " << ndeck[i].zog << std::endl;
    } */
    /* std::cout << "\ndeck before main: \n";
    for(int i = 0; i < 40; i++){
        std::cout << deck[i] << " ";
    } */


    input_player(deck, ndeck, s, tmp, numberOfPlayers);
    player p(s, tmp, point);
    //p.printNameCombo(p.name);

    /* for(int i = 0; i < p.name.size(); i++){
        std::cout << p.name[i];
    } */  
    //std::cout << p.name.size() << p.combination.size();

    std::cout << "\n";

    for(int i = 0; i < p.combination.size(); i++){
        for(int j = 0; j < ndeck.size(); j++){
            std::cout << p.combination[i].deck_[j].number << " " << p.combination[i].deck_[j].zog << " ";
        }
        std::cout << "\n";
    }
    PointsPerNumber(p, numberOfPlayers, ndeck);
    Winner(p);
    //p.printComboPoints(p.combination);
   

}
