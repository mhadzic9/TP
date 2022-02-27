//TP 2018/2019: Tutorijal 8, Zadatak 3
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <iomanip>

const int BrojPredmeta(8);
struct Datum {
    int dan, mjesec, godina;
};
struct Ucenik {
    std::string ime, prezime;
    Datum datum_rodjenja;
    int ocjene[BrojPredmeta];
    double prosjek;
    bool prolaz;
};

int main ()
{
    void UnesiUcenike(Ucenik *p_ucenici[],int brojucenika);
    void ObradiUcenike(Ucenik *p_ucenici[],int brojucenika);
    void IspisiIzvjestaj(Ucenik *p_ucenici[],int brojucenika);
    void OslobodiMemoriju(Ucenik *p_ucenici[],int brojucenika);
    int brojucenika;
    std::cout << "Koliko ima ucenika: ";
    std::cin >> brojucenika;
    Ucenik **p_ucenici(nullptr);
    try {
        p_ucenici=new Ucenik*[brojucenika] {};
        try {
            UnesiUcenike(p_ucenici,brojucenika);
        } catch(...) {
            OslobodiMemoriju(p_ucenici, brojucenika);
            throw;
        }
        ObradiUcenike(p_ucenici, brojucenika);
        IspisiIzvjestaj(p_ucenici, brojucenika);
    } catch(...) {
        std::cout << "Problemi sa memorijom...\n";
    }
    OslobodiMemoriju(p_ucenici, brojucenika);
    return 0;
}
void UnesiUcenike(Ucenik *p_ucenici[], int brojucenika)
{
    void UnesiJednogUcenika(Ucenik *p_ucenik);
    for (int i=0; i<brojucenika; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". ucenika:\n";
        p_ucenici[i] = new Ucenik;
        UnesiJednogUcenika(p_ucenici[i]);
    }
}
void UnesiJednogUcenika(Ucenik *p_ucenik)
{
    void UnesiDatum(Datum &datum);
    void UnesiOcjene(int ocjene[], int brojpredmeta);
    std::cout << "  Ime: ";
    std::cin >> (*p_ucenik).ime;
    std::cout << "  Prezime: ";
    std::cin >> (*p_ucenik).prezime;
    std::cout << "  Datum rodjenja (D/M/G): ";
    UnesiDatum((*p_ucenik).datum_rodjenja);
    UnesiOcjene((*p_ucenik).ocjene, BrojPredmeta);
}
void UnesiDatum(Datum &d)
{
    char znak;
    std::cin >> d.dan >> znak >> d.mjesec >> znak >> d.godina;
}
void UnesiOcjene(int ocjene[], const int brojpredmeta)
{
    for(int i=0; i<brojpredmeta; i++) {
        std::cout << "  Ocjena iz " << i+1 << ". predmeta: ";
        std::cin >> ocjene[i];
    }
}
void ObradiUcenike(Ucenik *p_ucenici[], int brojucenika)
{
    void ObradiJednogUcenika(Ucenik *p_ucenik);
    for(int i=0; i<brojucenika; i++)
        ObradiJednogUcenika(p_ucenici[i]);
    std::sort(p_ucenici,p_ucenici+brojucenika,[](Ucenik *p_u1,Ucenik *p_u2) {
        return p_u1 -> prosjek > p_u2 -> prosjek;
    });
}
void ObradiJednogUcenika(Ucenik *p_ucenik)
{
    double suma_ocjena=0;
    p_ucenik -> prosjek=1;
    p_ucenik -> prolaz=false;
    for(int i=0; i<BrojPredmeta; i++) {
        if(p_ucenik -> ocjene[i]==1) return;
        suma_ocjena += p_ucenik -> ocjene[i];
    }
    p_ucenik -> prolaz=true;
    p_ucenik -> prosjek = suma_ocjena/BrojPredmeta;
}
void IspisiIzvjestaj(Ucenik *p_ucenici[], int brojucenika)
{
    void IspisiJednogUcenika(Ucenik *p_ucenik);
    std::cout << std::endl;
    for(int i=0; i<brojucenika; i++) IspisiJednogUcenika(p_ucenici[i]);
}
void IspisiJednogUcenika(Ucenik *p_ucenik)
{
    void IspisiDatum(const Datum &d);
    std::cout << "Ucenik " << p_ucenik -> ime << " " << p_ucenik -> prezime << " rodjen ";
    IspisiDatum(p_ucenik -> datum_rodjenja);
    if(p_ucenik -> prolaz)
        std::cout << " ima prosjek " << std::setprecision(3) << p_ucenik -> prosjek;
    else
        std::cout << " mora ponavljati razred";
    std::cout << std::endl;
}
void IspisiDatum(const Datum &d)
{
    std::cout << d.dan << "/" << d.mjesec << "/" << d.godina;
}
void OslobodiMemoriju(Ucenik *p_ucenici[], int brojucenika)
{
    for(int i=0; i<brojucenika; i++) delete p_ucenici[i];
    delete[] p_ucenici;
}
