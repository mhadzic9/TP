//TP 2018/2019: ZSR 2, Zadatak 17
#include <iostream>
#include <vector>

std::vector<int> Djeljivi (int n) {
    std::vector<int> v;
    for (int i=100;i<1000;i++) {
        if (i%n==0) {
            v.push_back(i);
        }
    }
    return v;
}

int main ()
{
    int a;
    std::cout << "Unesite broj a: ";
    std::cin >> a;
    std::vector<int> vek=Djeljivi(a);
    if (vek.size()==0) {
        std::cout << "Za uneseni broj nema rezultata.";
        return 0;
    }
    for (int x:vek) {
        std::cout << x << " ";
    }
    
    
	return 0;
}