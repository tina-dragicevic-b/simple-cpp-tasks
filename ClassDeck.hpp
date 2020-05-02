#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "ClassCard.hpp"

#ifndef _mac
#define _mac

class mac{
    std::vector<int> deck;
    std::vector<card> deck_;
    public:

    mac();
    mac(std::vector<int>& deck, std::vector<card>& _deck);
    void setInt(std::vector<int>& deck);
    void setC(std::vector<card>& deck_);
    int getInt();
    std::vector<card> getC();
    ~mac();


/* 
    mac(std::vector<int>& deck) : deck(0) {
        this->deck = deck;
        for(int i = 1; i < 41; i++)
        {
            deck.push_back(i);
        } 
    }
    mac(std::vector<card>& ndeck) : deck_(ndeck) {
        this->deck_ = ndeck;
    }
    ~mac(){} */
};

#endif