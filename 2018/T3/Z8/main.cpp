//TP 2017/2018: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>
#include <stdexcept>

std::string IzdvojiRijec(std::string Recenica, int br)
{
    int brojac=0;
    std::string rijec;
    Recenica="  " + Recenica + "  ";
    int P=0;
    while(Recenica[P]==' '  ) {
        P++;
    }
    P--;
    for(int i=P; i<Recenica.length(); i++) {
        if(Recenica[i]==' ') {
            while(Recenica[i]==' ') {
                i++;
            }
            brojac++;
            if(brojac==br) {
                while (Recenica[i]!=' ' && i<Recenica.length()) {
                    rijec=rijec+Recenica[i];
                    i++;
                }
            }
        }
    }
    if(brojac<br+1 || br<0) {
        throw std::range_error ("IZUZETAK: Pogresan redni broj rijeci!");
    }
    return rijec;
}




int main ()
{
    std::cout << "Unesite redni broj rijeci: ";
    int broj;
    std::cin >> broj;
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite recenicu: ";
    std::string s;
    getline(std::cin,s);
    try {
        IzdvojiRijec(s,broj);
        std::cout << "Rijec na poziciji " << broj << " je " << IzdvojiRijec(s,broj);
    } catch (std::range_error izuzetak) {
        std::cout << izuzetak.what();
    }

    return 0;
}
