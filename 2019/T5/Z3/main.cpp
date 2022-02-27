/*
    TP 2018/2019: Tutorijal 5, Zadatak 3

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
#include <cmath>
#include <vector>

void Unos(int &a)
{
	std::cin >> a;
}
bool PotpunKvadrat (int b)
{
	const double EPSILON=0.00001;
	if (std::sqrt(b)-int(std::sqrt(b))>-EPSILON && std::sqrt(b)-int(std::sqrt(b))<EPSILON) return true;
	return false;
}
int BrojCifara (int c)
{
	c=abs(c);
	return std::log10(c)+1;
}
bool ManjiBrojCifara (int x, int y)
{
	if (BrojCifara(x)<BrojCifara(y)) return true;
	return false;
}

bool DaLiJeTrocifreni (int d)
{
	if (BrojCifara(d)==3) return true;
	return false;
}
void Ispis (int e)
{
	std::cout << e << " ";
}

int main ()
{
	std::cout << "Unesite broj elemenata (max. 1000): ";
	int n;
	std::cin >> n;
	int niz1[1000];
	std::cout << "Unesite elemente: ";
	int *pocetak1=niz1,*iza_kraja1=niz1+n;
	std::for_each(pocetak1,iza_kraja1,Unos);
	std::cout << "Najveci element niza je " << *std::max_element(pocetak1,iza_kraja1) << std::endl;
	int p=*std::min_element(pocetak1,iza_kraja1);
	std::cout << "Najmanji element niza se pojavljuje " << std::count(pocetak1,iza_kraja1,p) << " puta u nizu" << std::endl;
	std::cout << "U nizu ima " << std::count_if(pocetak1,iza_kraja1,PotpunKvadrat) << " brojeva koji su potpuni kvadrati" << std::endl;
	std::cout << "Prvi element sa najmanjim brojem cifara je " << *(std::min_element(pocetak1,iza_kraja1,ManjiBrojCifara)) << std::endl;
	int niz2[1000];
	int *pocetak2=niz2, *iza_kraja2=std::remove_copy_if(pocetak1,iza_kraja1,pocetak2,DaLiJeTrocifreni);
	std::cout << "Elementi koji nisu trocifreni su: ";
	std::for_each(pocetak2,iza_kraja2,Ispis);

	return 0;
}
