/*
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
int aktivnih(0),kreiranih(0);

class StedniRacun
{
	double stanje;
public:
	StedniRacun(double x=0)
	{
		if (x<0) throw std::logic_error ("Nedozvoljeno pocetno stanje");
		stanje=x;
		kreiranih++;
		aktivnih++;
	}
	StedniRacun(const StedniRacun &s)
	{
		stanje=s.stanje;
		kreiranih++;
		aktivnih++;
	}
	~StedniRacun()
	{
		aktivnih--;
	}
	StedniRacun &Ulozi(double x)
	{
		if (x+stanje<0) throw std::logic_error ("Transakcija odbijena");
		stanje+=x;
		return *this;
	}
	StedniRacun &Podigni(double x)
	{
		if (x>stanje) throw std::logic_error ("Transakcija odbijena");
		stanje-=x;
		return *this;
	}
	double DajStanje () const
	{
		return stanje;
	}
	StedniRacun ObracunajKamatu(double x)
	{
		if (x<0) throw std::logic_error ("Nedozvoljena kamatna stopa");
		stanje+=stanje*x/100;
		return *this;
	}
	static int DajBrojAktivnih()
	{
		return aktivnih;
	}
	static int DajBrojKreiranih ()
	{
		return kreiranih;
	}
};

int main ()
{
	return 0;
}
