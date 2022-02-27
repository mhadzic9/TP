//TP 2018/2019: ZSR 1, Zadatak 28
#include <iostream>

int main ()
{
    int niz[10];
    std::cout << "Unesite elemente niza: ";
    for (int i=0;i<10;i++) {
        std::cin >> niz[i];
    }
    int tmp;
    for (int i=0;i<9;i++) {
        for (int j=i+1;j<10;j++) {
            tmp=niz[i];
            niz[i]=niz[j];
            niz[j]=tmp;
        }
    }
    std::cout << "Niz okrenut naopako glasi: ";
    for (int i=0;i<10;i++) {
        std::cout << niz[i] << " ";
    }
    
	return 0;
}