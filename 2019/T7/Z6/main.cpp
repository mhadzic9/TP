/*
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iterator>
#include <list>

template<typename Tip>
std::list<Tip> SortirajListu (std::list<Tip> &lista)
{
	for (auto i=lista.begin(); i!=lista.end(); i++) {
		auto min=i;
		for (auto j=i; j!=lista.end(); j++) {
			if (*j<*min) min=j;
		}

		auto pomocna=*i;
		*i=*min;
		*min=pomocna;
	}
	std::list<Tip>novalista;
	for (auto i=lista.begin(); i!=lista.end(); i++) {
		novalista.push_back(*i);
	}
	return novalista;

}

int main ()
{
	int n;
	std::cout << "Koliko ima elemenata: ";
	std::cin >> n;
	std::list<int> lista;
	std::cout << "Unesite elemente: ";
	std::list<int>::iterator it=lista.begin();
	for (int i=0; i<n; i++) {
		int tmp;
		std::cin >> tmp;
		lista.insert(it,tmp);
		it++;
	}
	std::list<int>novalista=SortirajListu(lista);
	std::cout << "Sortirana lista: ";
	for (int x:novalista) {
		std::cout << x << " ";
	}

	return 0;
}
