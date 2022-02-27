/*
    TP 16/17 (Tutorijal 7, Zadatak 5)
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

int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite recenice: " << std::endl;
	try {
		std::shared_ptr<std::shared_ptr<std::string>> recenica(new std::shared_ptr<std::string>[n] {},
		[](std::shared_ptr<std::string> *p) {
			delete [] p;
		});
		try {
			for (int i=0; i<n; i++) {
				recenica.get()[i]=std::make_shared<std::string>();
				std::getline(std::cin,*recenica.get()[i]);
			}
		} catch (std::bad_alloc) {
			for (int i=0; i<n; i++) recenica.get()[i]=nullptr;
			recenica=nullptr;
			throw;
		}
		std::sort (recenica.get(),recenica.get()+n, [] (std::shared_ptr<std::string> a,std::shared_ptr<std::string> b) {
			return *a<*b;
		});

		std::cout << "Sortirane recenice: " << std::endl;
		for (int i=0; i<n; i++) {
			std::cout << *recenica.get()[i] << std::endl;
		}


	} catch (...) {
		std::cout << "Problemi s memorijom!";
	}

	return 0;
}
