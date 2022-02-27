/*
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>

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


int main ()
{
	StudentBachelor student1 ("Mirza", "Hadzic", 18513);
	StudentMaster student2 ("Mirza", "Hadzic" , 18513, 2020);
	student1.RegistrirajIspit(7);
	student1.RegistrirajIspit(6);
	student2.RegistrirajIspit(8);
	student1.IspisiPodatke();
	student2.IspisiPodatke();
	
	return 0;
}
