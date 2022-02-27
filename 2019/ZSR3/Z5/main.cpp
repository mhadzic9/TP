//TP 2018/2019: ZSR 3, Zadatak 5
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

double Korijeni (std::vector<double> v) {
    double korijen=0,suma=0,clan=0;
    for (int i=v.size()-1;i>0;i--) {
        if (v.at(i)<0) throw std::range_error ("Ne valja.");
        korijen=sqrt(v.at(i)+sqrt(clan));
        clan=korijen;
        suma+=korijen
    }
  return sqrt(korijen);
}

int main ()
{
    std::vector<double> v;
    std::cout << "Unesite broj elemenata vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    int a;
    do {
        std::cin >> a;
        v.push_back(a);
    } while (v.size()<n);
    double suma=Korijeni(v);
    std::cout << suma;
    
	return 0;
}