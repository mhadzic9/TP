/*
    TP 16/17 (Tutorijal 12, Zadatak 3)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

enum Dani {Ponedjeljak,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};
std::ostream& operator << (std::ostream& tok,Dani dan)
{
	if (int(dan)==0) tok << "Ponedjeljak";
	else if (int(dan)==1) tok << "Utorak";
	else if (int(dan)==2) tok << "Srijeda";
	else if (int(dan)==3) tok << "Cetvrtak";
	else if (int(dan)==4) tok << "Petak";
	else if (int(dan)==5) tok << "Subota";
	else if (int(dan)==6) tok << "Nedjelja";
	return tok;
}
Dani &operator ++(Dani &d,int)
{
	return d=Dani((int(d)+1)%7);
}

int main ()
{
	for (Dani d=Ponedjeljak; d<=Petak; d++) std::cout << d << std::endl;
	for (Dani d=Ponedjeljak; d<=Nedjelja; d++) {
		std::cout << d << std::endl;
		if (int(d)==6) break;
	}

	return 0;
}
