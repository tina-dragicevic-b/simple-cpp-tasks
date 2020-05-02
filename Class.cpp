#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "Class.h"


std::vector<card>& assign_deck(std::vector<int>& deck, std::vector<card>& deck_){
    //std::cout << "size of deck: " << deck.size();
    deck_.clear();
    unsigned int a; std::string b;
    std::string zog[4] = {"Kupe", "Bastoni", "Spade", "Dinari"};
    unsigned int broj[10] = {1, 2, 3, 4, 5, 6, 7, 11, 12, 13};
    for(int i = 0; i < deck.size(); i++){            //ako je poziv funkcije prije inputPlayer, brojac i mora bit postavljen na 0:40; else 0:10
        for(int j = 0; j < 7; j++){
            if((deck[i] % 10) == broj[j]){
                a = broj[j];
            }
            else if(((deck[i] % 10) == 8) || (deck[i] % 10) == 9){
                a = broj[j] + 3;
            }
            else if((deck[i] % 10) == 0){
                a = 13;
            }
            if(deck[i] < 11){
                b = zog[0];
            }
            else if((deck[i] > 10) && (deck[i] < 21)){
                b = zog[1];
            }

            else if((deck[i] > 20) && (deck[i] < 31)){
                b = zog[2];
            }

            else if((deck[i] > 30) && (deck[i] < 41)){
                b = zog[3];
            }
        }
        card temp(a, b);
        deck_.push_back(temp);
    }
    //print deck_
   /*  for(int i = 0; i < deck_.size(); i++){
        std::cout << deck_[i].number << " " << deck_[i].zog << std::endl;
    } */ 
    return deck_;
}

std::vector<int>& createDeck(std::vector<int>& deck){
    mac d(deck);
    /* for(int i = 1; i < 41; i++){
        deck.push_back(i);
    } */
    //printDeck(deck);
    rand_shuffle(deck);
    //printDeck(deck);
    return deck;
}

void printDeck(std::vector<int>& deck){
    std::cout << "\nDeck: " << std::endl;
    for(int i = 0; i < 40; i++){
        std::cout << deck[i] << " ";
    }
}

void rand_shuffle(std::vector<int>& deck){
    std::random_shuffle(deck.begin(),deck.end());
    //printDeck(deck);
}

std::vector<mac>& input_player(std::vector<int>& deck, std::vector<card>& ndeck, std::vector<std::string>& s, std::vector<mac>& tmp, int& i){
    std::vector<int> temp;
    temp.clear();
    std::cout << "Input a number of players (2-4): \n";
    std::cin >> i;
    int k = 0;
    std::string n[10] = {"1", "2", "3", "4"};
    for(int j = 0; j < (i); j++){
        s.push_back(" Igrac");      //for some reason, using " " and "_" ispisuje manje od 'i' elemenata;
        s.push_back(n[j]);
        //std::cout << s[j];
    }
    std::cout << "\n";
    //printDeck(deck);
    int count = i;
    //std::cout << "count " << count;
    for(int j = 0; j < deck.size(); j++){
        temp.push_back(deck[j]);
        //std::cout << temp[j] << " ";
        if(temp.size() == 10){
            --count;
            assign_deck(temp, ndeck);
            mac t(ndeck);
            //std::cout << ndeck.size();
            tmp.push_back(t);
            //std::cout << tmp.size();
            temp.clear();
            //std::cout << temp.size();
        }
        if(count < 1){
            break;
        }
    }
    return tmp;
}

card print(class card k){
    //std::cout << "\nprint\n";
    std::cout << k.number << std::endl;
    std::cout << k.zog << std::endl;
    return k;
}

card ret(class card k){
    return k;
}

int Winner(player p){
    unsigned int max = 0;
    int t;
    for(int i = 0; i < p.combination.size(); i++){
        if(p.points[i] > 0 && p.points[i] == max){
            std::cout << " Two players have the same number of points. " << std::endl;
        }
        if(p.points[i] > max){
            max = p.points[i];
            t = i;
        }
    }
    if(max == 0){
        std::cout << " No winners. ";
        return -1;}
    else
        {std::cout << " Winner is "  << p.name[t] << t + 1 << " points " << p.points[t] << std::endl;}
    return 0;
}

