#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include "book.hpp"

/*1. Definirajte klasu Book čiji su članovi autor, naslov knjige i godina izdanja. Iz
klase Book izvedite dvije klase: HardCopyBook i EBook. Papirnata knjiga ima
još i broj stranica, a elektronska knjiga ime datoteke i veličinu u MB.
Definirajte klasu Library koja ima niz (ili vektor) pointera na Book i nekoliko
metoda:
· metodu koja vraća sve naslove nekog autora,
· metodu koja vraća ukupnu veličinu u MB za sve knjige nekog autora,
· metodu koja za neki dio naslova (jedna ili više riječi) vraća sve knjige
koje sadrže te riječi.
U funkciji main testirajte metode klase Library. Unos knjiga možete realizirati 
čitanjem iz datoteke (u prilogu je primjer čitanja iz datoteke).*/


int main(){
    //std::cout << "tu sam";
    //Book c;
    //c.year = 5;
    //c.print();
    EBook a; a.year = 5; a.print();
    //HardCopyBook b;
    //a.print();
    //b.print();
    

    

    std::ifstream fin("knjige.txt");
    std::vector<std::string> v;
    std::string line;
    
    // citanje i spremanje u vektor
    while(getline(fin, line))
        v.push_back(line);
    
    
    // ispis vektora - test
    std::vector<std::string>::iterator it;
    
    /*for (it = v.begin(); it != v.end(); ++it)
       std::cout << *it << std::endl; */

    Book c;

    std::string name;
    Library lib;
    
    for(it = v.begin(); it != v.end(); it++){
        name = *it;
        //std::cout << "name" << name << std::endl;
        lib.Funk(v, name);
        //std::cout << " name " << lib.name << std::endl;
        //std::cout << " book " << lib.book << std::endl;
    }
    lib.print();
    
    /* for(int i = 0; i < v.size(); i++){
        std::cout << " name " << lib.name << std::endl;
        std::cout << " book " << lib.book << std::endl;
    } */


 /* 
    for(it = v.begin(); it != v.end(); it++){
        if(*it == ";")
            std::cout << "bn" << std::endl;
        else
        {
            std::cout << "all good" << std::endl;
        }
    }    */
    
 



    /*for (it = l.name.begin(); it != l.name.end(); it++)
        std::cout << *it << std::endl; */
    //for(int i = 0; i < l.p.size(); i++)
    //    std::cout << l.p[i] << std::endl;
    //l.print();
        
}