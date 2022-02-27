//TP 2017/2018: Tutorijal 2, Zadatak 5
#include <iostream>
#include <cmath>
#include <complex>

int main ()
{
    int n;
    const double PI=4*atan(1);
    std::cout << "Unesi broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex <double> suma;
    for(int i=0;i<n;i++) {
        std::complex<double> z;
        double r,fi;
        std::cout << "Z" << i+1 << " = ";
        std::cin >> r;
        std::cout << "fi" << i+1 << " = ";
        std::cin >> fi;
        z.real(cos(fi*(PI/180.)));
        z.imag(sin(fi*(PI/180.)));
        z*=r;
        suma+=1./z;
        std::cout << std::endl;
    }
    std::complex<double> s=1./suma;
    std::cout << "Paralelna veza ovih elemenata ima Z = " << abs(s) << " i fi = " << std::arg(s)*(180./PI) << ".";
	return 0;
}
