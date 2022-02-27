//TP 2018/2019: ZSR 2, Zadatak 10
#include <iostream>
#include <vector>
#include <cmath>

bool ImaLiKvadrata (std::vector<int> v) {
    const double EPSILON=0.00001;
    for (int i=0;i<v.size();i++) {
        int brojac=1;
        while (brojac<=v.at(i)/2) {
            if (pow(brojac,2)-v.at(i)>-EPSILON && pow(brojac,2)-v.at(i)<EPSILON) return true;
            brojac++;
        }
    }
    return false;
}

int main ()
{
    std::vector<int> vek;
    int a;
    std::cout << "Koliko zelite unijeti elemenata vektora: ";
    int n;
    std::cin >> n;
    do {
        if (n==0) break;
        std::cin >> a;
        vek.push_back(a);
    } while (vek.size()<n);
    if (ImaLiKvadrata(vek)==true) {
        std::cout << "Vektor sadrzi barem jedan potpun kvadrat.";
    }
    else {
        std::cout << "Vektor ne sadrzi niti jedan potpun kvadrat.";
    }
	return 0;
}