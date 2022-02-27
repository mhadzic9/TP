/*
    TP 2018/2019: Tutorijal 6, Zadatak 1

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <limits>

template <typename Tip>
Tip *GenerirajStepeneDvojke (int n)
{
	if (n<=0) throw std::domain_error ("Broj elemenata mora biti pozitivan");
	Tip *niz=nullptr;
	try {
		niz=new Tip[n];
	} catch (std::bad_alloc) {
		throw std::runtime_error ("Alokacija nije uspjela");
	}
	Tip clan=1;
	for (int i=0; i<n; i++) {
		if (clan>std::numeric_limits<Tip>::max()/2 && i<n-1) {
			delete [] niz;
			throw std::overflow_error ("Prekoracen dozvoljeni opseg");
		}
		niz[i]=clan;
		clan*=2;
	}
	return niz;
}

int main ()
{
	std::cout << "Koliko zelite elemenata: ";
	int n;
	std::cin >> n;
	unsigned long long *pok;
	try {
		pok=GenerirajStepeneDvojke<unsigned long long>(n);
		for (int i=0; i<n; i++) {
			std::cout << pok[i] << " ";
		}
	} catch (std::overflow_error izuzetak1) {
		std::cout << "Izuzetak: " << izuzetak1.what();
		return 0;
	} catch (std::runtime_error izuzetak2) {
		std::cout << "Izuzetak: " << izuzetak2.what();
		return 0;
	} catch (std::domain_error izuzetak3) {
		std::cout << "Izuzetak: " << izuzetak3.what();
		return 0;
	}
	delete [] pok;


	return 0;
}
