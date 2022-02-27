//TP 2018/2019: ZSR 1, Zadatak 13
#include <iostream>
#include <cmath>

int main ()
{
    double suma,k=0,sredina;
    double x,proizvod=1,korijen;
    do {
        std::cout << "Unesite broj x: ";
        std::cin >> x;
        if (x==0) break;
        k++;
        suma+=x;
        proizvod*=x;
        
    } while (x!=0);
    sredina=suma/k;
    korijen=pow(proizvod,1/k);
    std::cout << sredina << std::endl;
    std::cout << korijen;
    
	return 0;
}