/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
template <typename Tip>
auto KreirajIzvrnutiNiz(Tip n1, Tip n2) -> typename std::remove_reference<decltype(*n1)>::type*
{
	typename std::remove_reference<decltype(*n1)>::type *niz=nullptr;
	int broj_elemenata=0;
	Tip pomocna=n1;
	while(pomocna!=n2) {
		pomocna++;
		broj_elemenata++;
	}
	niz=new typename std::remove_reference<decltype(*n1)>::type[broj_elemenata];
	for(int i=broj_elemenata-1; i>=0; i--) {
		niz[i]=*n1;
		n1++;
	}
	return niz;
}
int main ()
{
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	std::vector<double> vektor;
	try {
		vektor.resize(n);
		std::cout << "Unesite elemente: ";
		for(int i=0; i<n; i++) {
			std::cin >> vektor[i];
		}
		auto *niz=KreirajIzvrnutiNiz(vektor.begin(),vektor.end());
		std::cout << "Kreirani niz: ";
		for(int i=0; i<vektor.size(); i++) {
			std::cout << niz[i] << " ";
		}
		delete [] niz;
	} catch (...) {
		std::cout << "Nedovoljno memorije!";
	}
	return 0;
}
