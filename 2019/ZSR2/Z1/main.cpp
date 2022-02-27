//TP 2018/2019: ZSR 2, Zadatak 1
#include <iostream>
#include <cmath>

int NaopakiBroj (int n) {
    int naopaki=0,c;
    while (n!=0) {
        c=abs(n%10);
        naopaki=naopaki*10+c;
        n/=10;
    }
    return naopaki;
}
bool JeLiSimetrican (int a) {
    if (a==NaopakiBroj(a)) {
        return true;
    }
    return false;
}

int main ()
{
    int x;
    std::cout << "Unosite brojeve sa tastature (0 za kraj unosa): ";
    do {
        std::cin >> x;
        if (x<10) continue;
        if (JeLiSimetrican(x)==true) {
            std::cout << x << std::endl;
        }
        if (x==0) break;
    } while (x!=0);
    
	return 0;
}