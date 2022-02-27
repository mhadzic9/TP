//TP 2018/2019: ZSR 2, Zadatak 19
#include <iostream>
#include <vector>

std::vector<int> BrojCifara (std::vector<int> v) {
    std::vector<int> vek;
    for (int i=0;i<v.size();i++) {
        int brojac=0;
        while (v.at(i)!=0) {
            v.at(i)/=10;
            brojac++;
            if (v.at(i)==0) break;
        }
        vek.push_back(brojac);
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
    std::vector<int> vektor=BrojCifara(vekt);
    for (int i=0;i<vektor.size();i++) {
        std::cout << vektor.at(i) << " ";
    }
    
	return 0;
}