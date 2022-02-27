/* 
    TP 16/17 (Tutorijal 9, Zadatak 5)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

class Sat {
	int sekunde;
	public:
	static bool DaLiJeIspravno (const int &sati,const int &minute,const int &sekunde);
	void Postavi(int sati,int minute,int sekunde) {
		if(!DaLiJeIspravno(sati,minute,sekunde)) throw std::domain_error("Neispravno vrijeme");
		Sat::sekunde=sekunde+minute*60+sati*3600;
	}
	void PostaviNormalizirano(int sati,int minute,int sekunde) {
		while(sekunde>59) {
			sekunde-=60;
			minute++;
		}
		while (minute>59) {
			minute-=60;
			sati++;
		}
		while (sati>23) {
			sati-=24;
		}
		while (sekunde<0) {
			sekunde+=60;
			minute--;
		}
		while (minute<0) {
			minute+=60;
			sati--;
		}
		while (sati<0) 
		sati+=24;
		Sat::sekunde=sekunde+minute*60+sati*3600;
	}
	Sat Sljedeci() {
		sekunde ++;
		PostaviNormalizirano(DajSate(),DajMinute(),DajSekunde());
		return *this;
	}
	Sat Prethodni() {
		sekunde --;
		PostaviNormalizirano(DajSate(),DajMinute(),DajSekunde());
		return *this;
	}
	Sat PomjeriZa(int broj_pomjeraja) {
		sekunde +=broj_pomjeraja;
		PostaviNormalizirano(DajSate(),DajMinute(),DajSekunde());
		return *this;
	}
	void Ispisi() const {
		std::cout << std::setw(2) << std::setfill('0') << DajSate() << ":";
		std::cout << std::setw(2) << std::setfill('0') << DajMinute()<< ":";
		std::cout << std::setw(2) << std::setfill('0') << DajSekunde()<< ":";
	}
	int DajSate() const {
		return sekunde/3600;
	}
	int DajMinute() const {
		return(sekunde%3600)/60;
	}
	int DajSekunde() const {
		return (sekunde%3600)%60;
	}
	friend int BrojSekundiIzmedju(const Sat &vrijeme1, const Sat &vrijeme2);
	static int Razmak(const Sat &vrijeme1, const Sat &vrijeme2);
};
bool Sat::DaLiJeIspravno(const int &sati, const int &minute, const int &sekunde) {
	if(sati>23 || sati<0 || minute>59 || minute<0 || sekunde>59 || sekunde<0) return false;
	return true;
}
int main () {
	Sat s1,s2;
	try {
		int sati1,sati2,minute1,minute2,sekunde1,sekunde2;
		std::cout << "Unesite prvo vrijeme: ";
		std::cin >> sati1 >> minute1 >> sekunde1;
		s1.Postavi(sati1,minute1,sekunde1);
		std::cout << "Unesite dugo vrijeme: ";
		std::cin >> sati2 >> minute2 >> sekunde2;
		s1.PostaviNormalizirano(sati2,minute2,sekunde2);
		std::cout << "Prvo vrijeme uvecano za 1 sekundu: ";
		s1.Sljedeci().Ispisi();
		std::cout << std::endl << "Drugo vrijeme umanjeno za 1 sekundu: ";
		s2.Prethodni().Ispisi();
		std::cout << std::endl << "Razmak izmedju ova dva vremena je: " << BrojSekundiIzmedju(s1,s2) << std::endl;
	}
	catch(std::domain_error s) {
		std::cout << s.what();
	}
	return 0;
}
int BrojSekundiIzmedju(const Sat &vrijeme1,const Sat &vrijeme2) {
	return vrijeme1.sekunde-vrijeme2.sekunde;
}
int Sat::Razmak(const Sat &vrijeme1, const Sat &vrijeme2) {
	return vrijeme1.sekunde-vrijeme2.sekunde;
}