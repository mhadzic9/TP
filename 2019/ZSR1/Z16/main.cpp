//TP 2018/2019: ZSR 1, Zadatak 16
#include <iostream>

int MultOtpornost (int n) {
    int k=0,proizvod,c;
        while (1) {
            proizvod=1;
            do {
            c=n%10;
            proizvod*=c;
            n/=10;
            } while (n!=0);
           
            if (n==0) {
                n=proizvod;
                k++;
            }
             if (proizvod==0) break;
             if (k>8) break;
             if (proizvod<10) break;

    }
    return k;
}

int main ()
{
    int a,b,m;
    std::cout << "Unesite broj a: ";
    std::cin >> a;
    std::cout << "Unesite broj b: ";
    std::cin >> b;
    std::cout << "Unesite zeljenu multiplikativnu otpornost: ";
    std::cin >> m;
    for (int i=a;i<=b;i++) {
        if (MultOtpornost(i)==m) {
            std::cout << i << " ";
        }
    }
    
	return 0;
}