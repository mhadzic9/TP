//TP 2018/2019: ZSR 1, Zadatak 2
#include <iostream>

int main ()
{
    int cvorovi;
    std::cout << "Unesite broj cvorova: ";
    std::cin >> cvorovi;
    double km_h=cvorovi*1.852;
    std::cout << "Brzina broda u km/h iznosi " << km_h;
    
	return 0;
}