//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    int a,b,c;
    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin >> a >> b >> c;
    int d;
    std::cout << "Unesite sirinu plocice u centimetrima: ";
    std::cin >> d;
    int Pk,Pp;
    Pk=a*b+2*(a*c+b*c);
    Pp=d*d;
    if((Pk*10000)%Pp!=0 || (a*100)%d!=0 || (b*100)%d!=0 || (c*100)%d!=0) {
        std::cout << "\nPoplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m " << "sa plocicama dimenzija " << d << "x" << d << "cm " << "\nnije izvodljivo bez lomljenja plocica!" << std::endl;
    } else {
        std::cout << "\nZa poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m " << "sa plocicama dimenzija " << d << "x" << d << "cm" << "\npotrebno je " << (Pk*10000)/Pp << " plocica." << std::endl;
    }
    return 0;
}
