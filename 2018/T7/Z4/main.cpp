/*
    TP 16/17 (Tutorijal 7, Zadatak 4)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <memory>
#include <algorithm>


bool ASCII(const char *a, const char *b)
{
	return std::strcmp(a,b)<0;
}
typedef std::unique_ptr<std::shared_ptr<std::string>> USpointer;
typedef std::shared_ptr<std::string> Spointer;

int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::cout<<"Unesite recenice:" << std::endl;
	try {
		std::unique_ptr<std::shared_ptr<std::string>[]>tekst(new std::shared_ptr<std::string> [n]);
		try {
			for(int i=0; i<n; i++) {
				tekst[i]=std::make_shared<std::string>();
				std::getline(std::cin, *tekst[i]);
			}
			auto p1=tekst.get();
			std::sort(p1,p1+n,[](const std::shared_ptr<std::string> a, const std::shared_ptr<std::string> b) {
				return *a<=*b;
			});

			std::cout<<"Sortirane recenice:"<<std::endl;
			for(int i=0; i<n; i++) {
				std::cout<<tekst[i]<<std::endl;
			}

		} catch(std::bad_alloc) {
			std::cout << "Problemi s memorijom!";
		}
	} catch (std::bad_alloc) {

		std::cout << "Problemi s memorijom!";

	}



	return 0;
}
