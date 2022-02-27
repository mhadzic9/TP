//TP 2018/2019: ZSR 3, Zadatak 2
#include <iostream>
#include <vector>
#include <iomanip>

typedef<std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu (int br_redova, int br_kolona) {
    return Matrica (br_redova,std::vector<int> (br_kolona));
}

Matrica Zadatak(int n) {
    Matrica m=KreirajMatricu(n,n);
    int red=0,kolona=n-1,broj=1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if ()
        }
    }
}

int main ()
{
	return 0;
}