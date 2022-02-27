/*
    TP 16/17 (Tutorijal 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

class Ugao
{
	double ugao;
	static constexpr double PI=4*atan(1);
public:
	Ugao (double radijani=0)
	{
		Postavi(radijani);
	};
	Ugao (int stepeni,int minute,int sekunde)
	{
		Postavi (stepeni,minute,sekunde);
	};
	void Postavi (double radijani)
	{
		while (radijani>=2*PI) {
			radijani-=(2*PI);
		}
		while (radijani<0) {
			radijani+=(2*PI);
		}
		ugao=radijani;
	}
	void Postavi (int stepeni,int minute,int sekunde)
	{
		ugao=((stepeni+minute/60.+sekunde/3600.)*PI)/180;
		Postavi(ugao);
	}
	double DajRadijane () const
	{
		return ugao;
	}
	void OcitajKlasicneJedinice (int &stepeni,int &minute,int &sekunde)
	{
		stepeni=int(ugao*180/PI);
		minute=int((ugao*180/PI-stepeni)*60);
		sekunde=int(((ugao*180/PI-stepeni)*60)-minute)*60;
	}
	int DajStepene () const
	{
		return int (ugao*180/PI);
	}
	int DajMinute () const
	{
		return int ((ugao*180/PI-DajStepene())*60);
	}
	int DajSekunde () const
	{
		return int (((ugao*180/PI-DajStepene())*60-DajMinute())*60+2e-9);
	}
	void Ispisi () const
	{
		std::cout << std::fixed << std::setprecision(5) << ugao;
	}
	void IspisiKlasicno () const
	{
		std::cout << std::fixed << std::setprecision(5) << DajStepene() << "deg " << DajMinute() << "min " << DajSekunde() << "sec";
	}
	Ugao &SaberiSa (const Ugao &u);
	Ugao &PomnoziSa (double x);
	friend Ugao ZbirUglova (const Ugao &u1,const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem (const Ugao &u,double x);
};
Ugao &Ugao::SaberiSa (const Ugao &u)
{
	ugao+=u.ugao;
	Postavi(ugao);
	return *this;
}
Ugao &Ugao::PomnoziSa (double x)
{
	ugao*=x;
	Postavi(ugao);
	return *this;
}
Ugao ZbirUglova (const Ugao &u1,const Ugao &u2)
{
	Ugao u;
	u.ugao=u1.ugao+u2.ugao;
	u.Postavi(u.ugao);
	return u;
}
Ugao ProduktUglaSaBrojem (const Ugao &u,double x)
{
	Ugao produkt;
	produkt.ugao=u.ugao*x;
	produkt.Postavi(produkt.ugao);
	return produkt;
}

int main ()
{
	Ugao u(20,10,50);
	const Ugao u1(u);
	std::cout << u1.DajRadijane() << " " << u1.DajStepene() << " "
	          << u1.DajMinute() << " " << u1.DajSekunde() << std::endl;
	u1.Ispisi();
	std::cout << std::endl;
	u1.IspisiKlasicno();
	std::cout << std::endl;

	return 0;
}
