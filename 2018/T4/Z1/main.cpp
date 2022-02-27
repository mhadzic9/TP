//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>

int Cifre (long long int n, int &c_min, int &c_max)
{
    int br_cifara=0;
    c_min=9;
    c_max=0;
    if(n==0) {
        c_min=0;
        br_cifara++;
        return br_cifara;
    }
    while(n!=0) {
        if(n<0) n=n*(-1);
        int cif;
        cif=abs(n%10);
        if(cif>c_max) c_max=cif;
        if(cif<c_min) c_min=cif;
        br_cifara++;
        n=n/10;
    }
    if(br_cifara==0) c_min=0;
    return br_cifara;
}
int main ()
{
    long long int broj;
    std::cout << "Unesite broj: ";
    std::cin >> broj;
    int e,c,d;
    e=Cifre(broj,c,d);
    std::cout << "Broj " << broj << " ima " << e << " cifara, najveca je " << d << " a najmanja " << c << ".";
    return 0;
}
