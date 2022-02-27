//TP 2018/2019: ZSR 2, Zadatak 15
#include <iostream>
#include <vector>

std::vector<int> StepenDvojke (int n) {
    std::vector<int> v;
    int stepen=1;
    while (stepen<n) {
        v.push_back(stepen);
        stepen*=2;
        if (stepen>n) break;
    }
    return v;
}

int main ()
{
    int a;
    std::cout << "Unesite broj a: ";
    std::cin >> a;
    std::vector<int> vek=StepenDvojke(a);
    for (int x:vek) {
        std::cout << x << " ";
    }
    
	return 0;
}