//TP 2018/2019: ZSR 1, Zadatak 5
#include <iostream>
#include <cmath>

int main ()
{
    double a,b,c;
    const double EPSILON1=0.00001;
    const double EPSILON2=-0.00001;
    std::cout << "Unesite koeficijente kvadratne jednacine: " << std::endl;
    std::cout << "Koeficient a: ";
    std::cin >> a;
    std::cin.ignore(10000,'\n');
    std::cout << "Koeficient b: ";
    std::cin >> b;
    std::cin.ignore(10000,'\n');
    std::cout << "Koeficient c: ";
    std::cin >> c;
    std::cin.ignore(10000,'\n');
    if (a>EPSILON2 && a<EPSILON1 && b>EPSILON2 && b<EPSILON1 && c>EPSILON2 && c<EPSILON1) {
        std::cout << "Jednacina je identicki zadovoljena za svaku vrijednost x";
        return 0;
    }
    if (a>EPSILON2 && a<EPSILON1 && b>EPSILON2 && b<EPSILON1 && (c<EPSILON2 || c>EPSILON1)) {
        std::cout << "Jednacina nema rjesenja.";
        return 0;
    }
    if (a>EPSILON2 && a<EPSILON1) {
        double x_l=-c/b;
        std::cout << "Rjesenje linearne jednacine je " << x_l;
        return 0;
    }
    double d=b*b-4*a*c;
    if (d>0 || (d>EPSILON2 && d<EPSILON1)) {
        double x1_r=(-b+sqrt(d))/2*a;
        double x2_r=(-b-sqrt(d))/2*a;
        std::cout << "Rjesenja kvadratne jednacine su x1=" << x1_r << " i x2=" << x2_r << ".";
        return 0;
    }
    if (d<0) {
        std::cout << "Kompleksna rjesenja kvadratne jednacine su (" << -b/(2*a) << "," << abs(d) << ")";
        std::cout << " i (" << -b/(2*a) << "," << d << ").";
    }
    
	return 0;
}