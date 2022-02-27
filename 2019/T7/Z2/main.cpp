/*
    TP 16/17 (Tutorijal 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>


int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite recenice: " << std::endl;
	try {
		char** recenica=new char*[n];
		try {
			for (int i=0; i<n; i++) {
				char niz[1000];
				std::cin.getline(niz,sizeof niz);
				recenica[i]=new char [std::strlen(niz)+1];
				std::strcpy(recenica[i],niz);
			}
			std::sort (recenica,recenica+n, [] (const char* a,const char *b) {
				return std::strcmp(a,b)<0;
			});

			std::cout << "Sortirane recenice: " << std::endl;
			for (int i=0; i<n; i++) {
				std::cout << recenica[i] << std::endl;
			}
			for (int i=0; i<n; i++) {
				delete [] recenica[i];
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
