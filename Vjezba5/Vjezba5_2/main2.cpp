#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
//#include <algorithm>
//#include <random>
//#include <bits/stdc++.h>
#include "Class_.h"

struct Point{
    double x, y;
    char ch = '*';
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
}Point; 

//void DrawCharUp(struct Point);


void Board::Order(struct Point& p1, struct Point& p2, int a, int b){
    std::cout << "Order" << std::endl;
    if(p1.x > p2.x){
        int temp = p1.x;
        p1.x = p2.x;
        p2.x = temp;
        temp = p1.y;
        p1.y = p2.y;
        p2.y = temp;
    }
    if(p1.x == p1.y && p2.x == p2.y){
        DrawLine_xy_xy(p1, p2, a, b);
    }   
    else if(p1.x == p2.x){
        DrawLine_x_x(p1, p2, a, b);
    }
    else if(p1.y == p2.y){
        DrawLine_y_y(p1, p2, a, b);
    }
    else if(p1.x + p1.y == p2.x + p2.y){
        DrawLine_xppy(p1, p2, a, b);
    }
    else{std::cout << "Improper value\n";}
}

void Board::DrawCharUp(struct Point point, int a, int b){
    std::cout << "\n" << std::endl;
    std::cout << point.x << " " << point.y << std::endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if((i == point.x && j == point.y) || (i < point.x && j == point.y && i != 0)){
                std::cout << point.ch;
            }
            else{std::cout << " ";};
        }
        std::cout << "\n";
    }    
}
 
void Board::DrawLine_xy_xy(struct Point& p1, struct Point& p2, int a, int b){
    std::cout << "\n" << "Draw xy Line" << std::endl;
    std::cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << std::endl;
    struct Point min;
    struct Point Max;
    std::cout << "\n";
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(i == 0 || i == a - 1 || j == 0 || j == b - 1){
                std::cout << c;
            }
            else if(i >= p1.x && i < p2.x && j >= p1.y && j < p2.y && i == j){
                std::cout << p1.ch;
            }
            else{std::cout << ' ';}
        }
        std::cout << '\n';
    }
}

void Board::DrawLine_x_x(struct Point& p1, struct Point& p2, int a, int b){
    std::cout << "\n" << "Draw xx Line" << std::endl;
    std::cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << std::endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(i == 0 || i == a - 1 || j == 0 || j == b - 1){
                std::cout << c;
            }
            else if(j >= p1.y && j < p2.y && i == p1.x){
                std::cout << p1.ch;
            }
            else{std::cout << " ";}
        }
        std::cout << "\n";
    }
}

void Board::DrawLine_y_y(struct Point& p1, struct Point& p2, int a, int b){
    std::cout << "\n" << "Draw yy Line" << std::endl;
    std::cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << std::endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(i == 0 || i == a - 1 || j == 0 || j == b - 1){
                std::cout << c;
            }
            else if(i >= p1.x && i < p2.x && j == p1.y){
                std::cout << p1.ch;
            }
            else{std::cout << " ";}
        }
        std::cout << "\n";
    }

}

void Board::DrawLine_xppy(struct Point& p1, struct Point& p2, int a, int b){
    std::cout << "\n" << "Draw xppy Line" << std::endl;
    std::cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << std::endl;    
    int xx = p1.x; int yy = p1.y;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(i == 0 || i == a - 1 || j == 0 || j == b - 1){
                std::cout << 'o';
            }
            else if(i == xx && j == yy && xx <= p2.x){
                std::cout << p1.ch;
                xx++; yy--;
            }
            else{std::cout << " ";}
        }
        std::cout << "\n";
    }
}

void Sizes(int x, int y, struct Point& r){
    if(x < r.x){
        while(x < r.x){
            r.x = r.x - x;
        }
    }
    if(y < r.y){
        while(y < r.y){
            r.y -= y;
        }
    }
}

int main(){
    std::cout << "main" << std::endl;
    struct Point p;
    struct Point r;
    struct Point p1;
    struct Point p2;
    int *matrix = new int;
    int x = 10;
    int y = 10;
    char c = 'o';
    Board b(matrix, x, y, c);
    b.PrintMtrx(x, y, c);
    //struct Point p;
    p.x = 7.35; p.y = 2.82;
    r.x = 4; r.y = 22.22;

    Sizes(x, y, p);
    Sizes(x, y, r);


    p1.x = 1; p1.y = 5; p2.x = 7; p2.y = 5;

    Sizes(x, y, p1);
    Sizes(x, y, p2);
    
    std::cout << "Point values " << p.x << " " << p.y << std::endl;
    std::cout << "Point values " << r.x << " " << r.y << std::endl;
    //p.drawChar();   // must call draw char to cast double to int
    //r.drawChar();
    //b.DrawCharUp(p, x, y);
    //b.DrawCharUp(r, x, y);

    p1.drawChar();
    //b.DrawCharUp(p1, x, y);

    p2.drawChar();
    //b.DrawCharUp(p2, x, y);
    b.Order(p1, p2, x, y);

    //b.DrawLine_xy_xy(p1, p2, x, y);
    //b.DrawLine_y_y(p1, p2, x, y);

    p1.x = 8; p1.y = 8 ; p2.x = 1; p2.y = 8;
    p1.drawChar();
    p2.drawChar();
    b.Order(p1, p2, x, y);
    //b.DrawLine_x_x(p1, p2, x, y);

    p1.x = 1; p1.y = 4; p2.x = 4; p2.y = 1;
    b.Order(p1, p2, x, y);


    p1.x = 8.22; p1.y = 2 ; p2.x = 8; p2.y = 6.4;
    p1.drawChar();
    p2.drawChar();
    b.Order(p1, p2, x, y);

    p1.x = 4.13; p1.y = 3.79 ; p2.x = 2; p2.y = 2.12;
    p1.drawChar();
    p2.drawChar();
    b.Order(p1, p2, x, y);
    //b.DrawLine_xppy(p1, p2, x, y);
    //b(matrix, x, y);
}