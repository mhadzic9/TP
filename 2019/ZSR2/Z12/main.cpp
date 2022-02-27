//TP 2018/2019: ZSR 2, Zadatak 12
#include <iostream>
#include <vector>

bool ImaLiTrocifrenih (std::vector<int> v) {
    for (int i=0;i<v.size();i++) {
        int brojac=0;
        while (v.at(i)!=0) {
            v.at(i)/=10;
            brojac++;
            if (v.at(i)==0 && brojac==3) {
                return true;
                break;
            }
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
    if (ImaLiTrocifrenih(vek)==true) {
        std::cout << "U unesenom vektoru nalazi se barem jedan trocifreni broj.";
    }
    else {
        std::cout << "U unesenom vektoru ne nalazi se niti jedan trocifreni broj.";
    }
    
	return 0;
}