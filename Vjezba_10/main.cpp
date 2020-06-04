#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

class output{
    int n; 
    public:
    output() : n(0) {}
    void operator() (int vectorElement){ n = vectorElement; }
    operator int() { return n; }
};

class GT500{
    int greaterThan500;
    public:
    GT500() : greaterThan500(0) {}
    void operator() (int vectorElement) {
        if(vectorElement > 500){ greaterThan500++;} 
    }
    operator int() { return greaterThan500; }

};

/*int lessThan300(int vectorElement){
    if(vectorElement >= 300) return vectorElement;
    return 0;
}

void eraseZero(int vectorElement){
    if(vectorElement == 0) operator delete(vectorElement);
}

class lessThan300{
    int limit;
    int el;
    public:
    lessThan300(int limit) : limit(limit), el(0) {}
    void operator() (int vectEl) { if(vectEl > limit) el = vectEl; }
    operator int(el) { return el; }
};*/

class sortVec{
    public:
    bool operator() (const int& a, const int& b) { return a > b; }
};
int main()
{
    std::vector<int> v;
    try{
        std::ifstream f("numbers.txt");    // ako stavim krivi naziv fajla; kompajla se, ali bez privaje greške
        std::istream_iterator<int> is(f), eos;
        std::copy(is, eos, std::back_inserter(v));
    }
    catch(std::exception const& e){
        std::cout << "Error opening file " << e.what() << std::endl;
    }
   
    // radimo nesto s vektorom 
    
    //std::ostream_iterator<int> os(std::cout, ",");
    //std::copy(v.begin(), v.end(), os);

    //TEST
    /*for(int i = 0; i < v.size(); i++){
        std::cout << v.at(i) << " ___ "; }*/
    // std::cout << for_each(v.begin(), v.end(), output()); //ispisuje samo zadnji broj '273' 

    // count brojeva većih od 500:
    std::cout << "Broj elemenata većih od 500 ima " << std::for_each(v.begin(), v.end(), GT500()) << std::endl;
    
    // min and max element:
    std::cout << "Min element je " << *min_element(v.begin(), v.end()) << std::endl;
    std::cout << "Max element je " << *max_element(v.begin(), v.end()) << std::endl;

    // iz vektora izbaci el manje od 300; !koristi drugi vektor!
    std::vector<int> newVect;
   /* std::transform(v.begin(), v.end(), std::back_inserter(newVect), lessThan300);
    std::for_each(newVect.begin(), newVect.end(), eraseZero);

    std::transform(v.begin(), v.end(), std::back_inserter(newVect), lessThan300(300));*/

    newVect = v;
    for(int i = 0; i < 300; i++){
        newVect.erase(remove(newVect.begin(), newVect.end(), i), newVect.end());
    }
    std::ostream_iterator<int> os(std::cout, ",");
    //std::copy(newVect.begin(), newVect.end(), os);
    std::cout << "Broj nexVect elemenata " << newVect.size() << std::endl;

    // sortiraj newVect silazno
    std::sort(newVect.begin(), newVect.end(), sortVec());
    std::copy(newVect.begin(), newVect.end(), os);
}