void SumPoints(player& p, std::vector<unsigned int> vone, std::vector<unsigned int> vtwo, std::vector<unsigned int> vthree, std::vector<unsigned int> vnapolitana){
    unsigned int temp = 0;
    for(int i = 0; i < p.combination.size(); i++){
        temp = (vone[i] + vtwo[i] + vthree[i] + vnapolitana[i]);
        p.points.push_back(temp);
        std::cout << " Sum Points " << p.points[i] << std::endl;
        temp = 0;
    }
}

std::vector<unsigned int>& PointsNapolitana(player& p, std::vector<card>& ndeck, std::vector<unsigned int>& vnapolitana){
    unsigned int napolitana = 0;
    unsigned int b = 0, k = 0, s = 0, d = 0; 
    for(int i = 0; i < p.combination.size(); i++){
        for(int j = 0; j < ndeck.size(); j++){
            if(p.combination[i].deck_[j].zog == "Bastoni"){
                if(p.combination[i].deck_[j].number == 1){b++;}
                if(p.combination[i].deck_[j].number == 2){b++;}
                if(p.combination[i].deck_[j].number == 3){b++;}
            }
            if(p.combination[i].deck_[j].zog == "Kupe"){
                if(p.combination[i].deck_[j].number == 1){k++;}
                if(p.combination[i].deck_[j].number == 2){k++;}
                if(p.combination[i].deck_[j].number == 3){k++;}
            }
            if(p.combination[i].deck_[j].zog == "Spade"){
                if(p.combination[i].deck_[j].number == 1){s++;}
                if(p.combination[i].deck_[j].number == 2){s++;}
                if(p.combination[i].deck_[j].number == 3){s++;}
            }
            if(p.combination[i].deck_[j].zog == "Dinari"){
                if(p.combination[i].deck_[j].number == 1){d++;}
                if(p.combination[i].deck_[j].number == 2){d++;}
                if(p.combination[i].deck_[j].number == 3){d++;}
            }
        }
        if(b >= 3){napolitana++;}
        if(k >= 3){napolitana++;}
        if(s >= 3){napolitana++;}
        if(d >= 3){napolitana++;}
        napolitana *= 3;
        vnapolitana.push_back(napolitana);
        napolitana = 0;
        b = 0; k = 0; s = 0; d = 0;
    }
    return vnapolitana;
}

int PointsPerNumber(player& p, int& numberOfPlayers, std::vector<card>& ndeck){
    unsigned int one = 0; unsigned int two = 0; unsigned int three = 0;
    std::vector<unsigned int> vone;
    std::vector<unsigned int> vtwo;
    std::vector<unsigned int> vthree;
    std::vector<unsigned int> vnapolitana;
    for(int i = 0; i < p.combination.size(); i++){
        for(int j = 0; j < ndeck.size(); j++){
            if(p.combination[i].deck_[j].number == 1){
                one++;
            }
            if(p.combination[i].deck_[j].number == 2){
                two++;
            }
            if(p.combination[i].deck_[j].number == 3){
                three++;
            }/* 
            std::cout << one << two << three;
            std::cout << "\n";
            p.points = one + two + three;
            std::cout << "\npoints " <<p.points; */
        }
        std::cout << "one " << one << " two " << two << " three " << three << std::endl;
        if(one >= 3){vone.push_back(3);}
        else{vone.push_back(0);}
        if(two >= 3){vtwo.push_back(3);}
        else{vtwo.push_back(0);}
        if(three >= 3){vthree.push_back(3);}
        else{vthree.push_back(0);}

        one = 0; two = 0; three = 0;
    }
    PointsNapolitana(p, ndeck, vnapolitana);
    for(int i = 0; i < p.combination.size(); i++){
        std::cout << "one " << vone.at(i) << " two " << vtwo.at(i) << " three " << vthree.at(i) << " napolitana " << vnapolitana.at(i) << std::endl;
    }
    SumPoints(p, vone, vtwo, vthree, vnapolitana);
    return 0;

}




