//TP 2018/2019: ZSR 2, Zadatak 2
#include <iostream>
#include <vector>

bool DaLiSePonavljaju (int n) {
    int c,tmp,c1,brojac=0;
    while (n!=0) {
        c=n%10;
        tmp=n;
        tmp/=10;
        do {
            c1=tmp%10;
            tmp/=10;
            if (c1==c) brojac++;
            if (tmp==0) break;
        } while (tmp!=0);
        n/=10;
        if (brojac>=1) return true;
    }
    return false;
    
}

int main ()
{
    int a;
    std::cout << "Unesite neki broj: ";
    std::cin >> a;
    if (DaLiSePonavljaju(a)==true) {
        std::cout << "Broj " << a << " sadrzi cifre koje se ponavljaju.";
    }
    else {
        std::cout << "Broj " << a << " ne sadrzi cifre koje se ponavljaju.";
    }
    
	return 0;
}