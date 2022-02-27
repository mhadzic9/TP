//TP 2018/2019: ZSR 1, Zadatak 12
#include <iostream>

int main ()
{
    int predznak=-1,n;
    double x,suma=0,clan;
    std::cout << "Unesite broj x: ";
    std::cin >> x;
    std::cout << "Unesite broj n: ";
    std::cin >> n;
    for (int i=1;i<=n;i++) {
        clan=predznak/(x*(x+i));
        suma+=clan;
        predznak=-predznak;
    }
    std::cout << "Suma je " << suma;
    
	return 0;
}