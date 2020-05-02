#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <locale> 

//Napisati funkciju koja izmiješa riječi u rečenici u inverznom poredku.
//Točka mora ostati na kraju rečenice, prva riječ mora biti napisana velikim 
//početnim slovom, a zadnja malim. Koristiti reverse funkciju.

std::string& Rev(std::string &ST_r, std::string &new_str, int a){
    //char c[100];
    //std::cout << "\n novi " << new_str << std::endl;
    int i = 0; int j = 0; int k = i;
    while(j != a - 1){       // 'x' = char; "x" = const char* !!!
        new_str.at(i) = ST_r.at(i);
        i++;
        j++;
        if(ST_r.at(i) == '.'){
            std::reverse((new_str.begin() + k), new_str.end() - 1);
        }
        if(ST_r.at(i) == ' '){
            if(new_str.at(i - 1) == ','){
                std::reverse((new_str.begin() + k), new_str.end() - 1);}       //do kraja bez razmaka i točke/zareza
            else{
                std::reverse((new_str.begin() + k), new_str.end());}    //do kraja bez razmaka.
            k = i;
            i = 0;
        }
    }
    std::toupper(new_str.at(0));
    return new_str;
}

int main(){
    const char C_string[] = "Tina nema koronavirus, još."; 
    int a = strlen(C_string);
    //std::cout << "\n strlen" << a << std::endl;
    std::string ST_r(C_string);
    //std::cout << ST_r << std::endl;
    std::string new_str;
    //const int size_ = ST_r.size();
    Rev(ST_r, new_str, a);
    std::cout << new_str << std::endl;

}