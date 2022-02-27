//TP 2018/2019: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>
#include <stdexcept>

std::string IzdvojiRijec (std::string s,int a)
{
    std::string rijec;
    int broj=0,razmak=1;
    for (int i=0; i<s.length(); i++) {
        if (s.at(i)==' ') {
            razmak=1;
        } else if (razmak==1) {
            razmak=0;
            broj++;
        }
        if (broj==a) {
            while (s.at(i)!=' ' && i<s.length()) {
                rijec=rijec+s.at(i);
                i++;
                if (i==s.length()) break;

            }
            return rijec;
        }
    }
    if (broj<a || a<0) {
        throw std::range_error ("IZUZETAK: Pogresan redni broj rijeci!");
    }
    return rijec;
}

int main ()
{
    int n;
    std::cout << "Unesite redni broj rijeci: ";
    std::cin >> n;
    std::cin.ignore(10000,'\n');
    std::string str;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin,str);
    try {
        IzdvojiRijec(str,n);
        std::cout << "Rijec na poziciji " << n << " je " << IzdvojiRijec(str,n);
    } catch (std::range_error izuzetak) {
        std::cout << izuzetak.what();
    }

    return 0;
}
