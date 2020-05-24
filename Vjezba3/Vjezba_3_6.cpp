#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <list>
#include <iterator>

/*Napisati funkciju koja u listu prirodnih brojeva ispred svakog parnog
broja umetne nulu, a iza svakog neparnog broja osim jedinice umetne
jedinicu. Funkcija vraća broj elemenata između prve nule u listi i zadnje
jedinice. U main funkciji generirati listu, pozvati funkciju, ispisati listu
i povratnu vrijednost funkcije.*/


unsigned int function(std::list<unsigned int> l, std::list<unsigned int>& n){
    std::list<unsigned int>::iterator it;
    std::list<unsigned int>::iterator nit = n.begin();
    std::list<unsigned int>::reverse_iterator rit = l.rbegin();
    unsigned int start;
    unsigned int end; int i = 0;
    for(it = l.begin(); it != l.end(); it++){
        if(*it % 2 == 0){
            n.insert(nit, 0);
            n.insert((++nit), (*it));
        }
        else if(*it %2 == 1 && *it != 1){
            n.insert(nit, (*it));
            n.insert(++nit, 1);
        }
        nit++;
        nit++;
    }
    while((*it) != 0){
        it++;
        i++;
        if((*it) == 0){start = i; break;}
    }
    i = 0;
    while((*rit) != 1){
        rit++;
        i++;
        if((*rit) == 1){
            end = i; break;}
        
    }
    return abs(end - start);
}

int main(){
    std::list<unsigned int> lista;
    std::list<unsigned int> new_;
    unsigned int a;
    for(int i = 0; i < 10; i++){
        std::cout << "Unesi broj: \t";
        std:: cin >> a;
        lista.push_back(a);
    }
    std::list<unsigned int>::iterator it = lista.begin();
    std::cout << "\n";
    std::cout << "Lista: ";
    for(it; it != lista.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Broj elemenata između prve 0 i zadnje 1 je: " << function(lista, new_);
    std::cout << "\n";
    std::cout << "Nova lista: ";
    for(it = new_.begin(); it != new_.end(); it++){
        std::cout << *it << " ";
    }
    
}   
