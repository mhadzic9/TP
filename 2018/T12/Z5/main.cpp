/* 
    TP 16/17 (Tutorijal 12, Zadatak 5)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <functional>
#include <algorithm>

int main () {
	std::cout << "Koliko zelite elemenata: ";
	int n;
	std::cin >> n;
	double* niz(nullptr);
	try {
		niz=new double[n];
		std::cout << "Unesite elemente: ";
		for(int i=0;i<n;i++) 
		std::cin >> niz[i];
		std::transform (niz,niz+n,niz,std::bind1st(std::divides<double>(),1));
		std::cout << "Transformirani elementi: ";
		for(int i=0;i<n;i++)
		std::cout << niz[i] << " ";
	} catch(...) {
		std::cout << "Nema memorije!!";
	}
	delete[] niz;
	return 0;
}
int imain() {
	std::cout << "Unesite broj elemenata: ";
	int broj;
	std::cin >> broj;
	double* niz(nullptr);
	try {
		niz=new double[broj];
		for(int i=0;i<broj;i++)
		std::cin >> niz[i];
		std::transform(niz,niz+broj,niz,std::bind(std::divides<double>(),1,std::placeholders::_1));
		for(int i=0;i<broj;i++)
		std::cout << niz[i] << " ";
		
	} catch (...){
		std::cout << "Nema memorije!!";
	}
	delete[] niz;
}