//TP 2018/2019: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

Matrica PascalovTrougao (int n)
{
    if (n<0) {
        throw std::domain_error ("Broj redova ne smije biti negativan");
    }
    Matrica m(n);
    for (int i=0; i<n; i++) {
        m.at(i).resize(i+1);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            if (i==j || j==0) {
                m.at(i).at(j)=1;
            } else {
                m.at(i).at(j)=m.at(i-1).at(j)+m.at(i-1).at(j-1);
            }
        }
    }
    return m;

}


int Sirina (int n)
{
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
    Matrica mat;
    std::cout << "Unesite broj redova: ";
    std::cin >> a;
    std::cout << std::endl;
    mat=PascalovTrougao(a);
    for (int i=0; i<a; i++) {
        for (int j=0; j<i+1; j++) {
            std::cout << std::setw(NajvecaSirina(mat)+1) << mat.at(i).at(j);
        }
        std::cout << std::endl;
    }

    return 0;
}
