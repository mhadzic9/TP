//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    int a,b,c;
    std::cin >> a >> b >> c;
    std::cout << "Unesite sirinu plocice u centimetrima: " << std::endl;
    int d;
    std::cin >> d;
    int p;
    p=2*(a*c+b*c)+a*b;
    int p1=p*10000;
    if (p1%(d*d)==0 && (a*100)%d==0 && (b*100)%d==0 && (c*100)%d==0) {
        std::cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m " << "sa plocicama dimenzija " << d << "x" << d << "cm " << std::endl << "potrebno je " << p1/(d*d) << " plocica.";
    } else {
        std::cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m " << "sa plocicama dimenzija " << d << "x" << d << "cm" << std::endl << "nije izvodljivo bez lomljenja plocica!";
    }
    return 0;
}
