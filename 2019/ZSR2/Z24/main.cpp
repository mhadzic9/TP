//TP 2018/2019: ZSR 2, Zadatak 24
#include <iostream>
#include <vector>

std::vector<int> LokalniMaksimum (std::vector<int> v) {
    std::vector<int> ve;
    for (int i=1;i<v.size()-1;i++) {
        if (v.at(i)>v.at(i-1) && v.at(i)>v.at(i+1)) {
            ve.push_back(v.at(i));
        }
    }
    return ve;    
}

int main ()
{
    std::vector<int> vekt;
    int a;
    std::cout << "Koliko zelite unijeti elemenata vektora: ";
    int n;
    std::cin >> n;
    do {
        if (n==0) break;
        std::cin >> a;
        vekt.push_back(a);
    } while (vekt.size()<n);
    std::vector<int> vektor=LokalniMaksimum(vekt);
    for (int i=0;i<vektor.size();i++) {
        std::cout << vektor.at(i) << " ";
    }
    
	return 0;
}