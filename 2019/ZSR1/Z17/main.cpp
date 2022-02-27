//TP 2018/2019: ZSR 1, Zadatak 17
#include <iostream>
#include <iomanip>

int UnesiBroj() {
    double n;
    const double EPSILON1=0.00001;
    const double EPSILON2=-0.00001;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    while ((!std::cin) || (n-int(n)>EPSILON2 && n-int(n)<EPSILON1)) {
        std::cout << "Neispravan unos. Molimo, pokušajte ponovo:" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> n;
        }
    return n;
}

int main ()
{
    double a=UnesiBroj();
    double b=UnesiBroj();
    double c=UnesiBroj();
    double x;
    x=(c-b)/a;
    std::cout << "Rjesenje lineardne jednacine je " << x;
    
	return 0;
}