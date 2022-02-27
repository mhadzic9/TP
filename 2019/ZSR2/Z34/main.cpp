//TP 2018/2019: ZSR 2, Zadatak 34
#include <iostream>
#include <vector> 


unsigned long long int Faktorijel (int n) {
    if (n<0) return 0;
    if (n==1) return 1;
    int clan=1;
    for (int i=2;i<=n;i++) {
        clan*=i;
    }
    return clan;
}

std::vector<int> UFaktorijel (std::vector<int> v) {
    std::vector<int> vek;
    for (int i=0;i<v.size();i++) {
        vek.push_back(Faktorijel(v.at(i)));
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
        if (a==0) break;
        v.push_back(a);
    } while (a!=0);
    std::vector<int> vektor=UFaktorijel(v);
    for (int x:vektor) {
        std::cout << x << " ";
    }

    
	return 0;
}