//TP 2018/2019: ZSR 3, Zadatak 10
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

bool DaLiJeKub (int n) {
    const double EPSILON=0.00001;
        int broj=1;
        while (broj!=n) {
            if (pow(broj,3)-n>-EPSILON && pow(broj,3)-n<EPSILON) {
            return true;
            }
            broj++;
    }
    return false;
}

std::vector<bool> Kub (std::vector<int> v) {
    std::vector<bool> vek;
    for (int i=0;i<v.size();i++) {
        if (v.at(i)<0) throw std::range_error ("Ne dolazi u obzir!");
        if (DaLiJeKub(v.at(i))==true) {
            vek.push_back(true);
        }
        else {
            vek.push_back(false);
        }
    }
    return vek;
}

int main ()
{
    std::vector<int> v;
    std::cout << "Unesite dimenziju vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    int a;
    do {
        std::cin >> a;
        v.push_back(a);
    } while (v.size()!=n);
    
    try {
        std::vector<bool> vektor=Kub(v);
        for (bool x:vektor) {
            std::cout << std::boolalpha << x << " ";
        }
    }
    catch (std::range_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    
	return 0;
}