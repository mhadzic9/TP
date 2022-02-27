//TP 2018/2019: ZSR 2, Zadatak 16
#include <iostream>
#include <vector>

std::vector<int> Kvadrati (int n) {
    std::vector<int> v;
    int stepen=1;
    while (stepen*stepen<n) {
        v.push_back(stepen);
        stepen++;
        if (stepen*stepen>n) break;
    }
    return v;
}

int main ()
{
    int a;
    std::cout << "Unesite broj a: ";
    std::cin >> a;
    std::vector<int> vek=Kvadrati(a);
    for (int x:vek) {
        std::cout << x << " ";
    }
    
    
	return 0;
}