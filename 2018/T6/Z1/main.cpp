/*
    TP 2018/2019: Tutorijal 6, Zadatak 1

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <new>
#include <limits>
#include <iomanip>
#include <stdexcept>
template <typename Tip>
Tip *GenerirajStepeneDvojke(int n)
{
	if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
	Tip *niz=nullptr;
	try {
		niz=new Tip[n];
	} catch (std::bad_alloc) {
		std::runtime_error ("Alokacija nije uspjela");
	}
	Tip neki=1;
	for(int i=0; i<n; i++) {
		if(neki>std::numeric_limits<Tip>::max()/2 && i<n-1) {
			delete [] niz;
			throw std::overflow_error("Prekoracen dozvoljeni opseg");
		}
		niz[i]=neki;
		neki*=2;
	}
	return niz;
}
int main ()
{
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	unsigned long long *pok;
	try {
		pok=GenerirajStepeneDvojke<unsigned long long>(n);
		for (int i=0; i<n; i++) {
			std::cout << pok[i] << " ";
		}
	} catch(std::exception &e) {
		std::cout << "Izuzetak: " << e.what();
		return 0;
	}
	delete [] pok;
	return 0;
}
