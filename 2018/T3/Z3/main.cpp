//TP 2017/2018: Tutorijal 3, Zadatak 3
#include <iostream>
#include <vector>
#include <deque>

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
std::deque<int> IzdvojiElemente (std::deque<int> v, bool a)
{
    std::deque<int> vektor;
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
        std::deque<int> v;
        std::cout << "Unesite elemente: ";
        for(int i=0; i<n; i++) {
            std::cin >> a;
            v.push_back(a);
        }
        std::deque<int> b;
        std::deque<int> c;
        b=IzdvojiElemente(v,true);
        c=IzdvojiElemente(v,false);
        for(int i=0; i<b.size(); i++) {
            if(i==b.size()-1) std::cout << b.at(i);
            else std::cout << b.at(i) <<",";
        }
        std::cout << "\n";
        for (int i=0; i<c.size(); i++) {
            if(i==c.size()-1)
                std::cout << c.at(i);
            else std::cout << c.at(i) << ",";
        }

    }




    return 0;
}
