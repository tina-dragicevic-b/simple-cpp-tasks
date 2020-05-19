#include <iostream>


class Money{
    public:
    unsigned int kuna;
    int lipa;
    unsigned int racun;
    public:
    explicit Money(int a, int b) : kuna(a), lipa(b) {}
    Money operator+=(Money a);
    Money operator-=(Money a);
    Money operator-(const Money& a);
    Money operator+(const Money& a);
    operator double() { return double(kuna) / double(lipa);}
};

