/*
    TP 16/17 (Tutorijal 10, Zadatak 3)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
class Vektor3d
{
	double x,y,z;
	mutable int brojac;
public:
	Vektor3d()
	{
		x=0;
		y=0;
		z=0;
		brojac=0;
	}
	Vektor3d(double x,double y,double z)
	{
		Postavi(x,y,z);
		brojac=0;
	}
	Vektor3d(const Vektor3d &a)
	{
		x=a.DajX();
		y=a.DajY();
		z=a.DajZ();
		brojac=0;
	}
	void Postavi(double x,double y,double z)
	{
		Vektor3d::x=x;
		Vektor3d::y=y;
		Vektor3d::z=z;
	}
	void Ocitaj(double &x,double &y,double &z) const
	{
		x=Vektor3d::x;
		y=Vektor3d::y;
		z=Vektor3d::z;
	}

	void Ispisi()const
	{
		brojac++;
		std::cout << "{" << x << "," << y << "," << z << "}";
	}
	void PostaviX(double x)
	{
		Vektor3d::x=x;
	}
	void PostaviY(double y)
	{
		Vektor3d::y=y;
	}
	void PostaviZ(double z)
	{
		Vektor3d::z=z;
	}
	double DajX() const
	{
		return x;
	}
	double DajY() const
	{
		return y;
	}
	double DajZ() const
	{
		return z;
	}
	double DajDuzinu() const
	{
		return sqrt(x*x+y*y+z*z);
	}
	int DajBrojIspisa() const
	{
		return brojac;
	}
	Vektor3d &PomnoziSaSkalarom(double s)
	{
		x*=s;
		y*=s;
		z*=s;
		return *this;
	}
	Vektor3d &SaberiSa (const Vektor3d &v)
	{
		x+=v.x;
		y+=v.y;
		z+=v.z;
		return *this;
	}
	friend Vektor3d ZbirVektora (const Vektor3d &v1, const Vektor3d &v2);
};
Vektor3d ZbirVektora (const Vektor3d &v1,const Vektor3d &v2)
{
	Vektor3d v3;
	v3.x=v1.x+v2.x;
	v3.y=v1.y+v2.y;
	v3.z=v1.z+v2.z;
	return v3;
}

int main ()
{
	Vektor3d v1(1,1,1);
	for(int i=0; i<3; i++) {
		v1.Ispisi();
		std::cout << " ";
	}
	std::cout << std::endl;
	const Vektor3d v2(v1);
	v2.Ispisi();
	std::cout << std::endl;
	std::cout << v2.DajBrojIspisa()<<std::endl;
	const Vektor3d v3(v2);
	std::cout << v3.DajBrojIspisa();
	return 0;
}
