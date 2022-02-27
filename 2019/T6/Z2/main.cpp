/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
#include <new>

template <typename Tip>
auto KreirajIzvrnutiNiz (Tip pocetak,Tip iza_kraja) -> typename std::remove_reference<decltype(*pocetak)>::type*
{
	typename std::remove_reference<decltype(*pocetak)>::type *niz=nullptr;
	int broj_elemenata=0;
	Tip pomocna=pocetak;
	while (pomocna!=iza_kraja) {
		pomocna++;
		broj_elemenata++;
	}
	try {
	niz=new typename std::remove_reference<decltype(*pocetak)>::type[broj_elemenata];
	for (int i=0;i<broj_elemenata;i++) {
		niz[broj_elemenata-i-1]=*pocetak++;
	}
	}
	catch (std::bad_alloc) {
		delete [] niz;
		throw;
	}
	return niz;

}

int main ()
{
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	try {
		std::vector<double> v(n);
		std::cout << "Unesite elemente: ";
		for (int i=0;i<n;i++) {
			double a;
			std::cin >> a;
			v.push_back(a);
		}
	
		double *pok=KreirajIzvrnutiNiz(v.begin(),v.end());
		std::cout << "Kreirani niz: ";
		for (int i=0;i<n;i++) {
			std::cout << pok[i] << " ";
		}
		delete [] pok;
	}
	catch (std::bad_alloc) {
		std::cout << "Nedovoljno memorije!";
	}
	
	return 0;
}
