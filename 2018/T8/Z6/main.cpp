//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>
template<typename TipElemenata>
struct Cvor {
    TipElemenata element;
    Cvor<TipElemenata> *veza;
};
template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni);
template <typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak);
template <typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak);
template <typename TipElemenata>
int BrojVeciOd(Cvor<TipElemenata> *pocetak, TipElemenata prag);
template <typename TipElemenata>
void UnistiListu(Cvor <TipElemenata> *pocetak);

int main () {
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    Cvor<double> *pocetak=KreirajPovezanuListu<double>(0.0);
    std::cout << "U slijedu ima " << BrojVeciOd(pocetak,SumaElemenata(pocetak)/BrojElemenata(pocetak));
    std::cout << " brojeva vecih od njihove aritmeticke sredine";
    UnistiListu(pocetak);
	return 0;
}
template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni) {
    Cvor<TipElemenata> *pocetak=nullptr;
    Cvor<TipElemenata> *prethodni;
    for(;;) {
        TipElemenata k;
        std::cin >> k;
        if(k==zavrsni) break;
        Cvor<TipElemenata> *novi=new Cvor<TipElemenata>{k,nullptr};
        if(!pocetak) pocetak=novi;
        else prethodni -> veza=novi;
        prethodni = novi;
    }
    return pocetak;
}

