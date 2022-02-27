//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>
int main ()
{
    float n;
    std::cout << "Unesite prirodan broj ili 0 za kraj: ";
    for (;;) {
        std::cin >> n;
        while (!std::cin || n<0 || floor(n)!=ceil(n)) {
            std::cout << "Niste unijeli prirodan broj!" << std::endl;
            std::cin.clear();
            std::cin.ignore (10000, '\n');
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
            std::cin >> n;
        }
    
        if (n==0) { std::cout << "Dovidjenja!";
        break; }
        else {
    
 
    int br=int(n);
    int i,suma=0;
    for(i=1;i<n;i++) {
        if(br%i==0) suma+=i;
    }
    if(suma==br) std::cout << "Broj " << n << " je savrsen!";
    else if(suma>br) std::cout << "Broj " << n << " je obilan!";
    else if(suma<br) std::cout << "Broj " << n << " je manjkav!";
    }
    std::cout << "\nUnesite prirodan broj ili 0 za kraj: ";
    }












    return 0;
}
