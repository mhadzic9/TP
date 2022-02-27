//TP 2018/2019: ZSR 2, Zadatak 9
#include <iostream>
#include <vector>

bool ImaLiParnih (std::vector<int> v) {
    for (int i=0;i<v.size();i++) {
        if (v.at(i)%2==0) return true;
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
    if (ImaLiParnih(vek)==true) {
        std::cout << "Vektor sadrzi barem jedan paran element.";
    }
    else {
        std::cout << "Vektor ne sadrzi niti jedan paran element.";
    }
    
	return 0;
}