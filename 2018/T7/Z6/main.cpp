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

template <typename tip>
void SortirajListu(std::list<tip> &lista) {
	for (auto it=lista.begin();it!=(lista.end());it++) {
		auto min=it;
		auto it2=it;
		it2++;
		for(;it2!=lista.end();it2++) {
			if(*it2<*min) {
				min=it2;
			}
		}
		auto temp=*min;
		*min=*it;
		*it=temp;
	}
}

int main () {


	
	
	return 0;
}