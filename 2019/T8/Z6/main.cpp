//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>

template <typename TipElemenata>
struct Cvor {
    TipElemenata element;
    Cvor<TipElemenata> *veza;
};
template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni)
{
    Cvor<TipElemenata> *pocetak=nullptr,*prethodni;
    for (;;) {
        TipElemenata el;
        std::cin >> el;
        if (el==zavrsni) break;
        Cvor<TipElemenata> *novi =new Cvor <TipElemenata> {el,nullptr};
        if (!pocetak) pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
    return pocetak;
}

template <typename TipElemenata>
int BrojElemenata (Cvor<TipElemenata> *pocetak)
{
    if (!pocetak) return 0;
    int brojac=0;
    for (Cvor<TipElemenata> *p=pocetak; p!=nullptr; p=p->veza) brojac++;
    return brojac;
}

template <typename TipElemenata>
TipElemenata SumaElemenata (Cvor <TipElemenata> *pocetak)
{
    if (!pocetak) return TipElemenata();
    Cvor <TipElemenata> *p=pocetak;
    TipElemenata suma(p->element);
    for (; p!=nullptr; p=p->veza) {
        if (p!=pocetak) suma+=p->element;
    }
    return suma;
}

template <typename TipElemenata>
int BrojVecihOd (Cvor <TipElemenata> *pocetak,TipElemenata prag)
{
    if (!pocetak) return 0;
    int brojac=0;
    for (Cvor <TipElemenata> *p=pocetak; p!=nullptr; p=p->veza)
        if (p->element>prag) brojac++;
    return brojac;
}

template <typename TipElemenata>
void UnistiListu (Cvor <TipElemenata> *pocetak)
{
    if (!pocetak) return;
    Cvor <TipElemenata> *p=pocetak,*prethodni;
    while (p!=nullptr) {
        prethodni=p;
        p=p->veza;
        delete prethodni;
    }
}

int main ()
{
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    Cvor <double> *pocetak=KreirajPovezanuListu<double>(0);
    double a=0;
    a=SumaElemenata(pocetak)/BrojElemenata(pocetak);
    std::cout << "U slijedu ima " << BrojVecihOd(pocetak,a) << " brojeva vecih od njihove aritmeticke sredine";
    UnistiListu(pocetak);

    return 0;
}
