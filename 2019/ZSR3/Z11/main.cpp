//TP 2018/2019: ZSR 3, Zadatak 11
#include <iostream>
#include <vector>

std::vector<int> BrojCifara (std::vector<long long int> v)
{
    std::vector<int> vek;
    for (int i=0;i<v.size();i++) {
        int broj=0;
        if (v.at(i)<0) throw std::range_error ("Nemoj mi to raditi!");
        while (v.at(i)!=0) {
            v.at(i)/=10;
            broj++;
        }
        vek.push_back(broj);
    }
    return vek;
}

int main ()
{
    std::vector<long long int> v;
    std::cout << "Unesite dimenziju vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    int a;
    do {
        std::cin >> a;
        v.push_back(a);
    } while (v.size()!=n);
    
    try {
        std::vector<int> vek=BrojCifara(v);
        for (int x:vek) {
            std::cout << x << " ";
        }
    }
    catch (std::range_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    
    return 0;
}
