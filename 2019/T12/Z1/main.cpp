/*
    TP 16/17 (Tutorijal 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
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
	Sat():sati(0),minute(0),sekunde(0) {};
	Sat (int h,int m,int s)
	{
		PostaviNormalizirano(h,m,s);
	}
	void PostaviNormalizirano(int h,int m,int s);
	Sat &operator ++()
	{
		sekunde=sekunde+1;
		PostaviNormalizirano(sati,minute,sekunde);
		return *this;
	}
	Sat operator ++(int)
	{
		Sat pomocni=*this;
		++sekunde;
		PostaviNormalizirano(sati,minute,sekunde);
		return pomocni;
	}
	Sat &operator --()
	{
		sekunde=sekunde-1;
		PostaviNormalizirano(sati,minute,sekunde);
		return *this;
	}
	Sat operator --(int)
	{
		Sat pomocni=*this;
		--sekunde;
		PostaviNormalizirano(sati,minute,sekunde);
		return pomocni;
	}
	friend Sat& operator +=(Sat &s1,int n)
	{
		s1.sekunde+=n;
		s1.PostaviNormalizirano(s1.sati,s1.minute,s1.sekunde);
		return s1;
	}
	friend Sat& operator -=(Sat& s1,int n)
	{
		s1.sekunde+=-n;
		s1.PostaviNormalizirano(s1.sati,s1.minute,s1.sekunde);
		return s1;
	}
	friend std::ostream &operator <<(std::ostream &tok,const Sat& s)
	{
		tok << std::setw(2) << std::setfill('0') << s.DajSate() << ":" << std::setw(2) << std::setfill('0') << s.DajMinute() << ":" << std::setw(2) << std::setfill('0') << s.DajSekunde();
		return tok;
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
	friend int operator -(Sat s1,Sat s2)
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
	friend Sat operator +(const Sat& s,int n)
	{
		Sat novi=s;
		novi.sekunde+=n;
		novi.PostaviNormalizirano(novi.sati,novi.minute,novi.sekunde);
		return novi;
	}
	friend Sat operator -(const Sat& s,int n)
	{
		Sat novi=s;
		novi.sekunde-=n;
		novi.PostaviNormalizirano(novi.sati,novi.minute,novi.sekunde);
		return novi;
	}
};
	void Sat::PostaviNormalizirano(int h,int m,int s)
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
		if (h>=24 || h<=24) {
			h%=24;
		}
		if (h<0) h+=24;
		sati=h;
		minute=m;
		sekunde=s;
	}


int main ()
{
	return 0;
}
