/*
    TP 16/17 (Tutorijal 7, Zadatak 3)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite recenice: " << std::endl;
	try {
		std::string** recenica=new std::string*[n];
		try {
			for (int i=0; i<n; i++) {
				recenica[i]=new std::string();
				std::getline(std::cin,*recenica[i]);
			}
			std::sort (recenica,recenica+n, [] (std::string* a,std::string *b) {
				return *a<=*b;
			});

			std::cout << "Sortirane recenice: " << std::endl;
			for (int i=0; i<n; i++) {
				std::cout << *recenica[i] << std::endl;
			}
			for (int i=0; i<n; i++) {
				delete recenica[i];
			}
			delete [] recenica;

		} catch (std::bad_alloc) {
			std::cout << "Problemi s memorijom!";
		}
	} catch (std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
	}

	return 0;
}
