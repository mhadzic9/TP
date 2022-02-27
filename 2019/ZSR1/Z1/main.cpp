//TP 2018/2019: ZSR 1, Zadatak 1
#include <iostream>
#include <cmath>

int main ()
{
    double a1,b1,c1;
    std::cout << "Unesi prvo vrijeme (h min s): ";
    std::cin >> a1 >> b1 >> c1;
    double a2,b2,c2;
    std::cout << "Unesi drugo vrijeme (h min s): ";
    std::cin >> a2 >> b2 >> c2;
    double sec1, sec2;
    sec1=a1*3600+b1*60+c1;
    sec2=a2*3600+b2*60+c2;
    double sec3=abs(sec1-sec2);
    double n1,n2,n3;
    n1=int(sec3/3600);
    n2=round((sec3/3600-int(sec3/3600))*60);
    n3=round(((sec3/3600-int(sec3/3600))*60-int((sec3/3600-int(sec3/3600))*60))*60);
    std::cout << "Izmedju ova dva trenutka proteklo je " << n1 << "h " << n2 << "min " << n3 << "s.";
    
	return 0;
}