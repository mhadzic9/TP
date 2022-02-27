/*
    TP 2018/2019: Tutorijal 5, Zadatak 5

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
#include <cmath>
#include <iomanip>
double TrapeznoPravilo(double fun(double),double a,double b,int n)
{
	double suma=0;
	for(int k=1; k<n; k++) {
		suma+=fun(a+((b-a)/n)*k);
	}
	double integral=((b-a)/n)*(0.5*fun(a)+0.5*fun(b)+suma);
	if(integral<=0.00001)
		integral=0;
	return integral;
}
int main ()
{
	int n;
	std::cout << "Unesite broj podintervala: ";
	std::cin >> n;
	const double PI=4*atan(1);
	std::cout << "Za taj broj podintervala priblizne vrijednosti integrala iznose:" << std::endl;
	std::cout << "- Za funkciju sin x na intervalu (0,pi): " << std::fixed << std::setprecision(5) <<TrapeznoPravilo(std::sin,0,PI,n) << std::endl;
	std::cout << "- Za funkciju x^3 na intervalu (0,10): " << std::fixed << std::setprecision(2) << TrapeznoPravilo([](double x) {
		return x*x*x;
	},0,10,n) << std::endl;
	std::cout << "- Za funkciju 1/x na intervalu (1,2): " << std::fixed << std::setprecision(5) << TrapeznoPravilo([](double x) {
		return 1/x;
	},1,2,n) << std::endl;
	return 0;
}
