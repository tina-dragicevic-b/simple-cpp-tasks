#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include "book.hpp"

Book::Book(){}
Book::Book(std::string name, std::string book){
    this->name = name;
    this-> book = book;
    //this-> year = year;
}

/* 
void Book::print(){
    std::cout << "Book" << std::endl;
} */
//Book::~Book(){}
/* 
Library::Library(const Book* b){
    std::cout << "Lib" << std::endl;
    p.push_back(new Book());
    for(int i = 0; i < p.size(); i++){
        std::cout << "Library " << &(p[i]);
    }
} */



void Library::Funk(std::vector<std::string> v, std::string c){
    std::string::iterator it = c.begin();
    int count = 0;
    std::string a = "";
    //std::cout << *it << " " << std::endl;
    for (int i = 0; i < c.size(); i++){
        //std::cout << c[i] << std::endl;
        if(c[i] != ';'){
            a += c[i];
        }
        else if(c[i] == ';'){
            count ++;
            if(count == 1){
                //std::cout << " aaa " << a << std::endl;
                name = a;
                //std::cout << " name " << name << std::endl;
                a = "";
            }
            else if(count == 2){
                //std::cout << " bbbb " << a << std::endl;
                book = a;
                //std::cout << " book " << book << std::endl;
                a = "";
            }
            else if((count == 2 || count == 3) && a[i - 1] == 'M' && a[i] == 'B'){
                SizeMB += a;
            } 
            else if((count == 2 || count == 3) && isdigit(a[i])){
                NumbOfPages += a;
            }
        }
       // p.push_back(new Book(name, book));      
    }
    p.push_back(new Book(name, book));
    
    //std::cout << " name " << name << std::endl;
   // std::cout << " book " << book << std::endl;    
} 

void Library::print(){
    for(std::vector<Book*>::iterator it = p.begin(); it != p.end(); it++){
        std::cout << (*it)->name << (*it)->book << std::endl;
    }
}

Library::~Library(){
    std::cout << "dest" << std::endl;
    for(int i = 0;  i < p.size(); i++){
       // delete p.at(i);
       // delete p[i];
       p.erase(p.begin() + i);
    }
    p.clear();
}   