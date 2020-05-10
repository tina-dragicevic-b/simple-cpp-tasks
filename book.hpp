#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <vector>



class Book{
    //protected:
    public:
    std::string name;
    std::string book;
    int year;
    public:
    Book();
    Book(std::string name, std::string book);
    virtual void print() {}//{std::cout << "Book" << std::endl;std::cout << year << std::endl;}
   // void Funk(std::vector<std::string> v, std::string c);
    virtual ~Book(){std::cout << "Virtual dest" << std::endl;}  //= 0;
};

//Book::~Book(){}


class HardCopyBook : public Book{
    protected:
    std::string NumbOfPages;
    public:
    HardCopyBook(){}
    void print(){std::cout << "HCBook" << std::endl;}
    ~HardCopyBook(){}
};

class EBook : public HardCopyBook{
    protected:
    std::string SizeMB;
    public:
    EBook(){}
    void print(){std::cout << "EBook" << std::endl;}
    ~EBook(){}
};

#ifndef _Library
#define _Library

class Library : public EBook{
    protected:
    std::vector<Book*> p;
    Book * arr [];
    public:
    Library(){};
    //Library(const Book* b);
    std::string BookAuthor();
    void Funk(std::vector<std::string> v, std::string c);
    void print();
    unsigned int SizeOfBooks();
    std::string StringInBook();
    ~Library();
};

#endif