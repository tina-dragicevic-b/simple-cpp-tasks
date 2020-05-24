#include <iostream>
#include <algorithm>


/*template < typename T >
bool myIntSort(const T& var, const T& vbr){ return var < vbr; }*/

template < typename T >
void arrSort(T& a){
    int sizeOfArr = *(&a + 1) - a;
    //int sizeOfArr = sizeof(a)/(sizeof(T));        // ovo vraća 1 !!
    //std::cout << sizeof(a)/(sizeof(T)) << std::endl;
    std::sort(a, a + sizeOfArr);
}

template < typename T >
void charSort(T& a){
    // DULJINA CHAR POINTERA
    size_t sizeOfArr = sizeof(a) / sizeof(*a);
    //std::cout << sizeof(a)/(sizeof(*a)) << std::endl;  


    // TEMP je kopija originalnog niza radi kasnije usporedbe
    char temp[sizeOfArr];
    for(int i = 0; i < sizeOfArr; i++){
        temp[i] = a[i];
       // std::cout << temp[i];
    }
    // PROVJARE TEMP-A
    /*for(int i = 0; i < sizeOfArr; i++){
        std::cout << temp[i];
    }*/



    // CHAR *a prebaci u tolower();
    int count = 0;
    for(int i = 0; i < sizeOfArr; i++){
        if(isupper(a[i])) a[i] = tolower(a[i]);
        count++;
    }
    // PROVJERA
    /*for(int i = 0; i < sizeOfArr; i++){
        std::cout << a[i];
    }*/
    std::sort(a, a + sizeOfArr);



    //VRAĆANJE VELIKIH SLOVA; TEMP JE ORIGINALAN STR, a JE SORTIRAN
    if(count > 0){
        for(int i = 0; i < sizeOfArr; i++){
            for(int j = 0; j < sizeOfArr; j++){
                if( a[i] == tolower(temp[j]) && isupper(temp[j]))
                    a[i] = toupper(a[i]);
            }
        }
    }
}

int main(){
   // std::cout << (double)a;
    //std::cout << static_cast<double>(a);


    int a[] = {1,3,1,5,5,71,9,4,4};
    int sizeOfArr = *(&a + 1) - a; 
    //int sizeOfArr = (sizeof(a)/ (sizeof(a[0])));
   /* for(int i = 0; i < sizeOfArr; i++){
        std::cout << a[i] << ' ';
    }*/
    std::cout << "\n";
    arrSort(a);
   /* for(int i = 0; i < sizeOfArr; i++){
        std::cout << a[i] << ' ';
    }*/

    char c[] = {'t', 'I', 'n', 'a'};
    charSort(c);
    int sizeOfCh = *(&c + 1) - c;
    for(int i = 0; i < sizeOfCh; i++){
        std::cout << c[i] << ' ';
    }
}