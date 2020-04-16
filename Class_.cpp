#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
//#include <algorithm>
//#include <random>
//#include <bits/stdc++.h>
#include "Class_.h"

/* 
struct Point{
    double x, y;
    char ch = 'o';
    //Point(double x, double y) : x(x), y(y) {};
    void drawChar(){
        std::cout << "draw char" << std::endl;
        x = int(x + 0.5); y = int(y + 0.5);
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                if(i == (int)x && (int)j == y){
                    std::cout << ch;
                }
                else{std::cout << '-';}
            }
            std::cout << "\n";
        }
    }
}Point;   */

Board::Board(){
    std::cout << "default" << std::endl;
}

Board::Board(int *M, int& a, int& b, char& c){
    std::cout << "const" << std::endl;
    this->c = 'o';
    M = new int[a * b];
    for(int i = 0; i < (a); i++){
        for(int j = 0; j < b; j++){
            M[i * j] = 0;
        }
        //std::cout << M[i] << std::endl;
    }
}

int Board::PrintMtrx(int a, int b, char c){
    std::cout << "Print matrix" << std::endl;
    //std::cout << a << b << c << std::endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(i == 0 || i == a - 1 || j == 0 || j == b - 1){
                std:: cout << c;
            }
            else{std::cout << " ";}
        }
        std::cout << "\n";
    } 
    return 0;
}

Board::Board(const Board& B2) : a(B2.a), b(B2.b), M(B2.M), c(B2.c) {}

Board::~Board(){
    std::cout << "dest" << std::endl;
    delete [] M;
}

void drawChar(double x, double y, char ch){
        std::cout << "draw char" << std::endl;
        x = int(x + 0.5); y = int(y + 0.5);
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                if(i == (int)x && (int)j == y){
                    std::cout << ch;
                }
                else{std::cout << '-';}
            }
            std::cout << "\n";
        }
    }

