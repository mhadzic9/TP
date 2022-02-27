//TP 2018/2019: ZSR 1, Zadatak 7
#include <iostream>
#include <iomanip>
#include <cmath>

int main ()
{
    double G,p;
    std::cout << "Unesite vrijednost glavnice: ";
    std::cin >> G;
    std::cout << "Unesite kamatnu stopu: ";
    std::cin >> p;
    double kamata=(G*p)/100;
    double S=G+kamata;
    std::cout << "Glavnica: " << std::setw(10) << G << std::endl;
    std::cout << "Kamatna stopa: " << std::setw(5) << p << std::endl;
    std::cout << "Kamate: " << std::setw(12) << round(kamata) << std::endl;
    std::cout << "Nova svota: " << std::setw(8) << round(S);
    
	return 0;
}