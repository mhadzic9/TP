//TP 2018/2019: ZSR 1, Zadatak 6
#include <iostream>

int main ()
{
    double a,b,c;
    const double EPSILON1=0.00001;
    const double EPSILON2=-0.00001;
    std::cout << "Unesite duzine stranica a,b i c: ";
    std::cin >> a >> b >> c;
    if ((a+b>c && a+c>b && b+c>a) && ((a*a+b*b-c*c>EPSILON2 && a*a+b*b-c*c<EPSILON1) || (a*a+c*c-b*b>EPSILON2 && a*a+c*c-b*b<EPSILON1) || (b*b+c*c-a*a>EPSILON2 && b*b+c*c-a*a<EPSILON1))) {
        std::cout << "Sa unesenim stranicama moze se formirati pravougli trokut.";
        return 0;
    }
    else {
        std::cout << "Sa unesenim stranicama ne moze se formirati pravougli trokut!";
    }
    
	return 0;
}