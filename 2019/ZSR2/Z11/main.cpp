//TP 2018/2019: ZSR 2, Zadatak 11
#include <iostream>
#include <vector>

std::vector<double> Vektor (double niz[],int velicina) {
    std::vector<double> v;
    for (int i=0;i<velicina;i++) {
        v.push_back(niz[i]);
    }
    std::vector<double> v1;
    for (int i=v.size()-1;i>=0;i--) {
        v1.push_back(v.at(i));
    }
    return v1;
}

int main ()
{
    double niz[10];
    std::vector<double> v;
    std::cout << "Unesite elemente niza: ";
    for (int i=0;i<10;i++) {
        std::cout << "Element " << i+1 << ". " << std::endl;
        std::cin >> niz[i];
    }
    v= Vektor(niz,10);
    for (double x:v) {
        std::cout << x << " ";
    }
    
	return 0;
}