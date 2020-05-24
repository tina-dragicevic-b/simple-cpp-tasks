#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <vector>

#ifndef _Book
#define _Book

class Book{
    //protected:
    public:
    std::string name;
    std::string book;
    int year;
    //std::string num;
    public:
    Book();
    Book(std::string name, std::string book);
    virtual void print(); //{std::cout << "Book" << std::endl;std::cout << year << std::endl;}
   // void Funk(std::vector<std::string> v, std::string c);
    virtual ~Book(){std::cout << "Virtual dest" << std::endl;}  //= 0;
};

#endif
//Book::~Book(){}


#ifndef _HardCopyBook
#define _HardCopyBook

class HardCopyBook : public Book{
    protected:
    std::string NumbOfPages;
    public:
    HardCopyBook(std::string velicina) : Book(name, book) {}
    //HardCopyBook(std::string x){NumbOfPages = x;}
    virtual void print();//{std::cout << "HCBook" << std::endl;}
    ~HardCopyBook(){}
};

#endif

#ifndef _EBook
#define _EBook

class EBook : public Book{
    protected:
    std::string SizeMB;
    public:
    EBook(std::string velicina) : Book(name, book) , SizeMB(SizeMB){}
    //EBook(std::string x){SizeMB = x;}
    virtual void print();//{std::cout << "EBook" << std::endl;}
    ~EBook(){}
};

#endif

#ifndef _Library
#define _Library

class Library : public Book{
    protected:
    std::vector<Book*> p;

    public:
    Library(){};
    //std::string BookAuthor();
    void libre(Book* b);
    //void Funk(std::string c);
    void print();

    //unsigned int SizeOfBooks();
    //std::string StringInBook();
    ~Library();
};

#endif

void Funk(std::string& v, Library& lib);