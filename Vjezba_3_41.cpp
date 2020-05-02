#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <locale> 

//Napisati funkciju koja vraća najduži zajednički podstring u dva stringa.

std::string function(std::string st, std::string ts, int a, int b, std::string& novi){
    if(st.empty() || ts.empty()){return 0;}
    int* current = new int [ts.size()];
    int* previous = new int [ts.size()];
    int* temp = 0;

    int maxSub = 0;
    std::string longest;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(st.at(i) != ts.at(j)){current[j] = 0;}
            else{
                if(i == 0 || j == 0){current[j] = 1;}
                else{current[j] = previous[j - 1] + 1;}
                if(maxSub < current[j]){
                    maxSub = current[j];
                    longest.clear();
                }
                if(maxSub == current[j]){longest += st.substr(i - maxSub + 1, i + 1);}
            }
        }
        temp = current;
        current = previous;
        previous = temp;
    }
    delete [] current;
    delete [] previous;
    return longest.substr(0, maxSub);


}

int main(){
    std::string st = "Tina nema koronavirus, još.";
    //std::cout << st << std::endl;
    std::string ts = "Tina nije zarazena koronavirusom.";
    int a = st.size();
    int b = ts.size();
    std::string novi;
    function(st, ts, a, b, novi);
    //std::cout << "a = " << a << "\n" << "b = " << b;
    std::cout << novi;
}


/* std::string& function(std::string st, std::string ts, int a, int b, std::string& novi){
    int i = 0; int j = 0;
    if(st.empty() || ts.empty()){return;}

    while(i < a || j < b){
        if(st.at(i) == ts.at(j)){
            novi.push_back(st.at(i));
            i++; j++;
        }
        else if(st.at(i) != ts.at(j)){

        }
    }  
    int n = 0; int m = 0;
    while(i < a){
        while(j < b){
            if(st.at(i) == ts.at(j)){
                novi.push_back(st.at(i));
                j++; i++;
            }
            else if(st.at(i) != ts.at(j)){
                j++;
            }
            j = 0;
        }
        i++;
    } 

    return novi;
}
 */ 