//TP 2018/2019: ZSR 2, Zadatak 35
#include <iostream>
#include <vector>
#include <cmath>

int NaopakiBroj (int n)
{
    int c,naopako=0;
    while (n!=0) {
        c=abs(n%10);
        naopako=naopako*10+c;
        n/=10;
    }
    return naopako;
}
int VecaManjaZaJedan (int a)
{
    int c1,naopako1=0;
    while (a!=0) {
        c1=abs(a%10);
        if (c1%2==0) {
            c1++;
        } else {
            c1--;
        }
        naopako1=naopako1*10+c1;
        a/=10;
    }
    return NaopakiBroj(naopako1);
}

std::vector<int> Transformacija (std::vector<int> v)
{
    std::vector<int> vek;
    for (int i=0; i<v.size(); i++) {
        vek.push_back(VecaManjaZaJedan(v.at(i)));
    }
    return vek;
}

int main ()
{
    std::vector<int> v;
    int a;
    std::cout << "Unosite elemente vektora (0 za kraj): ";
    do {
        std::cin >> a;
        if (a==0) break;
        v.push_back(a);
    } while (a!=0);
    std::vector<int> vektor=Transformacija(v);
    for (int x:vektor) {
        std::cout << x << " ";
    }

    return 0;
}
