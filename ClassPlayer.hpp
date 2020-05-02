#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "ClassDeck.hpp"

class player{
    public:
    std::vector<std::string> name;
    std::vector<mac> combination;
    std::vector<unsigned int> points;
    public:

    player();
    player(std::vector<std::string> name, std::vector<mac> combination, std::vector<unsigned int> points);
    void setName(std::vector<std::string>& name);
    void setCombo(std::vector<mac> combination);
    void setPoints(std::vector<unsigned int> points);
    std::vector<std::string> getName();
    std::vector<mac> getCombo();
    std::vector<unsigned int> getPoints();
    /* player(const std::vector<std::string>& n, std::vector<mac>& c, std::vector<unsigned int>& p) : name(n), combination(c), points(p){
        name = n;
        combination = c;
        points = p;
    }
    void printNameCombo(std::vector<std::string> name){
        for(int i = 0; i < name.size(); i++){
            std::cout << name[i] << points[i];
        }
    }
    void printComboPoints(std::vector<mac> combination){
        for(int i = 0; i < combination.size(); i++){
            std::cout << combination[i].deck_[i].zog << combination[i].deck_[i].zog;
        }
    }
     */
    ~player(){}
};
