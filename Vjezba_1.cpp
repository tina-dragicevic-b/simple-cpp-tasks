#include <iostream>
#include <iomanip>
//using namespace std;

int main(){
    bool flag;
    std::cout << "Unesi" << true << " - " << false << std::endl;
    std::cin >> flag;
    std::cout << std::boolalpha << flag << std::endl;
    std::cout << std::noboolalpha << flag << std::endl;

    int a = 255;
    std::cout << "hex " << std::hex << a << std::endl;
    std::cout << "dec " << std::dec << a << std::endl;
    std::cout << "oct " << std::oct << a << std::endl;

    double pi = 3.141592;
    //std::cout << "pi = " << std::scientific << std::uppercase;
    //std::cout << "pi_ = " << std::scientific << std::nouppercase;
    std::cout << "_pi = " << std::fixed << std::nouppercase; //fixed point, upp/noupp ne pokazuje 'e'..
    std::cout << std::setprecision(7) << std::setw(20) << std::setfill('0');
    std::cout << pi << std::endl;

    //ws\\ 

    //setbase
    std::cout << "\nSetbase" << std::endl;
    std::cout << std::setbase(16);
    std::cout << 16 << std::endl;

    int n = -77;
    std::cout.width(2); 
    std::cout << std::internal << n << '\n';
    std::cout.width(6);
    std::cout << std::left << n << '\n';            //do not understand!!!
    std::cout.width(6);
    std::cout << std::right << n << '\n';
    

    //setfill, setw => include 'iomainp'
    std::cout << std::setfill('o') << std::setw(10);
    std::cout << 7 << std::endl;
    //setw za 10 pozicija 9 prazno, jedna = 7 (in this case)
    //setfill prazne pozicije postavljene pomocu setw ispunjava necim


    std::cout << std::hex;
    std::cout << std::setiosflags;
    std::cout << 3000 << std::endl; //prints an extra '1' on the left...
    std::cout << std::resetiosflags(std::ios::showbase) << 100 << std::endl;


    /*int a, b, s;
    std::cout << "Unesi dva broja" << std::endl;
    std::cin >> a >> b;
    s = a + b;
    std::cout << "Suma je" << s << std::endl;*/
    return 0;
}
