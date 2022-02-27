//TP 2017/2018: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> suma;
    for(int i=0; i<n; i++) {
        std::complex<double> z;
        std::cout << "Z_" << i+1 << " = ";
        std::cin >> z;
        suma+=1./z;
    }
    suma=1./suma;
    std::cout << "\nParalelna veza ovih elemenata ima impedansu Z_ = (" << (real(suma)) << "," << (imag(suma)) << ")." << std::endl;

    return 0;
}
