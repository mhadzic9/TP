/*
    TP 16/17 (Tutorijal 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ApstraktniStudent
{
	std::string ime,prezime;
	int indeks, br_polozenih;
	double prosjek;
public:
	ApstraktniStudent(std::string ime,std::string prezime, int ind) : ime(ime), prezime(prezime),
		indeks(ind),br_polozenih(0),prosjek(5) {}
	virtual ~ ApstraktniStudent() {};
	std::string DajIme() const
	{
		return ime;
	}
	std::string DajPrezime() const
	{
		return prezime;
	}
	int DajBrojIndeksa () const
	{
		return indeks;
	}
	int DajBrojPolozenih () const
	{
		return br_polozenih;
	}
	double DajProsjek() const
	{
		return prosjek;
	}
	void RegistrirajIspit (int ocjena)
	{
		if (ocjena<5 || ocjena>10) throw std::domain_error ("Neispravna ocjena");
		if (ocjena>5) {
			double suma=prosjek*br_polozenih+ocjena;
			br_polozenih++;
			prosjek=suma/br_polozenih;
		}
	}
	void PonistiOcjene()
	{
		br_polozenih=0;
		prosjek=5;
	}
	virtual void IspisiPodatke() const=0;
	virtual ApstraktniStudent* DajKopiju() const=0;
};
class StudentBachelor: public ApstraktniStudent
{
public:
	StudentBachelor(std::string ime,std::string prezime,int indeks): ApstraktniStudent(ime,prezime,indeks) {}
	ApstraktniStudent *DajKopiju() const override
	{
		return new StudentBachelor(*this);
	}
	void IspisiPodatke() const override
	{
		std::cout << "Student bachelor studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << ",\n";
		std::cout << "ima prosjek " << DajProsjek() << ".\n";
	}
};
class StudentMaster:public ApstraktniStudent
{
	int godina_diplomiranja;
public:
	StudentMaster(std::string ime,std::string prezime,int indeks,int godina_diplomiranja): ApstraktniStudent (ime,prezime,indeks),
		godina_diplomiranja(godina_diplomiranja) {}
	ApstraktniStudent* DajKopiju() const override
	{
		return new StudentMaster(*this);
	}
	void IspisiPodatke() const override
	{
		std::cout << "Student master studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() <<",\n";
		std::cout << "zavrsio bachelor studij godine " << godina_diplomiranja << ",ima prosjek " << DajProsjek() << ".\n";
	}
};

class Fakultet
{
	std::vector<ApstraktniStudent*> studenti;
public:
	explicit Fakultet() {};
	~Fakultet()
	{
		for (int i=0; i<studenti.size(); i++) delete studenti[i];
	}
	Fakultet(const Fakultet& f);
	Fakultet& operator*(const Fakultet &f);
	Fakultet(Fakultet &&f);
	Fakultet& operator*(Fakultet && f);
	void UpisiStudenta (std::string ime,std::string prezime,int indeks);
	void UpisiStudenta (std::string ime,std::string prezime,int indeks,int godina_diplomiranja);
	void ObrisiStudenta (int ind);
	ApstraktniStudent& operator[](int indeks) const;
	void IspisiSveStudente() const;
};
Fakultet::Fakultet(const Fakultet& f)
{
	studenti.resize(f.studenti.size());
	for (int i=0; i<studenti.size(); i++) delete studenti[i];
	try {
		for (int i=0; i<studenti.size(); i++) studenti[i]=f.studenti[i]->DajKopiju();
	} catch(...) {
		for (int i=0; i<studenti.size(); i++) delete studenti[i];
		throw;
	}
}
Fakultet& Fakultet::operator*(const Fakultet& f)
{
	std::vector<ApstraktniStudent*> novi_v(f.studenti.size());
	try {
		for (int i=0; i<f.studenti.size(); i++) novi_v[i]=f.studenti[i]->DajKopiju();
	} catch (...) {
		for (int i=0; i<studenti.size(); i++) delete studenti[i];
		throw;
	}
	for (int i=0; i<studenti.size(); i++) delete studenti[i];
	studenti.resize(novi_v.size());
	studenti=novi_v;
	return *this;
}
Fakultet::Fakultet(Fakultet&& f)
{
	for (int i=0; i<studenti.size(); i++) delete studenti[i];
	studenti.resize(f.studenti.size());
	for (int i=0; i<studenti.size(); i++) studenti[i]=f.studenti[i];
	for (int i=0; i<f.studenti.size(); i++) f.studenti[i]=nullptr;
	f.studenti.resize(0);
}
Fakultet& Fakultet::operator*(Fakultet&& f)
{
	for (int i=0; i<studenti.size(); i++) delete studenti[i];
	studenti.resize(f.studenti.size());
	for (int i=0; i<studenti.size(); i++) studenti[i]=f.studenti[i];
	for (int i=0; i<f.studenti.size(); i++) f.studenti[i]=nullptr;
	f.studenti.resize(0);
	return *this;
}
void Fakultet::UpisiStudenta(std::string ime,std::string prezime,int indeks)
{
	for (int i=0; i<studenti.size(); i++) if (studenti[i]->DajBrojIndeksa()==indeks) throw std::logic_error ("Student sa zadanim brojem indeksa vec postoji");
	studenti.push_back(new StudentBachelor(ime,prezime,indeks));
}
void Fakultet::UpisiStudenta(std::string ime,std::string prezime,int indeks,int godina_diplomiranja)
{
	for (int i=0; i<studenti.size(); i++) if (studenti[i]->DajBrojIndeksa()==indeks) throw std::logic_error ("Student sa zadanim brojem indeksa vec postoji");
	studenti.push_back(new StudentMaster(ime,prezime,indeks,godina_diplomiranja));
}
void Fakultet::ObrisiStudenta(int ind)
{
	bool obrisan=false;
	for (int i=0; i<studenti.size(); i++) {
		if (studenti[i]->DajBrojIndeksa()==ind) {
			delete studenti[i];
			studenti.erase(studenti.begin()+i);
			obrisan=true;
			break;
		}
	}
	if (!obrisan) throw std::logic_error ("Student sa zadanim brojem indeksa ne postoji");
}
ApstraktniStudent& Fakultet::operator [](int indeks) const
{
	int i;
	for (i=0; i<studenti.size(); i++)
		if (studenti[i]->DajBrojIndeksa()==indeks) return *studenti[i];
	if (i==studenti.size() || i==0) throw std::logic_error ("Student sa zadanim brojem indeksa ne postoji");
	return *studenti[0];
}
void Fakultet::IspisiSveStudente() const
{
	std::vector<ApstraktniStudent*> kopija(studenti.size());
	for (int i=0; i<studenti.size(); i++) kopija[i]=studenti[i]->DajKopiju();
	std::sort (kopija.begin(),kopija.end(),[](ApstraktniStudent* s1,ApstraktniStudent *s2) {
		if (s1->DajProsjek()==s2->DajProsjek()) return s1->DajBrojIndeksa()<s2->DajBrojIndeksa();
		else return s1->DajProsjek()>s2->DajProsjek();
	});
	for (int i=0; i<kopija.size(); i++) kopija[i]->IspisiPodatke();
	for (int i=0; i<kopija.size(); i++) delete kopija[i];
}

int main ()
{
	return 0;
}
