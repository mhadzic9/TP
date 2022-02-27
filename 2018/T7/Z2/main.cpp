/*
    TP 16/17 (Tutorijal 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <algorithm>

int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::cout<<"Unesite recenice:" << std::endl;
	try {
		char **tekst=new char*[n];
		try {
			for(int i=0; i<n; i++) {
				char recenica [1000];
				std::cin.getline(recenica, sizeof recenica);
				tekst[i]=new char[std::strlen(recenica)+1];
				std::strcpy(tekst[i],recenica);
			}
			std::sort(&tekst[0],&tekst[n],[](const char *a, const char *b) {
				return std::strcmp(a,b) < 0;
			});


			std::cout<<"Sortirane recenice:"<<std::endl;
			for(int i=0; i<n; i++) {
				std::cout<<tekst[i]<<std::endl;
			}
			for(int j=0; j<n; j++) {
				delete [] tekst[j];
			}
			delete [] tekst;
		} catch(std::bad_alloc) {
			std::cout << "Problemi s memorijom!";
		}
	} catch (std::bad_alloc) {

		std::cout << "Problemi s memorijom!";

	}



	return 0;
}
