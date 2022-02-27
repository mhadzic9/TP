//TP 2018/2019: ZSR 2, Zadatak 26
#include <iostream>
#include <vector>
#include <iomanip>

bool ZbirUzastopnih (int n) {
    int broj=1;
    while (broj+5<=n) {
        int suma=0;
        for (int i=broj;i<broj+5;i++) {
            suma+=i;
        }
        if (suma==n) return true;
        broj++;
    }
    return false;
}

std::vector<bool> VektorLogickihVrijednosti (std::vector<int> v) {
    std::vector<bool> vek;
    for (int i=0;i<v.size();i++) {
        if (ZbirUzastopnih(v.at(i))==true) {
            vek.push_back(true);
        }
        else {
            vek.push_back(false);
        }
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
    std::vector<bool> vektor=VektorLogickihVrijednosti(vekt);
    for (bool x:vektor) {
        std::cout << std::boolalpha << x << " ";
    }
    
	return 0;
}