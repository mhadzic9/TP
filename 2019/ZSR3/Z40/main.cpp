//TP 2018/2019: ZSR 3, Zadatak 40
#include <iostream>
#include <string>

bool JeLiKorektna (std::string s) {
    for (int i=0;i<s.length();i++) {
        int brojac=0;
        while (s.at(i)!='a' && s.at(i)!='e' && s.at(i)!='i' && s.at(i)!='o' && s.at(i)!='u' && s.at(i)!='A' && s.at(i)!='E' && s.at(i)!='I' && s.at(i)!='O' && s.at(i)!='U') {
            brojac++;
            i++;
            if (brojac>2) return false;
            if (s.at(i)=='a' || s.at(i)=='e' || s.at(i)=='i' || s.at(i)=='o' || s.at(i)=='u' || s.at(i)=='A' || s.at(i)=='E' || s.at(i)=='I' || s.at(i)=='O' || s.at(i)=='U') {
                brojac=0;
                break;
            }
        }
    }
    return true;
}

int main ()
{
    std::string s;
    std::cout << "Unesite neku rijec: ";
    std::getline(std::cin,s);
    if (JeLiKorektna(s)==true) {
        std::cout << "Rijec je korektna.";
    }
    else {
        std::cout << "Rijec nije korektna.";
    }
    
	return 0;
}