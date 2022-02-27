//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>
bool DaLiJeProst(int n) 
{
    for(int i=2;i<=sqrt(n);i++) {
        
        if(n%i==0) {
        n=false;
        
        break;
        }
    
    else if (i==n) {
        n=true;
    }
    
}
if(n<=1) n=false;
return n;
}
std::vector<int> ProstiBrojeviUOpsegu (int a,int b) {
    std::vector<int> vek;
    for(int i=a;i<=b;i++) {
        if(DaLiJeProst(i)==true) vek.push_back(i);
        if(i==b) break;
    }
    return vek;
}
    
int main ()
{
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    int a,b;
    std::vector<int> vekt;
    std::cin >> a >> b;
    vekt=ProstiBrojeviUOpsegu(a,b);
    if(vekt.size()==0) {
        std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!" << std::endl;
    } else {
        std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
        for (int i=0;i<vekt.size();i++) {
            if(i==vekt.size()-1) std::cout << vekt[i] << std::endl;
            else std::cout << vekt[i] << ", ";
        }
    }
    
    
	return 0;
}
