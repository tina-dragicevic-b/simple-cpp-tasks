/* #include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <vector>

class Book{
    protected:
    std::string name;
    std::string book;
    int year;
    public:
    Book() {}
    virtual void print(){std::cout << "Book" << std::endl;}
    virtual ~Book();
};


Book::~Book(){}

class HardCopyBook : public Book{
    protected:
    unsigned int NumbOfPages;
    public:
    HardCopyBook(){}
    void print(){std::cout << "HCBook" << std::endl;}
    ~HardCopyBook(){}
};

class EBook : public Book{
    protected:
    unsigned int SizeMB;
    public:
    EBook(){}
    void print(){std::cout << "EBook" << std::endl;}
    ~EBook(){}
};

#ifndef _Library
#define _Library

class Library : public Book{
    std::vector<Book*> p;
    public:
    Library();
    ~Library();
};

#endif */