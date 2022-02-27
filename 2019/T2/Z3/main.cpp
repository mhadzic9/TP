//TP 2018/2019: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> suma;
    for (int i=1;i<=n;i++) {
        std::cout << "Z_" << i << " = ";
        std::complex<double> z;
        std::cin >> z;
        suma+=1./z;
        
    }
    suma=1./suma;
    std::cout << "\nParalelna veza ovih elemenata ima impedansu Z_ = " << suma << "." << std::endl;
    
    
	return 0;
}