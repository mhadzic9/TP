/* 
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>


std::string IzvrniBezRazmaka (std::string s) {
	std::string s1;
	std::remove_copy(s.rbegin(),s.rend(),std::back_inserter(s1),' ');
	return s1;
}

int main ()
{
	
	
	return 0;
}