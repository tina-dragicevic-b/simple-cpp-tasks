#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <locale> 

//Napisati funkciju koja iz stringa izbaci svako pojavljivanje podstringa
//koristeći funkcije standardne biblioteke.

void function(std::string& st, std::string sub){
    int pos; // može se definirat i kao size_t pos; definira indeks/poziciju podstringa i ignorira sve prije njega.
    while ((pos = st.find(sub)) != std::string::npos)   //std::string::npos
	{
		st.erase(pos, sub.length());
	}
}

int main(){
    char ch[] = "Tina nema koronavirus, još.vir";
    std::string st(ch);
    std::string sub(st.begin() + 16, st.begin() + 19);
    //std::cout << sub;
    function(st, sub);
    std::cout << st << std::endl;
}