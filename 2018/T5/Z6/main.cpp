/*
    TP 2018/2019: Tutorijal 5, Zadatak 6

	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.

	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.

			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <algorithm>
#include <vector>
int sumacifri(int n)
{
	if(n==0) return 0;
	return(abs(n%10)+sumacifri(n/10));
}
bool Poredak(int a, int b)
{
	if(sumacifri(a)<sumacifri(b)) return true;
	if(sumacifri(a)==sumacifri(b) && a<b) return true;
	return false;
}

int main ()
{
	int broj_elemenata,neki_broj;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> broj_elemenata;
	std::vector<int> v(broj_elemenata);
	std::cout << "Unesite elemente: ";
	std::for_each(v.begin(),v.end(),[](int &x) {
		std::cin >> x;
	});
	std::sort(v.begin(),v.end(),Poredak);
	std::cout << "Niz sortiran po sumi cifara glasi: ";
	std::for_each(v.begin(),v.end(),[](int &x) {
		std::cout << x << " ";

	});
	std::cout<<std::endl<<"Unesite broj koji trazite: ";
	std::cin >> neki_broj;

	if(std::binary_search(v.begin(),v.end(),neki_broj,Poredak)) {
		auto pozicija=std::lower_bound(v.begin(),v.end(),neki_broj,Poredak);
		std::cout << "Trazeni broj nalazi se na poziciji " << pozicija-v.begin();
	} else {
		std::cout << "Trazeni broj ne nalazi se u nizu!";
	}
	return 0;
}
