//TP 2018/2019: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

bool TestPerioda (std::vector<double> v, int p) {
    const double EPSILON1=0.0001;
    const double EPSILON2=-0.0001;
    if (p<1) return false;
    if (p>=v.size()) return false;
    for (int i=0;i<v.size()-p;i++) {
        if (v.at(i)-v.at(i+p)<EPSILON2 || v.at(i)-v.at(i+p)>EPSILON1){
            return false;
        }
    }
    return true;
}
int OdrediOsnovniPeriod (std::vector<double> vek) {
    const double EPSILON1=0.0001;
    const double EPSILON2=-0.0001;
    for (int i=1;i<vek.size();i++) {
        if (TestPerioda(vek,i)==true && (vek.at(i)-vek.at(0)>EPSILON2 && vek.at(i)-vek.at(0)<EPSILON1)) {
            return i;
        }
    }
    return 0;
}

int main ()
{
    std::vector<double> vekt;
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    double broj;
    const double EPSILON1=0.0001;
    const double EPSILON2=-0.0001;
    do {
        std::cin >> broj;
        if (broj<EPSILON2 || broj>EPSILON1) {
            vekt.push_back(broj);
        } 
    } while (broj<EPSILON2 || broj>EPSILON1);
    if (OdrediOsnovniPeriod(vekt)==0) {
        std::cout << "Slijed nije periodican!" << std::endl;
    }
    else {
        std::cout << "Slijed je periodican sa osnovnim periodom " << OdrediOsnovniPeriod(vekt) << "." << std::endl;
    }
    
	return 0;
}