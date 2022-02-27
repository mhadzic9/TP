//TP 2018/2019: ZSR 2, Zadatak 28
#include <iostream>
#include <vector>

std::vector<bool> JesuLiProsti (std::vector<int> v) {
    std::vector<bool> vek;
    for (int i=0;i<v.size();i++) {
        bool vrijednost=true;
            for (int j=2;j<v.at(i);j++){
                if (v.at(i)%j==0) vrijednost=false;
            }
            if (vrijednost==false) {
                vek.push_back(false);
            }
            else {
                vek.push_back(true);
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
    std::vector<bool> vektor=JesuLiProsti(vekt);
    for (bool x:vektor) {
        std::cout << std::boolalpha << x << " ";
    }
    
	return 0;
}