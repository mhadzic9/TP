//TP 2018/2019: ZSR 2, Zadatak 31
#include <iostream>
#include <vector>

int PrijateljskiBrojevi (std::vector<int> v) {
    int brojac=0;
    for (int i=0;i<v.size()-1;i++) {
        int suma=0;
        int broj=1;
        while (1) {
            if (v.at(i)%broj==0) {
                suma+=broj;
            }
            broj++;
            if (broj>=v.at(i)) break;
                    
                }
            for (int j=i+1;j<v.size();j++) {
                if (v.at(j)==suma) brojac++;
            }
    }
    return brojac;
}

int main ()
{
    std::vector<int> v;
    int a;
    std::cout << "Unosite elemente vektora (0 za kraj): ";
    do {
        std::cin >> a;
        v.push_back(a);
        if (a==0) break;
    } while (a!=0);
    std::cout << "Parova prijateljskih brojeva ima " << PrijateljskiBrojevi(v) << ".";
    
	return 0;
}