//TP 2018/2019: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int n)
{
    int i;
    if (n<=0) return false;
    if (n==1) return false;
    for (i=2; i<=std::sqrt(n); i++) {
        if (n%i==0) {
            return false;
            break;
        }
    }
    return true;
}
std::vector<int> ProstiBrojeviUOpsegu (int a, int b)
{
    std::vector<int> v;
    int i;
    for (i=a; i<=b; i++) {
        if (DaLiJeProst(i)==true) {
            v.push_back(i);
        }
        if (i==b) break;
    }
    return v;
}

int main ()
{
    int a,b;
    std::vector<int> vek;
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    std::cin >> a >> b;
    vek=ProstiBrojeviUOpsegu(a,b);
    if (vek.size()==0) {
        std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!" << std::endl;
    } else {
        std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
        for (int i=0; i<vek.size(); i++) {
            if (i==vek.size()-1) {
                std::cout << vek[i] << std::endl;
            } else {
                std::cout << vek[i] << ", ";
            }
        }
    }


    return 0;
}
