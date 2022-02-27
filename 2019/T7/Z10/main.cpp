/*
    TP 16/17 (Tutorijal 7, Zadatak 10)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>

std::function<int(int)> IteriranaFunkcija (int f(int),int n)
{
	std::function<int(int)> funkcija=std::function<int(int)>(f);
	for (int i=1; i<n; i++) {
		funkcija=std::function<int(int)>([f,funkcija] (int x) {
			return funkcija(f(x));
		});
	}
	return funkcija;
}
int Proizvod (int x) {
	return x*3;
}

int main() {
	std::cout << IteriranaFunkcija(Proizvod,0)(5);
	
	return 0;
}
