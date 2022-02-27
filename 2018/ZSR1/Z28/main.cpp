#include <iostream>

int main ()
{
    int a,b;
    std::cout << "Unesite dva broja: ";
    std::cin >> a >> b;
    if (a>b) {
        while (b!=0) {
            a--;
            std::cout << a << "\n";
            b--;
        }
    }
    if (a<b) {
        while (a!=0) {
            b--;
            std::cout << b << "\n";
            a--;
        }
    }
    
	return 0;
}
