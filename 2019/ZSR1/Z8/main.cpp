//TP 2018/2019: ZSR 1, Zadatak 8
#include <iostream>

int main ()
{
    int a,b,c,d,e,f;
    std::cout << "Unesite 6 brojeva: ";
    std::cin >> a >> b >> c >> d >> e >> f;
    if (a<=0 || b<=0 || c<=0 || d<=0 || e<=0 || f<=0) {
        std::cout << "Svi brojevi nisu pozitivni.";
        return 0;
    }
    if (a%2==0 && b%2==0 && c%2==0 && d%2==0 && e%2==0 && f%2==0) {
        std::cout << "Medju njima nema neparnih brojeva.";
        return 0;
    }
    else {
        std::cout << "Medju njima ima neparnih brojeva.";
    }
    
	return 0;
}