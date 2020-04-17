#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "ClassCard.hpp"
#include "ClassDeck.hpp"
#include "ClassPlayer.hpp"


int main(){
    std::cout << "main" << std::endl;
    card c;
    std::vector<int> v{1, 2, 3, 4, 5};
    mac m;
    player p;
    //card c(5, "tina");  //ako pri inicijalizaciji objekta pridjelimo vrijednosti, obavlja se algoritam zadan u konstruktoru;
    //card c;   //ako objektu ne pridjelimo vrijednosti, default constructor (mora biti definiran);

    unsigned int a = 5;
    char b[10] = "tina";
    c.setNumb(a);
    c.setZog(b); 
    //print(c);
    std::cout << c.getNumb() << std::endl;
    std::cout << c.getZog() << std::endl;
    std::vector<card> l;
    l.push_back(c);
    //std::vector<int> v{1, 2, 3, 4, 5};
    //std::vector<card> l;
    m.setInt(v); 
    //std::vector<int> n = m.getInt();    //m.getInt()[i]
    for(int i = 0; i < v.size(); i++){
        std::cout <<  m.getInt() << std::endl;
    } 

    m.setC(l);
    m.getC();

    std::vector<std::string> s('Tina');
    p.setName(s);
    p.getName();

    std::vector<mac> t;
    t.push_back(m);
    p.setCombo(t);
    p.getCombo();

    std::vector<unsigned int> pt{2, 12};
    p.setPoints(pt);
    p.getPoints();
    //std::cout <<  m.getInt() << std::endl;
}

