//TP 2018/2019: ZSR 2, Zadatak 30
#include <iostream>
#include <vector>
#include <cmath>

bool JeLiSavrseni (int n) {
    if (n==0) return false;
    int broj=1,suma=0;
    while (n!=0) {
        if (n%broj==0) {
            suma+=broj;
        }
        broj++;
        if (broj==n) break;
    }
    if(suma==n) return true;
    return false;
}

std::vector<int> SavrseniBrojevi (std::vector<int> v) {
    std::vector<int> vek;
    for (int i=0;i<v.size();i++) {
        if (JeLiSavrseni(v.at(i))==true) {
            vek.push_back(v.at(i));
        }
    }
    return vek;
}

int main ()
{
    std::vector<int> v;
    int a;
    std::cout << "Unosite elemente vektora (0 za kraj): ";
    do {
        std::cin >> a;
        v.push_back(a);
        if (a==0) break;
    } while (a!=0);
    std::vector<int> vektor=SavrseniBrojevi(v);
    for (int x:vektor) {
        std::cout << x << " ";
    }
    
	return 0;
}