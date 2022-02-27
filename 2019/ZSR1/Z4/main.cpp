//TP 2018/2019: ZSR 1, Zadatak 4
#include <iostream>

int main ()
{
    int sati;
    std::cout << "Unesite broj sati: ";
    std::cin >> sati;
    double pretplata1,pretplata2;
    pretplata1=10+sati*0.5;
    pretplata2=sati*0.8;
    if (pretplata1>pretplata2) {
        std::cout << "Isplatnija je druga pretplata.";
        return 0;
    }
    else {
        std::cout << "Isplatnija je prva pretplata.";
    }
    
	return 0;
}