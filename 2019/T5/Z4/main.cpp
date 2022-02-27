/*
    TP 2018/2019: Tutorijal 5, Zadatak 4

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
#include <deque>
#include <algorithm>
#include <cmath>

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int n;
	std::cin >> n;
	std::deque<int> d1(n);
	std::cout << "Unesite elemente: ";
	std::deque<int>::iterator pocetak=d1.begin(), iza_kraja=d1.end();
	std::for_each(pocetak,iza_kraja,[](int &a) {
		std::cin >> a;
	});
	std::cout << "Najveci element deka je " << *std::max_element(pocetak,iza_kraja) << std::endl;
	int p=*std::min_element(pocetak,iza_kraja);
	std::cout << "Najmanji element deka se pojavljuje " << std::count(pocetak,iza_kraja,p) << " puta u deku" << std::endl;
	std::cout << "U deku ima " << std::count_if(pocetak,iza_kraja,[](int b) {
		const double EPSILON=0.00001;
		return(std::sqrt(b)-int(std::sqrt(b))>-EPSILON && std::sqrt(b)-int(std::sqrt(b))<EPSILON);
	}) << " brojeva koji su potpuni kvadrati" << std::endl;
	std::cout << "Prvi element sa najmanjim brojem cifara je " << *(min_element(pocetak,iza_kraja,[](int x,int y) {
		return int(log10(abs(x)))<int(log10(abs(y)));
	})) << std::endl;
	std::deque<int> d2(n);
	std::deque<int>::iterator pocetak1=d2.begin(), iza_kraja1=std::remove_copy_if(pocetak,iza_kraja,pocetak1,[] (int a) {
		return int(log10(abs(a))+1)==3;
	});
	std::cout << "Elementi koji nisu trocifreni su: ";
	std::for_each(pocetak1,iza_kraja1,[](int x) {
		std::cout << x << " ";
	});

	return 0;
}
