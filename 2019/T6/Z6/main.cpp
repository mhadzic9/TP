/*
    TP 2018/2019: Tutorijal 6, Zadatak 6

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
#include <deque>


template <typename Tip>
int BrojElemenata (Tip T)
{
	int brojac=0;
	for (int i=0; i<T.size(); i++) {
		for (int j=0; j<T[i].size(); j++) {
			brojac++;
		}
	}
	return brojac;
}
template <typename Tip>
auto KreirajDinamickuKopiju2D (Tip t) -> typename std::remove_reference<decltype(t[0][0])>::type**
{
	typename std::remove_reference<decltype(t[0][0])>::type** m=nullptr;
	try {
		m=new typename std::remove_reference<decltype(t[0][0])>::type *[t.size()] {};
		m[0]=new typename std::remove_reference<decltype(t[0][0])>::type [BrojElemenata(t)];
	} catch(std::bad_alloc) {
		delete [] m;
		throw;
	}
	for (int i=1; i<t.size(); i++) {
		m[i]=m[i-1]+t[i-1].size();
	}
	for (int i=0; i<t.size(); i++) {
		for (int j=0; j<t[i].size(); j++) {
			m[i][j]=t[i][j];
		}
	}
	return m;
}

int main ()
{
	int n;
	std::cout << "Unesite broj redova kvadratne matrice: ";
	std::cin >> n;
	try {
		std::vector<std::deque<int>> v (n,std::deque<int>(n));
		std::cout << "Unesite elemente matrice: ";
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				std::cin >> v.at(i).at(j);
			}
		}

		int **mat=nullptr;
		mat=KreirajDinamickuKopiju2D(v);
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				std::cout << mat[i][j] << " ";
			}
			std::cout << std::endl;
		}
		delete [] mat[0];
		delete [] mat;
	} catch (std::bad_alloc) {
		std::cout << "Nedovoljno memorije";
	}

	return 0;
}
