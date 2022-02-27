//TP 2018/2019: ZSR 1, Zadatak 15
#include <iostream>

int IzbaciNule (int n) {
    int naopako1=0,naopako2=0,c1,c2;
    while (n!=0) {
        c1=n%10;
        if (c1==0) {
            n/=10;
            continue;
        }
        naopako1=naopako1*10+c1;
        n/=10;
     }
     while (naopako1!=0) {
         c2=naopako1%10;
         naopako2=naopako2*10+c2;
         naopako1/=10;
     }
    return naopako2;
}

int main ()
{
    int x;
    do {
        std::cout << "Unesite broj x: ";
        std::cin >> x;
        if (x==0) break;
        std::cout << "Broj nakon izbacivanja nula glasi " << IzbaciNule(x) << std::endl;
        
    } while (x!=0);
    
	return 0;
}