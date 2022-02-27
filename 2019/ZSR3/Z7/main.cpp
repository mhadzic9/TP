//TP 2018/2019: ZSR 3, Zadatak 7
#include <iostream>
#include <vector>

double Razlomak (std::vector<double> v) {
    double suma=0,rezultat=0;
    while (v.size()!=0) {
        double proizvod=1;
        for (int i=0;i<v.size();i++) {
            proizvod*=v.at(i);
        }
        rezultat+=1./proizvod;
        v.resize(v.size()-1);
    }
    return rezultat;
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
    double suma=Razlomak(v);
    std::cout << suma;

    
	return 0;
}