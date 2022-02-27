/*
    TP 16/17 (Tutorijal 9, Zadatak 5)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>

class Sat
{
	int sekunde;
public:
	bool static DaLiJeIspravno (int h,int m,int s)
	{
		if (h>=0 && h<=23 && m>=0 && m<=59 && s>=0 && s<=59) return true;
		return false;
	}
	void Postavi (int h,int m,int s)
	{
		if (!DaLiJeIspravno(h,m,s)) throw std::domain_error ("Neispravno vrijeme");
		sekunde=s+m*60+h*3600;
	}
	void PostaviNormalizirano(int h,int m,int s);
	Sat &Sljedeci ()
	{
		sekunde++;
		if (sekunde>=86400 || sekunde<=86400) sekunde%=86400;
		if (sekunde<0) sekunde+=86400;
		return *this;
	}
	Sat &Prethodni ()
	{
		sekunde--;
		if (sekunde>=86400 || sekunde<=86400) sekunde%=86400;
		if (sekunde<0) sekunde+=86400;
		return *this;
	}
	Sat &PomjeriZa(int s)
	{
		sekunde+=s;
		if (sekunde>=86400 || sekunde<=86400) sekunde%=86400;
		if (sekunde<0) sekunde+=86400;
		return *this;
	}
	void Ispisi () const
	{
		std::cout << std::setw(2) << std::setfill('0') << DajSate() << ":" << std::setw(2) << std::setfill('0') << DajMinute() << ":" << std::setw(2) << std::setfill('0') << DajSekunde();
	}
	int DajSate () const
	{
		return int((sekunde/60)/60);
	}
	int DajMinute () const
	{
		return int((sekunde/60)%60);
	}
	int DajSekunde () const
	{
		return int(sekunde%60);
	}
	static int Razmak (Sat s1,Sat s2)
	{
		return s1.sekunde-s2.sekunde;
	}
	friend int BrojSekundiIzmedju (Sat s1,Sat s2);
};
int BrojSekundiIzmedju(Sat s1,Sat s2)
{
	return s1.sekunde-s2.sekunde;
}
void Sat::PostaviNormalizirano(int h,int m,int s)
{
	sekunde=s+m*60+h*3600;
	if (sekunde>=86400 || sekunde<=86400) sekunde%=86400;
	if (sekunde<0) sekunde+=86400;
}

int main ()
{
	try {
		Sat s1,s2;
		s1.Postavi(12,34,55);
		std::cout << "Vrijeme s1: ";
		s1.Ispisi();
		std::cout << "\nVrijeme s2: ";
		s2.Postavi(3,1,23);
		s2.Ispisi();
		s1.Sljedeci().Sljedeci().Prethodni().PomjeriZa(5);
		std::cout << "\nPrvo vrijeme nakon dodavanja 6 sekundi: ";
		s1.PostaviNormalizirano(s1.DajSate(),s1.DajMinute(),s1.DajSekunde());
		s1.Ispisi();
		std::cout << "Razlika izmedju ova dva vremena u sekundama: " << Sat::Razmak(s1,s2);
		Sat razlika;
		std::cout << ", a u pretvorenom obliku (hh::mm::ss) ";
		razlika.PostaviNormalizirano(0,0,BrojSekundiIzmedju(s1,s2));
		razlika.Ispisi();
	} catch (std::domain_error Izuzetak) {
		std::cout << Izuzetak.what();
	}
	
	return 0;
}
