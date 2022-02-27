//TP 2018/2019: Tutorijal 3, Zadatak 2
#include <iostream>
#include <vector>

int ZbirCifara (int n)
{
    int c,suma=0;
    while (n!=0) {
        c=n%10;
        suma+=c;
        n/=10;
    }
    return suma;
}


std::vector<int > IzdvojiElemente (std::vector<int> v, bool stanje)
{
    std::vector<int> vek;
    for (int x : v) {
        if (stanje==true && ZbirCifara(x)%2==0) {
            vek.push_back(x);
        }
        if (stanje==false && ZbirCifara(x)%2!=0) {
            vek.push_back(x);
        }
    }
    return vek;
}
int main()
{
    int n,a;
    std::vector<int> v1;
    std::cout << "Koliko zelite unijeti elemenata: ";
    std::cin >> n;
    if (n<=0) {
        std::cout << "Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::cout << "Unesite elemente: ";
    for (int i=0; i<n; i++) {
        std::cin >> a;
        v1.push_back(a);
    }
    std::vector<int> v2;
    std::vector<int> v3;
    v2=IzdvojiElemente(v1,true);
    v3=IzdvojiElemente(v1,false);
    for (int i=0; i<v2.size(); i++) {
        if (i<v2.size()-1) {
            std::cout << v2.at(i) << ",";
        } else if (i==v2.size()-1) {
            std::cout << v2.at(i);
        }
    }
    std::cout << std::endl;
    for (int i=0; i<v3.size(); i++) {
        if (i<v3.size()-1) {
            std::cout << v3.at(i) << ",";
        } else if (i==v3.size()-1) {
            std::cout << v3.at(i);
        }
    }

    return 0;
}
