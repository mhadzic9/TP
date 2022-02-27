//TP 2018/2019: Ispit 1, Zadatak 2
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>

template <typename Tip>

std::deque<double> IzdvojiElemente (std::vector<Tip> v) {
    std::deque<double> dek;
    for(int i=0;i<v.size();i++){
        if((i+1)%2==0 && v.at(i)<0) throw std::logic_error ("Element vektora negativan!");
    }
    for (int i=0;i<v.size();i++) {
        if ((i+1)%2==0)dek.push_back(sqrt(v.at(i)));
        if ((i+1)%2!=0) dek.push_back(v.at(i)*v.at(i));
    }
    return dek;
}

int main ()
{
    int n;
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >>n;
    std::cout << "Unesite elemente vektora: ";
    std::vector<int> v;
    int a;
    do{
        std::cin >> a;
        v.push_back(a);
        
    } while (v.size()!=n);
    try {
        std::deque<double> dek=IzdvojiElemente(v);
        std::cout << "Rezultujuci dek: ";
        for (int i=0;i<dek.size();i++) {
            if (dek.at(i)-int(dek.at(i))==0)std::cout << dek.at(i) << " ";
            else std::cout << std::fixed << std::setprecision(2) << dek.at(i) << " ";
        }
    }
    catch (std::logic_error izuzetak) {
        std::cout << "Problem: "<< izuzetak.what();
    }
    
	return 0;
}