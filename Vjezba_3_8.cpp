#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>


std::vector<int>& unstuffing_bit(std::vector<int>& modif){
    int flag = 0;
    int len = modif.size();
    for(int i = 0; i < len; i++){
        if(modif[i] == 1){flag++;}
        if(flag == 5){
            //modif.erase(modif.at(i));
            modif.erase(modif.begin() + i + 1);
            flag = 0;
        }
    }  
    return modif; 
}

std::vector<int>& stuffing_bit(std::vector<unsigned int> v, std::vector<int>& modif){
    int flag = 0;
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) == 0){
            modif.push_back(v[i]);
            flag = 0;
        }
        else if(v.at(i) == 1){
            /* if(flag > 1 && v.at(i - 1) == 0){
                flag = 1;
            } */
            if(flag == 5){
                modif.push_back(0);
                modif.push_back(v.at(i));
                flag = 0;
            }
            else{modif.push_back(v[i]);}
            flag++;
        }
    }
    return modif;
}

int main(){
    unsigned int input;
    std::vector<unsigned int> v;
    std::vector<int> modified;
    std::cout << "Unesi binarnu znamenku: ";
    std:: cin >> input;
    v.push_back(input);
    if(input > 1){return -1;}
    while(input < 2){      
        std::cout << "Unesi binarnu znamenku: ";
        std:: cin >> input;
        if(input > 1){break;}       //ulazi u loop s prethodnim unosom; uvjet provjerava trenutni unos; else: sprema znamenku koja je uvjet prekida u vektor
        else{v.push_back(input);}
   }

    for(int i = 0; i < v.size(); i++){
        std::cout << v.at(i);
    }
    std::cout << "\n";
    stuffing_bit(v, modified);
    std::cout << "Modificirani container: \n";
    for(int i = 0; i < modified.size(); i++){
        std::cout << modified.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
    unstuffing_bit(modified);
    std::cout << "Unmodified container: \n";
    for(int i = 0; i < modified.size(); i++){
        std::cout << modified.at(i) << " ";
    }
    return 0;
}