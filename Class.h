#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>


class card{
    public:
    unsigned int number;
    std::string zog;
    public:
    card(const unsigned int& a, const std::string& b) : number(0), zog("") {
        this->number = a;
        this->zog = b;
        /* std::cout << a << "\n";
        std::cout << b; */
    }
    ~card(){}
};
class mac{
    public:
    std::vector<int> deck;
    std::vector<card> deck_;
    public:
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
    ~mac(){}
};
class player{
    public:
    std::vector<std::string> name;
    std::vector<mac> combination;
    std::vector<unsigned int> points;
    public:
    player(const std::vector<std::string>& n, std::vector<mac>& c, std::vector<unsigned int>& p) : name(n), combination(c), points(p){
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
    
    ~player(){}
};

card print(class card k);
card ret(class card k);
std::vector<int>& createDeck(std::vector<int>& deck);
void printDeck(std::vector<int>& deck);
void rand_shuffle(std::vector<int>& deck);
std::vector<card>& assign_deck(std::vector<int>& deck, std::vector<card>& ndeck);
std::vector<mac>& input_player(std::vector<int>& deck, std::vector<card>& ndeck, std::vector<std::string>& s, std::vector<mac>& tmp, int& numberOfPlayers);
int PointsPerNumber(player& p, int& numberOfPlayers, std::vector<card>& ndeck);
std::vector<unsigned int>& PointsNapolitana(player& p, std::vector<card>& ndeck, std::vector<unsigned int>& vnapolitana);
int Winner(player p);