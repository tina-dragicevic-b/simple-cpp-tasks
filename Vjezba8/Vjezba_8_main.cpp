#include <iostream>
#include "Vjezba_8.hpp"
  

int main() {

Money a(4, 16);
Money b(15, 50);
Money c(12,4);          // 12.4 == 12.04!!
Money racun2(0,0);
Money racun1(0,0);
//racun = a + b;

// OPERATOR+= //
racun2 += a;
racun2 += b;
std::cout << racun2.kuna << "," << racun2.lipa << std::endl;


// OPERATOR+ //
racun1 = a + b + c;
std::cout << racun1.kuna << "," << racun1.lipa << std::endl;


// OPERATOR- //
racun1 = b - a;
std::cout << racun1.kuna << "," << racun1.lipa << std::endl;



//std::cout << c.operator+=;
// zadan je jednostavan cjenik
Money juha(11,30), becki(15,50), salata(10,00), pivo(15,00), babic(16,40), nestoNovo(11,45), kupus(4,00);   // kbaž <3
// gost je konzumirao:
Money racun = juha + becki + salata + pivo + nestoNovo + kupus; 
// na zalost nas konobar je nepazljiv pa pivo treba stornirati
racun -= pivo;
// i dodati babic
racun += babic;
//racun -= nestoNovo;
std::cout << racun.kuna << " kuna" << ", " << racun.lipa << " lipa" << std::endl;

Money x(124,3353);
double f = x;
std::cout << f;
return f;

}