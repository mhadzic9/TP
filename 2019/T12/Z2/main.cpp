/*
    TP 16/17 (Tutorijal 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>
#include <utility>

template <typename Tip>
std::set<Tip> operator +(std::set<Tip> s1,std::set<Tip> s2)
{
	std::set<Tip> pom;
	for (auto it=s1.begin(); it!=s1.end(); it++) pom.insert(*it);
	for (auto it=s2.begin(); it!=s2.end(); it++) pom.insert(*it);
	return pom;
}
template <typename Tip>
std::set<Tip> operator *(const std::set<Tip> &s1,const std::set<Tip> &s2)
{
	std::set<Tip> pom;
	for (auto it=s1.begin(); it!=s1.end(); it++)
		for (auto it2=s2.begin(); it2!=s2.end(); it2++)
			if (*it==*it2) pom.insert(*it);
	return pom;
}
template <typename Tip1,typename Tip2>
std::set<std::pair<Tip1,Tip2>> operator%(const std::set<Tip1> &s1,const std::set<Tip2> &s2)
{
	std::set<std::pair<Tip1,Tip2>> pom;
	for (auto it=s1.begin(); it!=s1.end(); it++)
		for (auto it2=s2.begin(); it2!=s2.end(); it2++)
			pom.insert(std::pair<Tip1,Tip2>(*it,*it2));
	return pom;
}
template <typename Tip>
std::ostream &operator << (std::ostream & ispisi,std::set<Tip> s1)
{
	ispisi << "{";
	for (auto it=s1.begin(); it!=s1.end(); it++) {
		ispisi << *it;
		auto it2=it;
		it2++;
		if (it2!=s1.end()) ispisi << ",";
	}
	ispisi << "}";
	return ispisi;
}
template <typename Tip1,typename Tip2>
std::ostream &operator << (std::ostream & ispisi, std::set<std::pair<Tip1,Tip2>> s1)
{
	ispisi << "{";
	for (auto it=s1.begin(); it!=s1.end(); it++) {
		ispisi << "(" << it->first << "," << it->second << ")";
		auto it2=it;
		it2++;
		if (it2!=s1.end()) ispisi << ",";
	}
	ispisi << "}";
	return ispisi;
}
template <typename Tip>
std::set<Tip>& operator +=(std::set<Tip> & s1,std::set<Tip> s2)
{
	s1=s1+s2;
	return s1;
}
template <typename Tip>
std::set<Tip>& operator *=(std::set<Tip> & s1,const std::set<Tip> & s2)
{
	s1=s1*s2;
	return s1;
}


int main ()
{
	std::set<char> s3{'A','B'};
	std::set<int> s4{1,2,3};
	std::cout << s3%s4 << std::endl;
	
	return 0;
}
