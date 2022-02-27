//TP 2018/2019: ZSR 2, Zadatak 5
#include <iostream>
#include <complex>
#include <iomanip>

int main ()
{
    std::complex<double> z;
    std::cout << "Unesite kompleksan broj z: ";
    std::cin >> z;
    double x,y;
    std::cout << "Unesite realne brojeve x i y: ";
    std::cin >> x >> y;
    std::complex<double> I(0,1);
    std::complex<double> nazivnik=pow(z,3)*sqrt(std::complex<double>(x,-y));
    std::complex<double> izraz=x+((5.*I)/nazivnik);
    std::complex<double> konacno=pow(izraz,2);
    std::cout << konacno;
    
    return 0;
}
