//TP 2018/2019: ZSR 1, Zadatak 14
#include <iostream>

int main ()
{
    int n,naopako=0,c,tmp;
    std::cout << "Unesite broj n: ";
    std::cin >> n;
    tmp=n;
    while (n!=0) {
        c=n%10;
        naopako=naopako*10+c;
        n/=10;
    }
    if (naopako==tmp) {
        std::cout << "Broj " << tmp << " je palindroman broj."; 
    }
    else {
        std::cout << "Broj " << tmp << " nije palindroman broj."; 
    }
    
	return 0;
}