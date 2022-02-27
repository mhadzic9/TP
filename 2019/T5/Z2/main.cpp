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

template<typename Tip1,typename Tip2>
void Razmijeni(Tip1 &tip1,Tip2 &tip2)
{
	Tip1 tmp=tip1;
	tip1=tip2;
	tip2=tmp;
}

template<typename A,typename B>
B RazmijeniBlokove(A q1,A q2,B q3)
{
	while (q1!=q2) {
		Razmijeni(*q1,*q3);
		q1++;
		q3++;
	}
	return q3;
}

int main ()
{
	std::vector<int> v1{1,2,3,4,5};
	std::vector<int> v2{6,7,8,9,19};
	RazmijeniBlokove(v1.begin(),v1.end(),v2.begin());
	std::cout << "Prvi kontejner: ";
	for(int x : v1) std::cout << x << " ";
	std::cout << "\nDrugi kontejner: ";
	for(int x : v2) std::cout << x << " ";
	std::cout << std::endl;
	std::string s1="string1";
	std::string s2="string2";
	RazmijeniBlokove(s1.begin(),s1.end(),s2.begin());
	std::cout << "Prvi kontejner: ";
	for(char x : s1) std::cout << x;
	std::cout << "\nDrugi kontejner: ";
	for(char x : s2) std::cout << x;
	std::cout << std::endl;

	return 0;
}
