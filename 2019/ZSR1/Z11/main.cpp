//TP 2018/2019: ZSR 1, Zadatak 11 
#include <iostream>
#include <cmath>

int main ()
{
    int n=0,k=0;
    double x,clan=1;
    std::cout << "Unesite broj x: ";
    std::cin >> x;
    double F=pow(2.71828,x);
    double S=0;
    for (;;) {
        S+=clan;
        if (S-F>0) break;
        k++;
        n++;
        clan*=x/k;
    }
   std::cout << "Minimalna vrijednost takva da se S i F poklapaju na barem prvih 5 decimala je " << n;
  
    
	return 0;
}