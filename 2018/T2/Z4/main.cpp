//TP 2017/2018: Tutorijal 2, Zadatak 4
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> suma;
    for(int i=0;i<n;i++) {
       double R,X;
       std::complex<double> z;
       std::cout << "R" << i+1 << " = ";
       std::cin >> R;
       std::cout << "X" << i+1 << " = ";
       std::cin >> X;
       std::cout << std::endl;
       z.real(R);
       z.imag(X);
       suma+=1./z;
      
    }
    suma=1./suma;
    std::cout << "Paralelna veza ovih elemenata ima R = " << real(suma) << " i " << "X = " << imag(suma) << ".";
    
	return 0;
}
