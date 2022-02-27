//TP 2018/2019: ZSR 2, Zadatak 18
#include <iostream>
#include <vector>

std::vector<int> Ubaci (int niz[],int velicina) {
    std::vector<int> v;
    for (int i=0;i<velicina;i++) {
        if (niz[i]%2==0) {
            v.push_back(niz[i]);
        }
    }
    for (int i=0;i<velicina;i++) {
        if (niz[i]%2!=0) {
            v.push_back(niz[i]);
        }
    }
    return v;
}

int main ()
{
    int niz[10];
    std::vector<int> v;
    std::cout << "Unesite elemente niza: ";
    for (int i=0;i<10;i++) {
        std::cout << "Element " << i+1 << ". " << std::endl;
        std::cin >> niz[i];
    }
    v= Ubaci(niz,10);
    for (int i=0;i<v.size();i++) {
        if (i<v.size()-1) {
            std::cout << v.at(i) << ", ";
        }
        else if (i==v.size()-1) {
            std::cout << v.at(i) << ".";
        }
    }
	return 0;
}