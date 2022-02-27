//TP 2018/2019: ZSR 2, Zadatak 33
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> NajmanjaCifra (std::vector<int> v)
{
    std::vector<int> vek;
    for (int i=0; i<v.size(); i++) {
        int c;
        int min=9;
        while (v.at(i)!=0) {
            c=abs(v.at(i)%10);
            if (c<min) min=c;
            v.at(i)/=10;
            if (v.at(i)==0) break;
        }
        vek.push_back(min);
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
    std::vector<int> vektor=NajmanjaCifra(v);
    for (int x:vektor) {
        std::cout << x << " ";
    }
    
    return 0;
}
