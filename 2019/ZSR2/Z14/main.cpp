//TP 2018/2019: ZSR 2, Zadatak 14
#include <iostream>
#include <vector>

std::vector<int> Djelioci (int n) {
    int djelilac=2;
    std::vector<int> v;
    while (n!=1) {
        if (n%djelilac==0) {
            n/=djelilac;
            v.push_back(djelilac);
        }
        else djelilac++;
    }
    return v;
}

int main ()
{
    int n;
    std::cout << "Unesite broj n: ";
    std::cin >> n;
    std::vector<int> vek;
    vek=Djelioci(n);
    for (int x:vek) {
        std::cout << x << " ";
    }
    
	return 0;
}