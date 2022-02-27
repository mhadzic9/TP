//TP 2018/2019: ZSR 2, Zadatak 23
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int n) {
    for (int i=2;i<n;i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}

std::vector<int> SlozeniBrojevi (std::vector<int> v) {
    std::vector<int> vek;
    for (int i=0;i<v.size();i++) {
        if (DaLiJeProst(v.at(i))==false) {
            vek.push_back(v.at(i));
        }
    }
    return vek;
}

int main ()
{
    std::vector<int> vekt;
    int a;
    std::cout << "Koliko zelite unijeti elemenata vektora: ";
    int n;
    std::cin >> n;
    do {
        if (n==0) break;
        std::cin >> a;
        vekt.push_back(a);
    } while (vekt.size()<n);
    std::vector<int> vektor=SlozeniBrojevi(vekt);
    for (int i=0;i<vektor.size();i++) {
        std::cout << vektor.at(i) << " ";
    }
    
	return 0;
}