/*
    TP 16/17 (Tutorijal 9, Zadatak 4)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>

class Sat
{
	int sati,minute,sekunde;
public:
	bool static DaLiJeIspravno (int h,int m,int s)
	{
		if (h>=0 && h<=23 && m>=0 && m<=59 && s>=0 && s<=59) return true;
		return false;
	}
	void Postavi (int h, int m, int s)
	{
		if (!DaLiJeIspravno(h,m,s)) throw std::domain_error ("Neispravno vrijeme");
		sati=h;
		minute=m;
		sekunde=s;
	}
	void PostaviNormalizirano (int h,int m,int s);
	Sat &Sljedeci ()
	{
		sekunde++;
		PostaviNormalizirano (sati,minute,sekunde);
		return *this;
	}
	Sat &Prethodni ()
	{
		sekunde--;
		PostaviNormalizirano(sati,minute,sekunde);
		return *this;
	}
	Sat &PomjeriZa (int s)
	{
		sekunde+=s;
		PostaviNormalizirano(sati,minute,sekunde);
		return *this;
	}
	void Ispisi () const
	{
		std::cout << std::setw(2) << std::setfill('0') << DajSate() << ":" << std::setw(2) << std::setfill('0') << DajMinute() << ":" << std::setw(2) << std::setfill('0') << DajSekunde();
	}
	int DajSate () const
	{
		return sati;
	}
	int DajMinute () const
	{
		return minute;
	}
	int DajSekunde () const
	{
		return sekunde;
	}
	static int Razmak (Sat s1,Sat s2)
	{
		Sat razlika;
		if (s2.sekunde>s1.sekunde) {
			s1.minute--;
			s1.sekunde+=60;
		}
		razlika.sekunde=s1.sekunde-s2.sekunde;
		if (s2.minute>s1.minute) {
			s1.sati--;
			s1.minute+=60;
		}
		razlika.minute=s1.minute-s2.minute;
		razlika.sati=s1.sati-s2.sati;
		razlika.sekunde+=razlika.minute*60;
		razlika.sekunde+=razlika.sati*3600;
		return razlika.sekunde;
	}
	friend int BrojSekundiIzmedju(Sat s1,Sat s2);

};

int BrojSekundiIzmedju (Sat s1,Sat s2)
{
	Sat razlika;
	if (s2.sekunde>s1.sekunde) {
		s1.minute--;
		s1.sekunde+=60;
	}
	razlika.sekunde=s1.sekunde-s2.sekunde;
	if (s2.minute>s1.minute) {
		s1.sati--;
		s1.minute+=60;
	}
	razlika.minute=s1.minute-s2.minute;
	razlika.sati=s1.sati-s2.sati;
	razlika.sekunde+=razlika.minute*60;
	razlika.sekunde+=razlika.sati*3600;
	return razlika.sekunde;
}

void Sat::PostaviNormalizirano(int h,int m, int s)
{
	if (s>=60 || s<=60) {
		m+=s/60;
		s%=60;
	}
	if (s<0) {
		s+=60;
		m--;
	}
	if (m>=60 || m<=60) {
		h+=m/60;
		m%=60;
	}
	if (m<0) {
		m+=60;
		h-=1;
	}
	if (h>=24 || h<=-24) {
		h%=24;
	}
	if (h<0) h+=24;
	sati=h;
	minute=m;
	sekunde=s;
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
