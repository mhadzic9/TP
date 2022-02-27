//TP 2018/2019: ZSR 3, Zadatak 1
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu (int br_redova,int br_kolona)
{
    return Matrica(br_redova,std::vector<int> (br_kolona));
}
// Vraća broj redova zadane matrice
int BrojRedova(Matrica m) {
 return m.size();
}
// Vraća broj kolona zadane matrice
int BrojKolona(Matrica m) {
 return m[0].size();
}
Matrica UnesiMatricu(int br_redova, int br_kolona)
{
    auto m = KreirajMatricu(br_redova, br_kolona);
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++) {
            std::cout << "Element (" << i + 1 << "," << j + 1 << "): ";
            std::cin >> m[i][j];
        }
    return m;
}
void IspisiMatricu(Matrica m)
{
    for(int i = 0; i < BrojRedova(m); i++) {
        for(int j = 0; j < BrojKolona(m); j++)
            std::cout << std::setw(10) << m[i][j];
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite prirodan broj n: ";
    int n;
    std::cin >> n;
    Matrica m=UnesiMatricu(n,n);
    int maxsuma=0,maxk=0;
    for (int i=0; i<n; i++) {
        maxsuma+=m[i][0];
    }
    for (int i=0;i<n;i++) {
        int suma1=0;
        for (int j=0;j<n;j++) {
            suma1+=m[i][j];
            
        }
        if (suma1>maxsuma) {
            maxsuma=suma1;
            maxk=i;
        }
    }
    int minsuma=0,minr=0;
    for (int i=0; i<n; i++) {
        minsuma+=m[0][i];
    }
    for (int i=0;i<n;i++) {
        int suma2=0;
        for (int j=0;j<n;j++) {
            suma2+=m[i][j];
            
        }
        if (suma2<minsuma) {
            minsuma=suma2;
            minr=i;
        }
    }
    int suma3=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) suma3+=m[i][j];
        }
    }
    std::cout << "Redni broj kolone sa najvecom sumom elemenata je " << maxk+1 << std::endl;
    std::cout << "Redni broj reda sa najmanjom sumom elemenata je " << minr+1 << std::endl;
    std::cout << "Suma elemenata na dijagonali je " << suma3;

    return 0;
}
