/*
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun
{
	double stanje;
public:
	StedniRacun (double x=0)
	{
		if (x<0) throw std::logic_error ("Nedozvoljeno pocetno stanje");
		stanje=x;
	}
	StedniRacun &Ulozi (double x)
	{
		if ((x+stanje)<0) throw std::logic_error ("Transakcija odbijena");
		stanje+=x;
		return *this;
	}
	StedniRacun &Podigni (double x)
	{
		if (x>stanje) throw std::logic_error ("Transakcija odbijena");
		stanje-=x;
		return *this;
	}
	double DajStanje () const
	{
		return stanje;
	}
	StedniRacun &ObracunajKamatu (double k_stopa)
	{
		if (k_stopa<0) throw std::logic_error ("Nedozvoljena kamatna stopa");
		stanje+=stanje*k_stopa/100;
		return *this;
	}
};

int main ()
{
	try {
		StedniRacun n(150);
		n.Ulozi(40);
		n.Podigni(100);
		n.ObracunajKamatu(5);
		std::cout << "Stanje: " << n.DajStanje() << " ";
		const StedniRacun m;
		std::cout << m.DajStanje();
	}
	catch (std::logic_error izuzetak) {
		std::cout << izuzetak.what();
	}
	
	return 0;
}
