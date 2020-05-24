#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "ClassDeck.hpp"

mac::mac() {
    std::vector<int> deck;
    std::vector<card> deck_; 
}

mac::mac(std::vector<int>& deck, std::vector<card>& _deck){
    this->deck = deck;
    this->deck_ = _deck;
}

void mac::setInt(std::vector<int>& deck){
    this->deck = deck;
        for(int i = 1; i < deck.size(); i++)
        {
            deck.push_back(deck[i]);
        }
}

void mac::setC(std::vector<card>& _deck){
    this->deck_ = _deck;
    for(int i = 0; i < _deck.size(); i++){
        deck_.push_back(_deck[i]);
    }
}

int mac::getInt(){
    for(int i = 0; i < deck.size(); i++){
        std::cout << deck.at(i) << " ";
    }
    return 0;
}

std::vector<card> mac::getC(){
    return deck_;
}

mac::~mac(){
    deck.erase(deck.begin(), deck.end());
    deck_.erase(deck_.begin(), deck_.end());
}