#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "ClassPlayer.hpp"

player::player(){
    std::vector<std::string> name;
    std::vector<mac> combination;
    std::vector<unsigned int> points;
}

player::player(std::vector<std::string> name, std::vector<mac> combination, std::vector<unsigned int> points){
    this->name = name;
    this->combination = combination;
    this->points = points;
}

void player::setName(std::vector<std::string>& n){
    name = n;
    for(int i = 0; i < n.size(); i++){
        std::string temp = n[i];
        name[i].push_back(temp);
    }
}

void player::setCombo(std::vector<mac> c){
    combination = c;
    for(int i = 0; i < c.size(); i++){
        combination.push_back(c[i]);
    }
}

void player::setPoints(std::vector<unsigned int> p){
    points = p;
    for(int i = 0; i < p.size(); i++){
        points.push_back(p[i]);
    }
}

std::vector<std::string> player::getName(){
    return name;
}

std::vector<mac>player::getCombo(){
    return combination;
}

std::vector<unsigned int> player::getPoints(){
    return points;
}