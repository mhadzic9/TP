/*
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

class Krug
{
	double r;
public:
	friend class Valjak;
	explicit Krug (double x)
	{
		if (x<=0) throw std::domain_error ("Neispravan poluprecnik");
		r=x;
	}
	Krug &Postavi (double x)
	{
		if (x<=0) throw std::domain_error ("Neispravan poluprecnik");
		r=x;
		return *this;
	}
	double DajPoluprecnik () const
	{
		return r;
	}
	double DajObim () const
	{
		return 2*r*4*std::atan(1);
	}
	double DajPovrsinu () const
	{
		return r*r*4*std::atan(1);
	}
	Krug &Skaliraj (double faktor)
	{
		if (faktor<=0) throw std::domain_error ("Neispravan faktor skaliranja");
		r*=faktor;
		return *this;
	}
	void Ispisi () const
	{
		std::cout << std::fixed << std::setprecision(5) << "R=" << this->DajPoluprecnik() << std::fixed << std::setprecision(5) << " O=" << this->DajObim() << " P=" << this->DajPovrsinu();
	}
};
class Valjak
{
	Krug baza;
	double visina;
public:
	friend class Krug;
	Valjak (double r,double x): baza(r)
	{
		if (x<0) throw std::domain_error ("Neispravna visina");
		visina=x;
	}
	Valjak &Postavi (double y, double x)
	{
		this->baza.Postavi(y);
		if (x<0) throw std::domain_error ("Neispravna visina");
		visina=x;
		return *this;
	}
	Krug DajBazu () const
	{
		return baza;
	}
	double DajPoluprecnikBaze () const
	{
		return this->baza.DajPoluprecnik();
	}
	double DajVisinu () const
	{
		return visina;
	}
	double DajPovrsinu () const
	{
		return 2*this->baza.DajPovrsinu()+visina*this->baza.DajObim();
	}
	double DajZapreminu () const
	{
		return this->baza.DajPovrsinu()*visina;
	}
	Valjak &Skaliraj (double faktor)
	{
		if (faktor<=0) throw std::domain_error ("Neispravan faktor skaliranja");
		this->baza.Skaliraj(faktor);
		visina*=faktor;
		return *this;
	}
	void Ispisi () const
	{
		std::cout << std::fixed << std::setprecision(5) << "R=" << this->baza.DajPoluprecnik() << std::fixed << std::setprecision(5) << " H=" << this->DajVisinu() << " P=" << DajPovrsinu() << " V=" << this->DajZapreminu();
	}
};

int main ()
{
	Krug k(5);
	Valjak v(6,10);
	v.Postavi(7,10);
	v.Skaliraj(1.2);
	k.Ispisi();
	std::cout << std::endl;
	v.Ispisi();
	k.Skaliraj(2);
	std::cout << " R kruga pomnozen sa 2: " << k.DajPoluprecnik() << " Novi obim: " << k.DajObim() << " Nova povrsina: " << k.DajPovrsinu();
	k.Postavi(5);
	const Valjak v2(5,15);
	k=v2.DajBazu();
	std::cout << "\nPoluprecnik baze valjka: " << v.DajPoluprecnikBaze() << " Visina: " << v.DajVisinu() << " Povrsina: " << v.DajPovrsinu() << " Zapremina: " << v.DajZapreminu();

	return 0;
}
