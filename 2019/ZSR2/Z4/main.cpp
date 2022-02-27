//TP 2018/2019: ZSR 2, Zadatak 4
#include <iostream>

int NaopakiBroj (int n)
{
    int naopaki=0,c;
    while (n!=0) {
        c=abs(n%10);
        naopaki=naopaki*10+c;
        n/=10;
    }
    return naopaki;
}

int Podbroj (int n, bool vrijednost)
{
    int c,naopaki=0;
    if (vrijednost==true) {
        while (n!=0) {
            c=n%10;
            if (c%2==0) {
                naopaki=naopaki*10+c;
            }
            n/=10;
            if (n==0) break;
        }
    }
    if (vrijednost==false) {
        while (n!=0) {
            c=n%10;
            if (c%2!=0) {
                naopaki=naopaki*10+c;
            }
            n/=10;
            if (n==0) break;
        }
    }
    return NaopakiBroj(naopaki);
}

int main ()
{
    std::cout << Podbroj(3427816, true) << std::endl;
    std::cout << Podbroj(3427816, false) << std::endl;

    return 0;
}
