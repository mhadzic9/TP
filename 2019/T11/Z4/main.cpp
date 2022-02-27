/*
    TP 16/17 (Tutorijal 11, Zadatak 4)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <initializer_list>

class Tim
{
	char ime_tima[20];
	mutable int broj_odigranih,broj_pobjeda,broj_poraza,broj_nerijesenih,broj_datih,broj_primljenih,broj_poena;
public:
	Tim (const char ime[]):broj_odigranih(0),broj_pobjeda(0),broj_nerijesenih(0),broj_poraza(0),broj_datih(0),broj_primljenih(0),broj_poena(0)
	{
		if (std::strlen(ime)>20) throw std::range_error ("Predugacko ime tima");
		std::strcpy(ime_tima,ime);
	}
	void ObradiUtakmicu (int broj_datih,int broj_primljenih);
	const char *DajImeTima() const
	{
		return ime_tima;
	}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return broj_datih-broj_primljenih;
	}
	void IspisiPodatke() const;
};

class Liga
{
	int broj_timova;
	const int max_broj_timova;
	Tim** timovi;
public:
	explicit Liga (int velicina_lige): max_broj_timova(velicina_lige),broj_timova(0),timovi(new Tim*[velicina_lige]) {}
	explicit Liga (std::initializer_list <Tim> lista_timova):max_broj_timova(lista_timova.size()),broj_timova(0),timovi (new Tim*[lista_timova.size()])
	{
		auto it=lista_timova.begin();
		for (int i=0; i<lista_timova.size(); i++) {
			timovi[i]=new Tim(it->DajImeTima());
			it++;
		}
		broj_timova=lista_timova.size();
	}
	~Liga();
	Liga (const Liga &l);
	Liga (Liga &&l);
	Liga &operator=(const Liga &l);
	Liga &operator=(Liga &&l);
	void DodajNoviTim (const char ime_tima[]);
	void RegistrirajUtakmicu (const char tim1[],const char tim2[],int rezultat1,int rezultat2);
	void IspisiTabelu();
};

Liga::~Liga()
{
	for (int i=0; i<broj_timova; i++) delete timovi[i];
	delete[] timovi;
}
Liga::Liga(const Liga& l):timovi (new Tim*[l.max_broj_timova] {}),max_broj_timova(l.max_broj_timova),broj_timova(l.broj_timova)
{
	if (max_broj_timova!=l.max_broj_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");
	try {
		for (int i=0; i<l.broj_timova; i++) {
			timovi[i]=new Tim(*l.timovi[i]);
		}
	} catch (...) {
		for (int i=0; i<l.broj_timova; i++) delete timovi[i];
		delete[] timovi;
		throw;
	}
}
Liga &Liga::operator=(const Liga& l)
{
	if (l.max_broj_timova!=max_broj_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");
	for (int i=0; i<broj_timova; i++) {
		delete timovi[i];
	}
	delete [] timovi;
	timovi=new Tim*[max_broj_timova];
	for (int i=0; i<l.broj_timova; i++) timovi[i]=new Tim(*l.timovi[i]);
	broj_timova=l.broj_timova;
	return *this;
}
Liga::Liga(Liga &&l): timovi(l.timovi),max_broj_timova(l.max_broj_timova),broj_timova(l.broj_timova)
{
	l.timovi=nullptr;
	l.broj_timova=0;
}
Liga &Liga::operator=(Liga &&l)
{
	if (l.max_broj_timova!=max_broj_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");
	std::swap (broj_timova,l.broj_timova);
	std::swap(timovi,l.timovi);
	return *this;
}
void Liga::DodajNoviTim (const char ime_tima[])
{
	if (std::strlen(ime_tima)>20) throw std::range_error ("Predugacko ime tima");
	if (broj_timova==max_broj_timova) throw std::range_error ("Liga popunjena");
	for (int i=0; i<broj_timova; i++) if (std::strcmp(timovi[i]->DajImeTima(),ime_tima)==0) throw std::logic_error ("Tim vec postoji");
	timovi [broj_timova++]=new Tim(ime_tima);
}
void Liga::RegistrirajUtakmicu(const char tim1[],const char tim2[],int rezultat1,int rezultat2)
{
	if (rezultat1<0 || rezultat2<0) throw std::range_error ("Neispravan broj golova");
	bool prvi=false,drugi=false;
	int indeks_prvog=0,indeks_drugog=0;
	for (int i=0; i<broj_timova; i++) {
		if (std::strcmp(tim1,timovi[i]->DajImeTima())==0) {
			prvi=true;
			indeks_prvog=i;
		}
		if (std::strcmp(tim2,timovi[i]->DajImeTima())==0) {
			drugi=true;
			indeks_drugog=i;
		}
	}
	if (prvi==false || drugi==false) throw std::logic_error ("Tim nije nadjen");
	timovi[indeks_prvog]->ObradiUtakmicu(rezultat1,rezultat2);
	timovi[indeks_drugog]->ObradiUtakmicu(rezultat2,rezultat1);
}
void Liga::IspisiTabelu()
{
	std::sort(timovi,timovi+broj_timova,[](Tim* tim1,Tim* tim2)->bool {
		if (tim1->DajBrojPoena()==tim2->DajBrojPoena() && tim1->DajGolRazliku()==tim2->DajGolRazliku())
			return std::strcmp(tim1->DajImeTima(),tim2->DajImeTima())<0;
		else if (tim1->DajBrojPoena()==tim2->DajBrojPoena()) return tim1->DajGolRazliku()>tim2->DajGolRazliku();
		else return tim1->DajBrojPoena()>tim2->DajBrojPoena();
	});
	for (int i=0; i<broj_timova; i++) timovi[i]->IspisiPodatke();
}
void Tim::ObradiUtakmicu (int broj_datih,int broj_primljenih)
{
	if (broj_datih<0 || broj_primljenih<0) throw std::range_error ("Neispravan broj golova");
	Tim::broj_datih+=broj_datih;
	Tim::broj_primljenih+=broj_primljenih;
	broj_odigranih++;
	if (broj_datih>broj_primljenih) {
		broj_pobjeda++;
		broj_poena+=3;
	} else if (broj_datih<broj_primljenih) broj_poraza++;
	else if (broj_datih==broj_primljenih) {
		broj_nerijesenih++;
		broj_poena++;
	}
}
void Tim::IspisiPodatke() const
{
	std::cout << std::left << std::setw(20) << ime_tima << std::right << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda;
	std::cout << std::setw(4) << broj_nerijesenih << std::setw(4) << broj_poraza << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih << std::setw(4) << broj_poena;
	std::cout << std::endl;
}


int main ()
{
	Liga l{"Celik","Sarajevo","Borac","Jedinstvo","Zrinjski"};
	do {
		l.IspisiTabelu();	
		char tim1[20],tim2[20];
		try {
			std::cout << "Unesite ime prvog tima (ENTER za kraj): ";
			std::cin.getline (tim1,sizeof tim1);
			std::cout << "Unesite ime drugog tima (ENTER za kraj): ";
			std::cin.getline (tim2,sizeof tim2);
			int gol1,gol2;
			std::cout << "Unesite broj postignutih golova za oba tima: ";
			std::cin >> gol1 >> gol2;
			l.RegistrirajUtakmicu(tim1,tim2,gol1,gol2);
		}
		catch (...) {
			std::cout << "Problemi sa memorijom!";
		}
		std::cin.ignore(10000,'\n');
		std::cin.clear();
	} while (true);
	return 0;
}
