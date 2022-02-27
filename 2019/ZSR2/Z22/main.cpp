//TP 2018/2019: ZSR 2, Zadatak 22
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int n) {
    for (int i=2;i<n;i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}

std::vector<int> ProstiDjelioci (int a) {
    std::vector<int> v;
    int broj=2;
    while (1) {
        if (DaLiJeProst(broj)==true && a%broj==0) {
            v.push_back(broj);
            a/=broj;
        }
        else {
            broj++;
        }
        if (broj>a) break;
    }
    return v;
}

int main ()
{
    int n;
    std::cout << "Unesite neki broj: ";
    std::cin >> n;
    std::vector<int> v=ProstiDjelioci(n);
    for (int x:v) {
        std::cout << x << " ";
    }
    
	return 0;
}