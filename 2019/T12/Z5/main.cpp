/*
    TP 16/17 (Tutorijal 12, Zadatak 5)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main ()
{
	int br_elemenata;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> br_elemenata;
	double element;
	std::vector<double> v;
	std::cout << "Unesite elemente: ";
	for (int i=0; i<br_elemenata; i++) {
		std::cin >> element;
		v.push_back(element);
	}
	std::transform (v.begin(),v.end(),v.begin(),std::bind(std::divides<double>(),1,std::placeholders::_1));
	std::cout << "Transformirani elementi: ";
	for (int i=0; i<br_elemenata; i++) std::cout << v[i] << " ";

	return 0;
}
