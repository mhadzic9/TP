#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Grad
{
    char imeGrada[50];
    int brojStanovnika;
    
    public:
    Grad(const char ime[], int broj_stanovnika);
    const char *DajIme() const {return imeGrada;};
    int DajBrojStanovnika() const{return brojStanovnika;};
    int &DajBrojStanovnika(){return brojStanovnika;};
};

Grad::Grad(const char ime[], int broj_stanovnika)
{
    if (strlen(ime) >= 49)
        throw domain_error("Neispravni podaci");
    if (broj_stanovnika <= 0)
        throw domain_error("Neispravni podaci");
        
    strcpy (imeGrada, ime);
    brojStanovnika = broj_stanovnika;
}

class Gradovi
{
    vector<shared_ptr<Grad>> gradovi;
    
    public:
    Gradovi() = default;
    void DodajGrad (const char ime[], int broj_stanovnika);
    Gradovi(const Gradovi &g);
    Gradovi(Gradovi &&g);
    Gradovi &operator=(const Gradovi &g);
    Gradovi &operator=(Gradovi &&g);
    void IzbrisiGrad (const char ime[]);
    int DajBrojGradova() const {return gradovi.size();};
    void SortirajGradove();
    void Ispisi(ostream &tok = cout)
    {
        for (auto grad : gradovi)
            tok << grad-> DajIme() << ": " << grad->DajBrojStanovnika() << endl;
    };
    void SacuvajUBinarnuDatoteku(const char imeDatoteke[]);
    void ObnoviIzBinarneDatoteke(const char imeDatoteke[]);
    int &operator[](const char ime[]);
    
};

int &Gradovi::operator[](const char ime[])
{
    for (auto grad : gradovi)
    {
        if (strcmp(grad->DajIme(), ime))
            return grad->DajBrojStanovnika();
    }
    throw range_error("Nepostojeci grad");
}

void Gradovi::SacuvajUBinarnuDatoteku(const char imeDatoteke[])
{
    ofstream izlazni_tok(imeDatoteke, ios::binary);
    if (!izlazni_tok)
        throw logic_error("Greska pri upisu u datoteku");
    for (auto grad : gradovi)
    {
        char kopijaImena[50]; 
        strcpy (kopijaImena, grad->DajIme());
        int brSt = grad->DajBrojStanovnika();
        izlazni_tok.write(reinterpret_cast<char*> (&brSt), sizeof(brSt));
        izlazni_tok.write(reinterpret_cast<char*> (&kopijaImena), sizeof(kopijaImena));
    }
    if (izlazni_tok.bad())
        throw logic_error("Greska pri upisu u datoteku");
}

void Gradovi::ObnoviIzBinarneDatoteke(const char imeDatoteke[])
{
    ifstream ulazni_tok(imeDatoteke, ios::binary);
    if (!ulazni_tok)
        throw logic_error("Greska pri citanju datoteke");
    while (ulazni_tok)
    {
        char ime[50]; 
        int brSt;
        ulazni_tok.read(reinterpret_cast<char*> (&brSt), sizeof(brSt));
        ulazni_tok.read(reinterpret_cast<char*> (&ime), sizeof(ime));
        
        gradovi.push_back(make_shared<Grad>(ime, brSt));
    }
    if (ulazni_tok.bad() && !ulazni_tok.eof())
        throw logic_error("Greska pri citanju datoteke");
}

void Gradovi::SortirajGradove()
{
    sort(gradovi.begin(), gradovi.end(), []
        (shared_ptr<Grad> prvi, shared_ptr <Grad> drugi)
        {
            return (prvi->DajBrojStanovnika() < drugi->DajBrojStanovnika());
        }
    );
}

void Gradovi::DodajGrad(const char ime[], int broj_stanovnika)
{
    for (auto grad : gradovi)
    {
        if (strcmp(grad->DajIme(), ime))
            throw domain_error ("Grad vec postoji");
    }
    
    gradovi.push_back(make_shared<Grad>(ime, broj_stanovnika));
}

void Gradovi::IzbrisiGrad(const char ime[])
{
    for (int i = 0; i < gradovi.size(); i++)
    {
        if (strcmp (gradovi.at(i) -> DajIme(), ime))
        {
            gradovi.erase(gradovi.begin()+i);
            break;
        }
    }
}

Gradovi::Gradovi(const Gradovi &g)
{
    for (auto grad : g.gradovi)
    {
        gradovi.push_back(make_shared<Grad>(grad->DajIme(), grad->DajBrojStanovnika()));
    }
}
\
Gradovi &Gradovi::operator=(const Gradovi &g)
{
    if (this == &g) return *this;
    
    for (auto grad : g.gradovi)
    {
        gradovi.push_back(make_shared<Grad>(grad->DajIme(), grad->DajBrojStanovnika()));
    }
    return *this;
}

Gradovi::Gradovi(Gradovi &&g)
{
    gradovi = g.gradovi;
}

Gradovi &Gradovi::operator=(Gradovi &&g)
{
    if (this == &g) return *this;
    
    gradovi = g.gradovi;
    
    return *this;
}

int main ()
{
	Gradovi g;
}