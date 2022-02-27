/*
    TP 16/17 (Tutorijal 9, Zadatak 1)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>

class Vektor3d
{
	double x, y, z;
public:
	void Postavi(double x, double y, double z)
	{
		Vektor3d::x = x;
		Vektor3d::y = y;
		Vektor3d::z = z;
	}
	void Ocitaj(double &x, double &y, double &z) const
	{
		x = Vektor3d::x;
		y = Vektor3d::y;
		z = Vektor3d::z;
	}
	void Ispisi() const
	{
		std::cout << "{" << x << "," << y << "," << z << "}";
	}
	void PostaviX (double x)
	{
		Vektor3d::x=x;
	}
	void PostaviY (double y)
	{
		Vektor3d::y=y;
	}
	void PostaviZ (double z)
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
		return sqrt(x * x + y * y + z * z);
	}
	Vektor3d &PomnoziSaSkalarom(double s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	Vektor3d &SaberiSa(const Vektor3d &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
	double v1_x, v1_y, v1_z, v2_x, v2_y, v2_z;
	v1.Ocitaj(v1_x, v1_y, v1_z);
	v2.Ocitaj(v2_x, v2_y, v2_z);
	Vektor3d v3;
	v3.Postavi(v1_x + v2_x, v1_y + v2_y, v1_z + v2_z);
	return v3;
}

int main ()
{
	Vektor3d v1, v2;
	v1.Postavi(3, 4, 2);
	v2.Postavi(2, 0, 5);
	v1.Ispisi();
	v1.Ispisi();
	v1.Ispisi();
	v2.Ispisi();
	v2.Ispisi();
	std::cout << std::endl;
	return 0;
}
