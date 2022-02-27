/* 
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>
class Tim {
	char ime_tima[20];
	int broj_odigranih,broj_pobjeda,broj_nerijesenih,broj_poraza,broj_datih,broj_primljenih,broj_poena;
	public:
	Tim(const char ime[]) {
		if(std::strlen(ime)>19) throw std::range_error("Predugacko ime tima");
		const char *p(ime);
		char *q(ime_tima);
		while(*p!='\0') {
			*q=*p;
			q++;
			p++;
		}
		*q='\0';
		broj_odigranih=0;
		broj_pobjeda=0;
		broj_nerijesenih=0;
		broj_poraza=0;
		broj_datih=0;
		broj_primljenih=0;
		broj_poena=0;
	}
	void ObradiUtakmicu(int broj_datih,int broj_primljenih);
	const char *DajImeTima() const {
		return ime_tima;
	}
	int DajBrojPoena() const {
		return broj_poena;
	}
	int DajGolRazliku() const {
		return broj_datih-broj_primljenih;
	}
	void IspisiPodatke() const;
};
void Tim::ObradiUtakmicu(int broj_datih,int broj_primljenih) {
	if(broj_datih<0 || broj_primljenih<0) throw std::range_error("Neispravan broj golova");
	Tim::broj_datih+=broj_datih;
	Tim::broj_primljenih+=broj_primljenih;
	broj_odigranih++;
	if(broj_datih>broj_primljenih) {
		broj_pobjeda++;
		broj_poena+=3;
	}
	else if(broj_datih==broj_primljenih) {
		broj_nerijesenih++;
		broj_poena+=1;
	}
}
void Tim::IspisiPodatke() const {
	std::cout << std::left << std::setw(20) << ime_tima;
	std::cout << std::right << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda << std::setw(4) << broj_nerijesenih << std::setw(4) << broj_poraza << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih << std::setw(4) << broj_poena << std::setw(4) << std::endl;
	
}
int main ()
{
	return 0;
}