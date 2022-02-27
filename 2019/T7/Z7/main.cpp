/*
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>
#include <algorithm>

template<typename Tip>
std::set<Tip> Unija (std::set<Tip> skup1,std::set<Tip> skup2)
{
	std::set<Tip> skup3;
	for (Tip x:skup1) {
		skup3.insert(x);
	}
	for (Tip x:skup2) {
		skup3.insert(x);
	}
	return skup3;
}
template<typename Tip>
std::set<Tip> Presjek (std::set<Tip> skup1,std::set<Tip> skup2)
{
	std::set<Tip> skup3;
	for (Tip x:skup1) {
		if (binary_search(skup2.begin(),skup2.end(),x)==true) {
			skup3.insert(x);
		}
	}
	return skup3;
}

int main ()
{
	std::set<std::string> s1={"mirza","m","i","r","z","a"};
	std::set<std::string> s2={"hadzic" , "a" , "d" , "z"};
	std::set<std::string> s3=Unija(s1,s2);
	std::set<std::string> s4=Presjek(s1,s2);
	for (std::string x:s3) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (std::string x:s4) {
		std::cout << x << " ";
	}

	return 0;
}
