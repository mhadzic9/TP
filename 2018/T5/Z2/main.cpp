/*
    TP 2018/2019: Tutorijal 5, Zadatak 2

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
#include <vector>
#include <deque>
#include <algorithm>

template <typename Tip1, typename Tip2>
void Razmijeni(Tip1 &p1,Tip2 &p2)
{
	Tip1 temp=p1;
	p1=p2;
	p2=temp;
}
template <typename IterP1,typename IterP2>
IterP2 RazmijeniBlokove(IterP1 p1,IterP1 p2, IterP2 p3)
{
	while(p1!=p2) {
		Razmijeni(*p1,*p3);
		p1++;
		p3++;
	}
	return p3;
}
int main ()
{
	std::vector <int> vek1{1,2,3,4,5};
	std::vector <int> vek2{6,7,8,9,10};
	RazmijeniBlokove(std::begin(vek1),std::end(vek1),std::begin(vek2));
	return 0;
}
