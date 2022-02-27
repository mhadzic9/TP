//TP 2018/2019: ZSR 2, Zadatak 29
#include <iostream>
#include <vector>
#include <cmath>

int SumaCifara (int n) {
    int c,suma=0;
    while (n!=0) {
        c=abs(n%10);
        suma+=c;
        n/=10;
    }
    return suma;
}

std::vector<int> SumaVeca (std::vector<int> v,int a) {
    std::vector<int> vekt;
    for (int i=0;i<v.size();i++) {
        if (SumaCifara(v.at(i))>a) {
            vekt.push_back(v.at(i));
        }
    }
    return vekt;
}

int main ()
{
    int b;
    std::cout << "Unesite neki broj: ";
    std::cin >> b;
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
    std::vector<int> vektor=SumaVeca(vekt,b);
    for (int x:vektor) {
        std::cout << x << " ";
    }
    
	return 0;
}