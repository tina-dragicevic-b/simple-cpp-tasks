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
    this-> year = 0;
}


void Book::print(){
    std::cout << " name " <<  name << std::endl;
    std::cout << " book " <<  book << std::endl;
    std::cout << " year " <<  year << std::endl;
} 


//Book::~Book(){}
/* 
Library::Library(const Book* b){
    std::cout << "Lib" << std::endl;
    p.push_back(new Book());
    for(int i = 0; i < p.size(); i++){
        std::cout << "Library " << &(p[i]);
    }
} */



/* 
void Library::Funk(std::string c){
    std::string::iterator it = c.begin();
    int count = 0;
    std::string a = "";


    int hc = 0, eb = 0;
    std::string reverse = "";
    std::string catchString = "";

    
    for (std::string::iterator it = c.begin(); it != c.end(); it++){
        
        if(*it != ';'){
            a += *it;
        }
        else{
            count ++;
            if(count == 1){
                //std::cout << " aaa " << a << std::endl;
                name = a;
                //std::cout << " name " << name << std::endl;
                a = "";
            }
            else if(count == 2 && isdigit(*it + 2)){
                //std::cout << " bbbb " << a << std::endl;
                book = a;
                //std::cout << " book " << book << std::endl;
                a = "";
                hc++;
            }
            else if(count == 2 && isalpha(*it + 2)){
                eb++;
            }
            
            else if(count == 3){
                book = a;
                a = "";
            }
        }
        if(hc == 1){
            catchString += a;
            a = "";
            p.push_back(new HardCopyBook(name, book, catchString));
        } 
        else if(eb == 1){
            catchString += a;
            a = "";
            p.push_back(new EBook(name, book, catchString));
        }    
    }
    print();
} */


void HardCopyBook::print(){
   /* std::cout << " name " <<  name << std::endl;
    std::cout << " book " <<  book << std::endl;
    std::cout << " year " <<  year << std::endl;*/
    std::cout << " numb of pages " << NumbOfPages << std::endl;
} 

void EBook::print(){
   /* std::cout << " name " <<  name << std::endl;
    std::cout << " book " <<  book << std::endl;
    std::cout << " year " <<  year << std::endl;*/
    std::cout << " size of book " << SizeMB << std::endl;
} 


void Library::libre(Book* b){
    p.push_back(b);
}

void Library::print(){
    for(unsigned int i = 0; i < p.size(); i++){
        p[i]->print();
    }
}


/*
std::string& Library::HCE(std::string c){
    int count1 = 0;
    std::string reverse = "";
    std::string catchString = "";
    std:: cout << p[0];
    for(std::string::reverse_iterator it = c.rbegin(); *it != ' '; it++){
        if(isalpha(*it)){
            count1 ++;
        catchString += *it;
    }
    std::cout << " count1 " << count1 << std::endl;
    for(int i = catchString.size(); i > 0; i--)
        reverse += catchString[i];
    /* if(count > 0){
        EB->num += reverse;
        //std::cout << EB->num;
        //p.push_back(new Book(num));
        }
    else{
        HC->num += reverse;
        //std::cout << HC->num;
        //p.push_back(num);}
    } 
    
    }
    return num;
}
*/

Library::~Library(){
    std::cout << "dest" << std::endl;
    for(int i = 0;  i < p.size(); i++){
       // delete p.at(i);
       // delete p[i];
       p.erase(p.begin() + i);
    }
    p.clear();
}    


void Funk(std::string& c, Library& lib){
   std::string::iterator it = c.begin();
    int count = 0;
    std::string a = "";
    std::string name = "";
    std::string book = "";
    std::string catchString = "";
    int hc = 0, eb = 0;

    
    for (std::string::iterator it = c.begin(); it != c.end(); it++){
        
        if(*it != ';'){
            a += *it;
        }
        else{
            count ++;
            if(count == 1){
                //std::cout << " aaa " << a << std::endl;
                name = a;
                //std::cout << " name " << name << std::endl;
                a = "";
            }

            if(count == 2 || count == 3){
                book = a;
                a = "";
                lib.libre(new Book(name, book));
            }

            if(isdigit(*it)){
                if(count == 2){
                    lib.libre(new HardCopyBook(a));
                }
                else
                {
                    lib.libre(new EBook(a));
                }
                
            }
          /*  else if(count == 2 && isdigit(*it + 2)){
               // std::cout << " bbbb " << a << std::endl;
                book = a;
               // std::cout << " book " << book << std::endl;
                a = "";
                hc++;
                lib.libre(new Book(name, book));
            }
            else if(count == 2 && isalpha(*it + 2)){
                eb++;
            }
            
            else if(count == 3){
               // std::cout << " ccc " << a << std::endl;
                book = a;
                //std:: cout << " Ebook " << book << std::endl;
                a = "";
                lib.libre(new Book(name, book));
            }  */
            //lib.libre(new Book(name, book));
        }
        if(hc == 1){
            catchString += a;
            a = "";
            //std::cout << "catchString hc " << catchString << std::endl;
            lib.libre(new HardCopyBook(catchString));
        } 
        else if(eb == 1){
            catchString += a;
           // std::cout << "catchString eb " << catchString << std::endl;
            a = "";
            lib.libre(new EBook(catchString));
        }    
    }
    //lib.print();
}