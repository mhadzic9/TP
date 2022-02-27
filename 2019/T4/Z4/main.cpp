//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <iomanip>
#include <string>

template <typename Tip1,typename Tip2>
void UnosBroja(Tip1 s1,Tip1 s2, Tip2 &a)
{
    std::cout << s1;
    std::cout << std::endl;
    while (!(std::cin >> a) || std::cin.peek()!='\n') {
        std::cout << s2;
        std::cout << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << s1;
        std::cout << std::endl;
    }
}

int main ()
{
    double n;
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...",n);
    std::cout << std::endl;
    int e;
    UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...",e);
    int i=0;
    double h=1;
    if (e==0) {
        h=1;
    }
    if (e>0) {
        while (i<e) {
            h*=n;
            i++;
        }
    }
    if (e<0) {
        while (i<abs(e)) {
            h/=n;
            i++;
        }
    }
    std::cout << n << " na " << e << " iznosi " << h;

    return 0;
}
