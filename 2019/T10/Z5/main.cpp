/*
    TP 16/17 (Tutorijal 10, Zadatak 5)
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
	int stepeni,minute,sekunde;
	static constexpr double PI=4*atan(1);
public:
	Ugao (int stepeni,int minute,int sekunde)
	{
		Postavi (stepeni,minute,sekunde);
	}
	Ugao (double radijani=0)
	{
		Postavi(radijani);
	}
	void Postavi (int stepeni,int minute,int sekunde)
	{
		if (sekunde>=60) {
			minute+=sekunde/60;
			sekunde%=60;
		}
		if (sekunde<0) {
			sekunde+=60;
			minute-=1;
		}
		if (minute>=60) {
			stepeni+=minute/60;
			minute%=60;
		}
		if (minute<0) {
			minute+=60;
			stepeni-=1;
		}
		if (stepeni<0) stepeni+=360;
		if (stepeni>=360) stepeni%=360;
		Ugao::stepeni=stepeni;
		Ugao::minute=minute;
		Ugao::sekunde=sekunde;
	}
	void Postavi (double radijani)
	{
		if (radijani>=2*PI) radijani-=2*PI;
		if (radijani<0) radijani+=2*PI;
		stepeni=int(radijani*180/PI);
		minute=int((radijani*180/PI-stepeni)*60);
		sekunde=int(((radijani*180/PI-stepeni)*60-minute)*60+2e-9);
	}
	double DajRadijane () const
	{
		return ((stepeni+minute/60.+sekunde/3600.)*PI)/180;
	}
	int DajStepene () const
	{
		return stepeni;
	}
	int DajMinute () const
	{
		return minute;
	}
	int DajSekunde () const
	{
		return sekunde;
	}
	void OcitajKlasicneJedinice (int &stepeni,int &minute,int &sekunde)
	{
		stepeni=Ugao::stepeni;
		minute=Ugao::minute;
		sekunde=Ugao::sekunde;
	}
	void Ispisi () const
	{
		std::cout << std::fixed << std::setprecision(5) << DajRadijane();
	}
	void IspisiKlasicno () const
	{
		std::cout << std::fixed << std::setprecision(5) << stepeni << "deg " << minute << "min " << sekunde << "sec";
	}
	Ugao &SaberiSa (const Ugao &u);
	Ugao &PomnoziSa (double x);
	friend Ugao ZbirUglova (const Ugao &u1,const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem (const Ugao &u,double x);
};

Ugao &Ugao::SaberiSa (const Ugao &u)
{
	stepeni+=u.stepeni;
	minute+=u.minute;
	sekunde+=u.sekunde;
	Postavi (stepeni,minute,sekunde);
	return *this;
}
Ugao &Ugao::PomnoziSa (double x)
{
	stepeni*=x;
	minute*=x;
	sekunde*=x;
	Postavi(stepeni,minute,sekunde);
	return *this;
}
Ugao ZbirUglova (const Ugao &u1,const Ugao &u2)
{
	return Ugao (u1.stepeni+u2.stepeni, u1.minute+u2.minute, u1.sekunde+u2.sekunde);
}
Ugao ProduktUglaSaBrojem (const Ugao &u,double x)
{
	return Ugao (u.stepeni*x,u.minute*x,u.sekunde*x);
}

int main ()
{
	Ugao u(20, 10, 50);
	const Ugao u1(u);
	std::cout << u1.DajRadijane() << " " << u1.DajStepene() << " "
	          << u1.DajMinute() << " " << u1.DajSekunde() << std::endl;
	u1.Ispisi();
	std::cout << std::endl;
	u1.IspisiKlasicno();
	std::cout << std::endl;

	return 0;
}
