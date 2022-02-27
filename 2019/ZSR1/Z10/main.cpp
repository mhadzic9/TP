//TP 2018/2019: ZSR 1, Zadatak 10
#include <iostream>

int main ()
{
    int broj,k=2;
    std::cout << "Unesite neki broj: ";
    std::cin >> broj;
    while (broj>=k) {
        if (broj%k==0) {
            for(;;) {
                broj/=k;
                if(broj%k!=0) break;
            }
            std::cout << k << " ";
        }
        else {
            k++;
        }
    }
    
	return 0;
}