/*
    TP 16/17 (Tutorijal 7, Zadatak 4)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <memory>

typedef std::shared_ptr<std::string> Grupni;
typedef std::unique_ptr<std::shared_ptr<std::string>[]> Jedinstveni;

int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite recenice: " << std::endl;
	try {
		Jedinstveni recenica(new Grupni [n]);
		try {
			for (int i=0; i<n; i++) {
				recenica[i]=std::make_shared<std::string>();
				std::getline(std::cin,*recenica[i]);
			}
			auto p=recenica.get();
			std::sort (p,p+n, [] (std::shared_ptr<std::string> a,std::shared_ptr<std::string> b) {
				return *a<=*b;
			});

			std::cout << "Sortirane recenice: " << std::endl;
			for (int i=0; i<n; i++) {
				std::cout << *recenica[i] << std::endl;
			}

		} catch (std::bad_alloc) {
			std::cout << "Problemi s memorijom!";
		}
	} catch (std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
	}

	return 0;
}
