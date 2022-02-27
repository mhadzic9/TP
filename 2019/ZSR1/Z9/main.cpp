//TP 2018/2019: ZSR 1, Zadatak 9
#include <iostream>

int main ()
{
    int broj,k=2;
    std::cout << "Unesite neki broj: ";
    std::cin >> broj;
    while (broj!=0) {
        if (broj%k==0) {
            std::cout << k << " ";
            broj/=k;
        }
        else {
            k++;
        }
        if (broj<k) break;
    }
    
	return 0;
}