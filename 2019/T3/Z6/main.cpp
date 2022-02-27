//TP 2018/2019: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<int>> Matrica;

Matrica KroneckerovProizvod (std::vector<int> v1, std::vector<int> v2)
{
    Matrica mat(v1.size(),std::vector<int>(v2.size()));
    for (int i=0; i<v1.size(); i++) {
        for (int j=0; j<v2.size(); j++) {
            mat.at(i).at(j)=v1.at(i)*v2.at(j);
        }
    }
    return mat;
}
int Sirina (int n) {
    int broj=0;
    if (n<0) {
        broj++;
    }
    while (n!=0) {
        n/=10;
        broj++;
    }
    return broj;
}

int NajvecaSirina (Matrica m)
{
    if (m.size()==0) {
        return 0;
    }
    int max=m.at(0).at(0);
    for (std::vector<int> k:m) {
        for (int x:k) {
            if (Sirina(x)>Sirina(max)) {
                max=x;
            }
        }
    }
    return Sirina(max);
}

int main ()
{
    int a;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> a;
    std::vector<int> vek1;
    std::cout << "Unesite elemente prvog vektora: ";
    int a1;
    for (int i=0; i<a; i++) {
        std::cin >> a1;
        vek1.push_back(a1);
    }
    int b;
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> b;
    std::vector<int> vek2;
    std::cout << "Unesite elemente drugog vektora: ";
    std::cout << std::endl;
    int b1;
    for (int j=0; j<b; j++) {
        std::cin >> b1;
        vek2.push_back(b1);
    }
    Matrica matrica=KroneckerovProizvod(vek1,vek2);
    int sirina=NajvecaSirina(matrica);
    for (int i=0; i<matrica.size(); i++) {
        for (int j=0; j<matrica[0].size(); j++) {
            std::cout << std::setw(sirina+1) << matrica.at(i).at(j);
        }
        std::cout << std::endl;
    }
    return 0;
}
