/*
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <string>

class Lik
{
public:
	virtual ~Lik() {};
	virtual void IspisiSpecificnosti() const=0;
	virtual double DajObim() const=0;
	virtual double DajPovrsinu() const=0;
	virtual void Ispisi()
	{
		std::cout << std::endl;
		IspisiSpecificnosti();
		std::cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu() << std::endl;
	}
};
class Krug:public Lik
{
	double r;
	static constexpr double PI=4*atan(1);
public:
	Krug (double r)
	{
		if (r<=0) throw std::domain_error ("Neispravni parametri");
		Krug::r=r;
	}
	void IspisiSpecificnosti () const override
	{
		std::cout << "Krug poluprecnika " << r << std::endl;
	}
	double DajObim() const override
	{
		return 2*r*PI;
	}
	double DajPovrsinu() const override
	{
		return r*r*PI;
	}
};
class Pravougaonik:public Lik
{
	double a,b;
public:
	Pravougaonik(double a,double b)
	{
		if (a<=0 || b<=0) throw std::domain_error ("Neispravni parametri");
		Pravougaonik::a=a;
		Pravougaonik::b=b;
	}
	void IspisiSpecificnosti() const override
	{
		std::cout << "Pravougaonik sa stranicama duzine " << a <<" i " << b << std::endl;
	}
	double DajObim() const override
	{
		return 2*a+2*b;
	}
	double DajPovrsinu() const override
	{
		return a*b;
	}
};
class Trougao:public Lik
{
	double a,b,c;
public:
	Trougao (double a,double b, double c)
	{
		if (a+b>c && a+c>b && b+c>a) {
			Trougao::a=a;
			Trougao::b=b;
			Trougao::c=c;
		} else throw std::domain_error ("Neispravni parametri");
	}
	void IspisiSpecificnosti() const override
	{
		std::cout << "Trougao sa stranicama duzine " << a << ", " << b << " i " << c << std::endl;
	}
	double DajObim () const override
	{
		return a+b+c;
	}
	double DajPovrsinu() const override
	{
		double s=DajObim()/2;
		return std::sqrt(s*(s-a)*(s-b)*(s-c));
	}
};

int main ()
{
	std::vector<std::shared_ptr<Lik>> v;
	int br_likova;
	std::cout << "Koliko zelite likova: ";
	std::cin >> br_likova;
	for (int i=0; i<br_likova; i++) {
		std::cin.ignore(10000,'\n');
		std::cin.clear();
		std::cout << "Lik " << i+1 << ": ";
		char znak;
		std::cin >> znak;
		if (znak=='K') {
			double r;
			std::cin >> r;
			if ((std::cin.peek())!='\n') {
				std::cout << "Pogresni podaci, ponovite unos!\n";
				i--;
				continue;
			}
			try {
				v.push_back(std::make_shared<Krug>(r));
			} catch (std::domain_error) {
				std::cout << "Pogresni podaci, ponovite unos!\n";
				i--;
				continue;
			}
		} else if (znak=='P') {
			double a,b;
			std::cin >> a >> znak >> b;
			if ((std::cin.peek()!='\n') || znak!=',') {
				std::cout << "Pogresni podaci, ponovite unos!\n";
				i--;
				continue;
			}
			try {
				v.push_back(std::make_shared<Pravougaonik>(a,b));
			} catch (std::domain_error) {
				std::cout << "Pogresni podaci, ponovite unos!\n";
				i--;
				continue;
			}
		} else if (znak=='T') {
			double a,b,c;
			std::cin >> a >> znak;
			if (znak==',') std::cin >> b >> znak;
			if (znak==',') std::cin >> c;
			if ((std::cin.peek()!='\n') || znak!=',') {
				std::cout << "Pogresni podaci, ponovite unos!\n";
				i--;
				continue;
			}
			try {
				v.push_back(std::make_shared<Trougao>(a,b,c));
			} catch (std::domain_error) {
				std::cout << "Pogresni podaci, ponovite unos!\n";
				i--;
				continue;
			}
		} else {
			std::cout << "Pogresni podaci, ponovite unos!\n";
			i--;
		}
	}
	for (int i=0; i<br_likova; i++)
		v[i]->Ispisi();

	return 0;
}
