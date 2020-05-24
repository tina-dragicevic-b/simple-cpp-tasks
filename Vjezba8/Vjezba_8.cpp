#include <iostream>
#include "Vjezba_8.hpp"



// OPERATOR- //
Money Money::operator-(const Money& a){
    
    if(this->lipa < a.lipa){
        //std::cout << "Tu sam   ";
        lipa += 100;
        kuna -= 1;
        return Money(kuna - a.kuna, lipa - a.lipa);
    }
    return Money(kuna - a.kuna, lipa - a.lipa);
}


// OPERATOR+ //
Money Money::operator+(const Money& a){
    if( (this->lipa + a.lipa) > 99){
        //std::cout << " this lipa " << lipa << std::endl;
        this->lipa = (this->lipa + a.lipa) % 100 ;
        this->kuna = ( this->kuna + a.kuna ) + (( this->lipa + a.lipa ) / 100 );
        //std::cout << " this lipa " << lipa << std::endl;
        return Money(kuna, lipa);
    
    }
    return Money(kuna + a.kuna, lipa + a.lipa);
}

// OPERATOR+= //
Money Money::operator+=(Money a){
    this->kuna += a.kuna;
    this->lipa += a.lipa;
    if(lipa / 100 > 0){
        this->kuna += ( lipa / 100 );
        lipa = ( lipa % 100 );
    }
    //std::cout << kuna << "," << lipa << std::endl;
    return a;
}

// OPERATOR-= //
Money Money::operator-=(Money a){
    if(this->lipa < a.lipa){
        this->lipa += 10;
        this->kuna -= 1;
        this->kuna -= a.kuna;
        this->lipa -= a.lipa;
        return Money(kuna, lipa);
    }
    return Money(kuna -= a.kuna, lipa -= a.lipa);
}
