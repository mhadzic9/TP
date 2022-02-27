//TP 2018/2019: Tutorijal 2, Zadatak 4
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> suma;
    for (int i=1; i<=n; i++) {
        double re,im;
        std::complex<double> z;
        std::cout << "R" << i << " = ";
        std::cin >> re;
        std::cout << "X" << i << " = ";
        std::cin >> im;
        std::cout << std::endl;
        z.real(re);
        z.imag(im);
        suma+=1./z;

    }
    suma=1./suma;

    std::cout << "Paralelna veza ovih elemenata ima R = " << suma.real() << " i " << "X = " << suma.imag() << "." << std::endl;


    return 0;
}
