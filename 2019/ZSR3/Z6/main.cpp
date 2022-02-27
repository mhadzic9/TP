//TP 2018/2019: ZSR 3, Zadatak 6
#include <iostream>
#include <vector>

double Razlomci (std::vector<double> v)
{
    double suma=0;
    for (int i=v.size()-1; i>=0; i--) {
        suma=1/(v.at(i)+suma);

    }
    return 1/suma;
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
    double suma=Razlomci(v);
    std::cout << suma;

    return 0;
}
