#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
//#include "Struct.h"
//#include <algorithm>
//#include <random>
//#include <bits/stdc++.h>

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

#ifndef _Board
#define _Board

class Board{
    int a, b;
    int *M = new int;
    char c;
    public:
    Board();
    Board(int *M, int& a, int& b, char& c);
    void DrawCharUp(struct Point p, int a, int b);
    void Order(struct Point& p1, struct Point& p2, int a, int b);
    void DrawLine_xy_xy(struct Point& p1, struct Point& p2, int a, int b);
    void DrawLine_y_y(struct Point& p1, struct Point& p2, int a, int b);
    void DrawLine_x_x(struct Point& p1, struct Point& p2, int a, int b);
    void DrawLine_xppy(struct Point& p1, struct Point& p2, int a, int b);
    int PrintMtrx(int a, int b, char c);
    Board(const Board& B2);     //cpy konstruktor prima referencu na drugi obj istog tipa;
    ~Board();
};
/* 
void Board::DrawCharUp(struct Point p){

} */

#endif