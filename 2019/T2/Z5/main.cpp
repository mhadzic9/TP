//TP 2018/2019: Tutorijal 2, Zadatak 5
#include <iostream>
#include <cmath>
#include <complex>

int main ()
{
    int n;
    const double PI=4*atan(1);
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> suma;
    for (int i=1;i<=n;i++) {
        std::complex<double> z;
        double z1,fi;
        std::cout << "Z" << i << " = ";
        std::cin >> z1;
        std::cout << "fi" << i << " = ";
        std::cin >> fi;
        std::cout << std::endl;
        z=std::polar(z1,fi*(PI/180));
        suma+=1./z;
        
    }
    suma=1./suma;
    std::cout << "Paralelna veza ovih elemenata ima Z = " << abs(suma) << " i fi = " << std::arg(suma)*180./PI << "." << std::endl; 
    
	return 0;
}