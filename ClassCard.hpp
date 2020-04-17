#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

#ifndef _card
#define _card

class card{
    unsigned int number;
    std::string zog;
    public:
    //card() = default;     //default konstruktor; generira se ako se inicijalizira klasa bez argumenata!!

    card();
    void setNumb(const unsigned int& a);
    void setZog(const std::string& b);

    unsigned int getNumb();
    std::string getZog();

    ~card();
};

//void print(card& c);

#endif

