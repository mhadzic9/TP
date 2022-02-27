//TP 2018/2019: ZSR 2, Zadatak 13
#include <iostream>
#include <vector>
#include <cmath>

bool JeLiStepenDvojke (std::vector<int> v) {
    for (int i=0;i<v.size();i++) {
        if (v.at(i)%2==0) {
            while (v.at(i)%2==0) {
                v.at(i)/=2;
                if (v.at(i)==1) break;
            }
            if (v.at(i)==1) return true;
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
    if (JeLiStepenDvojke(vek)==true) {
        std::cout << "U unesenom vektoru nalazi se barem jedan stepen broja 2.";
    }
    else {
        std::cout << "U unesenom vektoru ne nalazi se niti jedan stepen broja 2.";
    }
    
	return 0;
}