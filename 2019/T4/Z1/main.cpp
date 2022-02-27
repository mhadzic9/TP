//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>

int Cifre (long long int n,int &c_min, int &c_max) {
    c_max=abs(n%10);
    c_min=abs(n%10);
    int brojac=0,c;
    if (n==0) {
        brojac++;
    }
    if (n<0) {
        n=-n;
    }
    while (n!=0) {
        c=abs(n%10);
        if(c>c_max) {
            c_max=c;
        }
        if (c<c_min) {
            c_min=c;
        }
        n/=10;
        brojac++;
    }
    return brojac;
}


int main ()
{
    long long int a;
    std::cout << "Unesite broj: ";
    std::cin >> a;
    int min,max,broj_cifara;
    broj_cifara=Cifre(a,min,max);
    std::cout << "Broj "<< a << " ima " << broj_cifara << " cifara, " << "najveca je " << max << " a najmanja " << min << ".";
    
	return 0;
}