//TP 2018/2019: Ispit 6, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>

class Apstraktna {
    double tezina;
    public:
    Apstraktna(double tezina) { if(tezina<0) throw std::domain_error("Neispravni parametri"); Apstraktna::tezina=tezina;}
    virtual ~Apstraktna() {}
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual std::shared_ptr<Apstraktna> DajKopiju() const=0;
};
class Sanduk:public Apstraktna {
    double tezina_predmeta;
    std::string naziv_predmeta;
    int br_predmeta;
    public:
    Sanduk(double tezina, std::string naziv, int br_predmeta, double tezina_predmeta) : Apstraktna(tezina) {
        if(br_predmeta<0 || tezina_predmeta<0) throw std::domain_error("Neispravni parametri");
        Sanduk::br_predmeta=br_predmeta; Sanduk::tezina_predmeta=tezina_predmeta;
        naziv_predmeta=naziv;
    }
    std::shared_ptr<Apstraktna> DajKopiju() const { return std::make_shared<Sanduk>(*this);}
    double DajUkupnuTezinu() const override {
        return br_predmeta*tezina_predmeta+DajTezinu();
    }
    void Ispisi() const {
        std::cout<<"Sanduk "<<DajTezinu()<<" "<<naziv_predmeta<<" "<<br_predmeta<<" "<<tezina_predmeta;
    }
};
class Bure: public Apstraktna {
    double tezina_tecnosti;
    std::string naziv_tecnosti;
    public:
    Bure(double tezina, std::string naziv, double tezina_tecnosti): Apstraktna(tezina) {
        if(tezina_tecnosti<0) throw std::domain_error("Neispravni parametri");
        Bure::tezina_tecnosti=tezina_tecnosti;
        naziv_tecnosti=naziv;
    }
    double DajUkupnuTezinu() const override {
        return tezina_tecnosti+DajTezinu();
    }
    std::shared_ptr<Apstraktna> DajKopiju() const { return std::make_shared<Bure>(*this);}
    void Ispisi() const {
        std::cout<<"Bure "<<DajTezinu()<<" "<<naziv_tecnosti<<" "<<tezina_tecnosti;
    }
};
class Skladiste {
    std::vector<std::shared_ptr<Apstraktna>> vektor_robe;
    public:
    Skladiste() {}
    Skladiste(const Skladiste& s);
    Skladiste& operator=(const Skladiste& s);
    Skladiste(Skladiste&& s): vektor_robe(std::move(s.vektor_robe)) {}
    Skladiste& operator=(Skladiste&& s) {
        vektor_robe=std::move(s.vektor_robe);
        return *this;
    }
    int DajBrojObjekata() const {
        return vektor_robe.size();
    }
    void DodajSanduk(double tezina, std::string naziv, int br_predmeta, double tezina_predmeta) {
        vektor_robe.push_back(std::make_shared<Sanduk>(tezina, naziv, br_predmeta, tezina_predmeta));
    }
    void DodajBure(double tezina, std::string naziv, double tezina_tecnosti) {
        vektor_robe.push_back(std::make_shared<Bure>(tezina, naziv, tezina_tecnosti));
    }
    const Apstraktna& DajNajlaksi() const {
        auto it=std::min_element(vektor_robe.begin(), vektor_robe.end(), [] (std::shared_ptr<Apstraktna> el1, std::shared_ptr<Apstraktna> el2) {
            return el1->DajTezinu()<el2->DajTezinu();
        });
        return **it;
    }
    int DajBrojPreteskih(double broj) {
        int brojac=0;
        for(int i=0;i<vektor_robe.size();i++) {
            if(vektor_robe[i]->DajUkupnuTezinu()>broj) brojac++;
        }
        return brojac;
    }
    void Ispisi() const;
    Apstraktna& operator[](int indeks) {
        if(indeks<0 || indeks>vektor_robe.size()-1) throw std::range_error("Neispravan indeks");
        return *vektor_robe[indeks-1];
    }
};
void Skladiste::Ispisi() const {
    Skladiste novo_skladiste(*this);
    std::sort(novo_skladiste.vektor_robe.begin(), novo_skladiste.vektor_robe.end(), [] (std::shared_ptr<Apstraktna> el1, std::shared_ptr<Apstraktna> el2) {
        return el1->DajUkupnuTezinu()>el2->DajUkupnuTezinu();
    });
    for(int i=0;i<novo_skladiste.vektor_robe.size();i++) {
        novo_skladiste.vektor_robe[i]->Ispisi();
        std::cout<<std::endl;
    }
}
 Skladiste::Skladiste(const Skladiste& s) {
        vektor_robe.resize(s.vektor_robe.size());
        for(int i=0;i<vektor_robe.size();i++) vektor_robe[i]=s.vektor_robe[i]->DajKopiju();
    }
Skladiste& Skladiste::operator=(const Skladiste& s) {
    if(&s!=this) {
    for(int i=0;i<vektor_robe.size();i++) vektor_robe[i]=nullptr;
    vektor_robe.resize(s.vektor_robe.size());
    for(int i=0;i<s.vektor_robe.size();i++) vektor_robe[i]=s.vektor_robe[i]->DajKopiju();
    }
    return *this;
}
int main ()
{
  /*  Skladiste s;
    while(1) {
        std::cout<<"\nS - sanduk, B - bure, K - kraj: ";
        char slovo;
        std::cin>>slovo;
        if(slovo=='B') {
            double tezina;
            std::cout<<"\nTezina bureta: ";
            std::cin>>tezina;
            std::string naziv;
            std::cout<<"\nSadrzaj: ";
            std::getline(std::cin, naziv);
            double tezina_tecnosti;
            std::cout<<"\nTezina tecnosti: ";
            std::cin>>tezina_tecnosti;
            s.DodajBure(tezina, naziv, tezina_tecnosti);
        } else if(slovo=='S') {
            double tezina;
            std::cout<<"\nTezina sanduka: ";
            std::cin>>tezina;
            std::string naziv;
            std::cout<<"\nSadrzaj: ";
            std::getline(std::cin, naziv);
            int broj_predmeta;
            std::cout<<"\nBroj predmeta: ";
            std::cin>>broj_predmeta;
            double tezina_predmeta;
            std::cout<<"\nTezina predmeta: ";
            std::cin>>tezina_predmeta;
            s.DodajSanduk(tezina, naziv, broj_predmeta, tezina_predmeta);
        } else if(slovo=='K') break;
    }
    s.Ispisi(); */
     {

        Skladiste s;

        // Dodavanje razlicitih objekata
        s.DodajBure(12.5,"Barel",52.5);
        s.DodajSanduk(2.5,"Paket",3,7);
        s.DodajBure(3,"Tekucina",10);

        if (true)
        {
            // Provjera na destruktivnu samododjelu
            s = s;

            // Kopirajuci operator dodjele
            Skladiste kopija;
            kopija = s;

            // Modifikacija kopiranog objekta
            kopija.DodajSanduk(30,"Odjeca",250,0.4);

            std::cout<<"Kopija:"<<std::endl;
            kopija.Ispisi();
        }

        // Test da li je originial ostao netaknut
        std::cout<<std::endl<<"Original:"<<std::endl;
        s.Ispisi();
    }
	return 0;
}