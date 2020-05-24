#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

int& function(std::vector<int> &v, std::vector<int> &v2, int& min, int& max){
    int size = v.size();
    int i = 0; int j = 0;
    int r = 0;
    std::vector<int>::iterator it;
    std::vector<int>::reverse_iterator rit;
    
    for(it = v.begin(); it != (v.begin() + (size / 2 - 1)); ++it){
        v2.push_back(v.at(i));
        i++;
    }
    i = 0;
    for(rit = v.rbegin(); rit != (v.rbegin() + (size / 2)); ++rit){
        v2.at(i) += v.at(j);
        j++; i++;
    }
    min = v2.at(0); max = v2.at(0);
    for(std::vector<int>::iterator i = v2.begin(); i != v2.end(); ++i){
        if(v2.at(r) < min){min = v2.at(r);}
        if(v2.at(r) > max){max = v2.at(r);}
        r++;
    }
    return min, max;
}

int main(){
    std::vector<int> v{2, 15, 7, 0, 11};
    std::vector<int> v2;
    int min, max;
    v.push_back(12);
    v.push_back(8);
    std::cout << function(v, v2, min, max) << std::endl;
}
