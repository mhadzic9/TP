//TP 2017/2018: Tutorijal 3, Zadatak 1
#include <iostream>
#include <vector>

int ZbirCifara (int broj)
{
    int a,b=0;
    do {
        a=broj%10;
        broj/=10;
        b+=a;
    } while(broj!=0);
    return b;
}
std::vector<int> IzdvojiElemente (std::vector<int> v, bool a)
{
    std::vector<int> vektor;
    for(int x:v) {
        if(a==true && (ZbirCifara(x))%2==0) vektor.push_back(x);
        else if(a==false && (ZbirCifara(x))%2!=0) vektor.push_back(x);
    }
    return vektor;
}

int main ()
{
    int n;
    std::cout << "Koliko zelite unijeti elemenata: ";
    std::cin >> n;
    if(n==0) std::cout << "Broj elemenata mora biti veci od 0!";
    else {
        int a;
        std::vector<int> v;
        std::cout << "Unesite elemente: ";
        for(int i=0; i<n; i++) {
            std::cin >> a;
            v.push_back(a);
        }
        std::vector<int> b;
        std::vector<int> c;
        b=IzdvojiElemente(v,true);
        c=IzdvojiElemente(v,false);
        for(int x:b) std::cout << x << " ";
        std::cout << "\n";
        for(int y:c) std::cout << y << " ";
    }




    return 0;
}
