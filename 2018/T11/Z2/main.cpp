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
		if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		stanje =x;
		kreiranih++;
		aktivnih++;
	}
	StedniRacun(const StedniRacun &s)
	{
		stanje=s.stanje;
		kreiranih ++;
		aktivnih++;
	}
	~StedniRacun()
	{
		aktivnih--;
	}
	StedniRacun &Ulozi (double x)
	{
		if(x+stanje<0) throw std::logic_error("Transakcija odbijena");
		stanje+=x;
		return *this;
	}
	StedniRacun &Podigni (double x)
	{
		if(x>stanje) throw std::logic_error("Transakcija odbijena");
		stanje-=x;
		return *this;
	}
	double DajStanje() const
	{
		return stanje;
	}
	StedniRacun ObracunajKamatu (double x)
	{
		if(x<0) throw std::logic_error ("Nedozvoljena kamatna stopa");
		stanje+=stanje*x/100;
		return *this;
	}
	static int DajBrojAktivnih()
	{
		return aktivnih;
	}
	static int DajBrojKreiranih()
	{
		return kreiranih;
	}
};
int main ()
{
	double x;
	std::cout << "Unesite pocetnu kolicinu novca: ";
	std::cin >> x;
	auto banka=StedniRacun(x);
	StedniRacun racun2(10);
	int unos;
	do {
		std::cout << std::endl << "Welcome! Unesite zeljenu opciju (1 za uplatu, 2 za podizanje novca, 3 za provjeru stanja, 4 za provjeru kamatne stope, 0 za izlaz): ";
		std::cin >> unos;
		if(unos==0) break;
		else if(unos==1) {
			double n;
			std::cout << std::endl << "Unesite zeljenu kolicinu novca: ";
			std::cin >> n;
			banka.Ulozi(n);
		} else if(unos==2) {
			double n;
			std::cout << std::endl << "Unesite zeljenu kolicinu novca: ";
			std::cin >> n;
			banka.Podigni(n);
		} else if(unos==3) {
			std::cout << std::endl <<"Vase trenutno stanje je: " << banka.DajStanje();
		} else if (unos==4) {
			double n;
			std::cout << std::endl << "Unesite zeljenu kamatnu stopu: ";
			std::cin >> n;
			banka.ObracunajKamatu(n);
		}
	} while (1);
	std::cout << std::endl << "Kreiranih je: " << StedniRacun::DajBrojKreiranih() << " a aktivnih je: " << StedniRacun::DajBrojAktivnih();
	return 0;
}
