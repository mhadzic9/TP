/*
    TP 16/17 (Tutorijal 7, Zadatak 3)
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
		std::string **tekst=new std::string*[n];
		try {
			for(int i=0; i<n; i++) {
				tekst[i]=new std::string();
				std::getline(std::cin, *tekst[i]);
			}
			std::sort(tekst,tekst+n,[](std::string* a, std::string *b) {
				return *a<=*b;
			});


			std::cout<<"Sortirane recenice:"<<std::endl;
			for(int i=0; i<n; i++) {
				std::cout<<*tekst[i]<<std::endl;
			}
			for(int j=0; j<n; j++) {
				delete tekst[j];
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
