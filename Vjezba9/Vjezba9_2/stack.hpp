#include <iostream>
#include <vector>

template <typename T>

class stack{
    protected:
    std::vector<T> vec;
    T var;
    public:
    stack(std::vector<T> a, T var);
    //stack(){};
    void push(T var, std::vector<T>& v);
    void pop(std::vector<T>& v);
    void is_empty(std::vector<T>& vec);
    ~stack(){}
};


template <typename T>
stack<T>::stack(std::vector<T> vec, T var) : vec(0), var(0) {}
//stack<T>::stack(){}

template <typename T>
void stack<T>::push(T var, std::vector<T>& v){
    v.push_back(var);
}

template <typename T>

void stack<T>::pop(std::vector<T>& v){
    for(int i = 0; i <= v.size(); i++)
        v.pop_back();
    //v.pop_back();
}

template <typename T>
void stack<T>::is_empty(std::vector<T>& vec){
    if(vec.empty()) std::cout << "Empty" << std::endl;
    else std::cout << "Not Empty" << std::endl;

}

/*template <typename T>
stack<T>::~stack(){}*/