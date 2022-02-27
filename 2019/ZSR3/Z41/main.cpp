//TP 2018/2019: ZSR 3, Zadatak 41
#include <iostream>
#include <string>

int BrojRijeci (std::string s) {
    int broj_rijeci=0,razmak=1;
    for (int i=0;i<s.length();i++) {
        if (s.at(i)==' ') {
            while (s.at(i)==' ') i++;
            razmak=1;
        }
        if (razmak==1) {
            razmak=0;
            broj_rijeci++;
        }
    }
    return broj_rijeci;
}

int main ()
{
    std::cout << BrojRijeci("AKihito je posjetio Jokohamu u srijedu.");
    
	return 0;
}