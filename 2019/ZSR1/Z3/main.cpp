//TP 2018/2019: ZSR 1, Zadatak 3
#include <iostream>

int main ()
{
    double broj;
    const double EPSILON1=0.0001;
    const double EPSILON2=-0.0001;
    std::cout << "Unesite neki broj: ";
    std::cin >> broj;
    if (!std::cin) {
        std::cout << "Uneseni podatak nije broj.";
        return 0;
    }
    if (broj-int(broj)>EPSILON2 && broj-int(broj)<EPSILON1 && broj>EPSILON1) {
        std::cout << "Uneseni podatak je prirodan broj.";
        return 0;
    }
    if (broj-int(broj)>EPSILON2 && broj-int(broj)<EPSILON1 && (broj<0 || (broj>EPSILON2 && broj<EPSILON1))) {
        std::cout << "Uneseni podatak je cijeli broj, ali nije prirodan.";
        return 0;
    }
    if (broj-int(broj)<EPSILON2 || broj-int(broj)>EPSILON1) {
        std::cout << "Uneseni podatak je realan broj, ali nije cijeli.";
    }
    
	return 0;
}