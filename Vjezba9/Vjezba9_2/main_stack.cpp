#include <iostream>
#include "stack.hpp"
#include <vector>

int main(){

    std::vector<double> vec;             // change type 1/3
    int a;
    std::cout << "Unesi broj elemenata ";
    std::cin >> a;
    //stack<int>newElement(vec);
    stack<double> newElemant(vec, 0);    // change type 2/3
    for(int i = 0; i < a; i++){
        double input;                   // change type 3/3
        std::cout << "Unesi " << i << ". element: ";
        std::cin >> input;
        newElemant.push(input, vec);
    }
    newElemant.is_empty(vec);
    for(int i = 0; i < a; i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << "\n";
    newElemant.pop(vec);
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i];
    }
    newElemant.is_empty(vec);
}