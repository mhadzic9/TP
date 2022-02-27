//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>

int main ()
{
    int i,suma;
    float n;
    const double EPSILON1=0.0001;
    const double EPSILON2=-0.0001;
    for (;;) {
        std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        std::cin >> n;
        suma=0;
        while (!(std::cin) || n<0 || (floor(n)-ceil(n)<0)) {
            std::cout << "Niste unijeli prirodan broj!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
            std::cin >> n;
        }
        if (n+0>EPSILON2 && n+0<EPSILON1) {
            std::cout << "Dovidjenja!" << std::endl;
            break;
        }
        int broj=int(n);
        for (i=1;i<n;i++) {
            if (broj%i==0) {
                suma+=i;
            }
        }
        if (suma<n) {
            std::cout << "Broj " << n << " je manjkav!" << std::endl;
        }
        if (suma>n) {
            std::cout << "Broj " << n << " je obilan!" << std::endl;
        }
        if (suma-n>EPSILON2 && suma-n<EPSILON1) {
            std::cout << "Broj " << n << " je savrsen!" << std::endl;
        }
    }
	return 0;
}