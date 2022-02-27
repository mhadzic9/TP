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

int SumaCifara (int a)
{
	if (a==0) return 0;
	return (abs(a%10)+SumaCifara(a/10));
}

bool Poredak (int x, int y)
{
	if (SumaCifara(x)<SumaCifara(y)) return true;
	if (SumaCifara(x)==SumaCifara(y) && x<y) return true;
	return false;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::vector<int> v(n);
	std::cout << "Unesite elemente: ";
	std::for_each (v.begin(),v.end(),[](int &x) {
		std::cin >> x;
	});
	std::sort(v.begin(),v.end(),Poredak);
	std::cout << "Niz sortiran po sumi cifara glasi: ";
	std::for_each(v.begin(),v.end(),[](int &x) {
		std::cout << x << " ";
	});
	std::cout << std::endl;
	int x;
	std::cout << "Unesite broj koji trazite: ";
	std::cin >> x;
	if (std::binary_search(v.begin(),v.end(),x,Poredak)) {
		auto pozicija=std::lower_bound(v.begin(),v.end(),x,Poredak);
		std::cout << "Trazeni broj nalazi se na poziciji " << pozicija-v.begin();
	} else {
		std::cout << "Trazeni broj ne nalazi se u nizu!";
	}

	return 0;
}
