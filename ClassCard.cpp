#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "ClassCard.hpp"

card::card(){
    this->number = 0;
    this->zog = "";
    std::cout << "const Card" << std::endl;
}

void card::setNumb(const unsigned int& a){
    this->number = a;
    std::cout << "sN Card" << std::endl;
}
void card::setZog(const std::string& b){
    this->zog = b;
    std::cout << "sZ Card" << std::endl;
}
unsigned int card::getNumb(){
    std::cout << "gN Card" << std::endl;
    return number;
}
std::string card::getZog(){
    std::cout << "gN Card" << std::endl;
    return zog;
}

card::~card(){
    number = 0;
    zog = "";
    std::cout << "dest Card" << std::endl;
    std::cout << number << zog << std::endl;
}




/* 
void print(card& c){
    c.number = 5;
    c.zog = "tina";
    std::cout << c.number << " " << c.zog << std::endl;
} */
