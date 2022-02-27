//TP 2018/2019: ZSR 2, Zadatak 3
#include <iostream>

bool Istinitost (int n) {
    int c,c1;
    while (n!=0) {
        c=n%10;
        n/=10;
        c1=n%10;
        if (c1==c) return true;
        if (n==0) break;
    }
    return false;
}

int main ()
{
    int a;
    std::cout << "Unesite neki broj: ";
    std::cin >> a;
    if (Istinitost(a)==true) {
        std::cout << "Broj sadrzi cifre koje se ponavljaju.";
    }
    else {
        std::cout << "Broj ne sadrzi cifre koje se ponavljaju.";
    }
   
	return 0;
}