//TP 2018/2019: ZSR 2, Zadatak 20
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> SumeCifara (std::vector<int> v) {
    std::vector<int> vek;
    int c;
    for (int i=0;i<v.size();i++) {
        int suma=0;
        while (v.at(i)!=0) {
            c=abs(v.at(i)%10);
            suma+=c;
            v.at(i)/=10;
            if (v.at(i)==0) break;
        }
        vek.push_back(suma);
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
    std::vector<int> vektor=SumeCifara(vekt);
    for (int i=0;i<vektor.size();i++) {
        std::cout << vektor.at(i) << " ";
    }
    
	return 0;
}