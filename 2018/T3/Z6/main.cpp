//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<int>> KroneckerovProizvod (std::vector<int> v1, std::vector<int> v2)
{
    std::vector<std::vector<int>> c(v1.size(),std::vector<int>(v2.size()));
    for(int i=0; i<v1.size(); i++) {
        for(int j=0; j<v2.size(); j++) {
            c.at(i).at(j)=v1.at(i)*v2.at(j);
        }
    }
    return c;
}
int velicina(int v)
{
    int vel=0;
    if(v<0) vel++;
    do {
        v/=10;
        vel++;
    } while (v!=0);
    return vel;
}
int NajvecaSirina(std::vector<std::vector<int>> m)
{
    if(m.size()==0) return 0;
    int najduzi=m.at(0).at(0);
    for(std::vector<int> r:m)
        for (int el:r)
            if(velicina(el)>velicina(najduzi))
                najduzi=el;
    return velicina(najduzi);
}

int main ()
{
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int m;
    std::cin >> m;
    std::vector<int> a;
    std::cout << "Unesite elemente prvog vektora: ";
    int el;
    for(int i=0; i<m; i++) {
        std::cin >> el;
        a.push_back(el);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    int n;
    std::cin >> n;
    std::vector<int> b;
    std::cout << "Unesite elemente drugog vektora: ";
    int el2;
    for (int i=0; i<n; i++) {
        std::cin >> el2;
        b.push_back(el2);
    }
    std::cout << std::endl;
    std::vector<std::vector<int>> C;
    C=KroneckerovProizvod(a,b);
    for(std::vector<int> r:C) {
        for(int element:r) {
            std::cout << std::setw(NajvecaSirina(C)+1)<<element;
        }
        std::cout<<std::endl;
    }


    return 0;
}
