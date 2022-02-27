#include <iostream>
#include <string>
#include <vector>
#include <cstring>
typedef std::vector<std::string> VektorStringova;
bool TestZnaka (char a)
{
	if(((a>=48) && (a<=57)) || ((a>=64) && (a<=90)) || ((a>=97) && (a<=122)))
		return 1;
	return 0;
}
bool IstiZnak(char a,char b)
{
	if((a>=30 && a<=39) && (b>=30 && b<=39) && (a==b)) {
		return 1;
	}
	if(TestZnaka(a) && TestZnaka(b) && (std::toupper(a)==std::toupper(b))) {
		return 1;
	}

	return 0;
}
bool Simetrican(std::string s)
{
	for (int i=0; i<=(s.length()/2); i++) {
		char a=s[i];
		char b=s[s.length()-1-i];
		if(IstiZnak(a,b)==0) return 0;
	}
	return 1;
}
void IspisiString(std::string s)
{
	for (int i=0; i<s.length(); i++)
		std::cout << s.at(i);
}
VektorStringova NadjiSimetricneRijeci(std::string s)
{
	VektorStringova V;
	char A[1000];
	std::strcpy(A,s.c_str());
	if(s.length()==0) return V;
	bool T=0;
	for (int i=0; i<s.length(); i++) {
		if(TestZnaka(A[i]))
			T=1;
	}
	if(T==0) return V;
	int br(0);
	while(TestZnaka(A[br]==0)) br++;
	for (int i=br; i<s.length();) {
		if((i>=0) && TestZnaka(A[i])) {
			std::string s1;
			while(TestZnaka(A[i]) && (i<s.length())) {
				s1.push_back(A[i]);
				i++;
			}
			if(Simetrican(s1) && (s1.length()>1)) {
				V.push_back(s1);
			}
			s1.resize(0);
		}
		i++;
	}
	return V;
}



int main ()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,s);
	VektorStringova V(NadjiSimetricneRijeci(s));
	if(V.size()==0) {
		std::cout << "\nRecenica ne sadrzi simetricne rijeci!";
		return 0;
	}
	std::cout << "\nSimetricne rijeci unutar recenice su: " << std::endl;
	for(int i=0; i<V.size(); i++) {
		IspisiString(V[i]);
		std::cout << std::endl;
	}
	return 0;
}
