/* TP, 2018/2019, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
#include <cmath>

int Palindrom (int n) {
	int a=0,b;
	while(n!=0) {
		b=n%10;
		a=a*10+b;
		n/=10;
	}
	return a;
}
std::vector<int> PalindromskaOtpornost(std::vector<int> v) {
	for(int i=0;i<v.size();i++) {
		v.at(i)=std::abs(v.at(i));
	}
	std::vector<int> vektor;
	for(int i=0;i<v.size();i++) {
		int brojac=0;
		while (v.at(i)!=Palindrom(v.at(i))) {
			v.at(i)+=Palindrom(v.at(i));
			brojac++;
		}
		vektor.push_back(brojac);
	}
	return vektor;
}

int main () {
	int a;
	std::cout<<"Koliko zelite unijeti elemenata: ";
	std::cin>>a;
	std::vector<int> v;
	std::cout<< "Unesite elemente: ";
	for (int i=0;i<a;i++) {
		int broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	std::vector<int> novivektor=PalindromskaOtpornost(v);
	for(int i=0;i<novivektor.size();i++) {
		std::cout<<"Palindromska otpornost broja " << v.at(i) << " iznosi " << novivektor.at(i) << std::endl;
	}
	
	

	return 0;
}
