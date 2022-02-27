//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <string>
#include <iomanip>

template <typename Tip1, typename Tip2>
void UnosBroja (Tip1 s1, Tip1 s2, Tip2 &p)
{
    std::cout << s1;
    std::cout << std::endl;
    while(!(std::cin>>p) || std::cin.peek()!='\n') {
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
    UnosBroja("Unesite bazu: ","Neispravan unos, pokusajte ponovo...",n);
    int e;
    std::cout<<std::endl;
    UnosBroja("Unesite cjelobrojni eksponent: ","Neispravan unos, pokusajte ponovo...",e);
    double h=1;
    int i=0;
    if(e>0) {
        while(i<e) {
            h*=n;
            i++;
        }
    } else if(e==0) {
        h=1;
    } else {
        i=0;
        while(i<abs(e)) {
            h*=(1./n);
            i++;
        }
    }

    std::cout << n << " na " << e << " iznosi " << h;
    return 0;
}
