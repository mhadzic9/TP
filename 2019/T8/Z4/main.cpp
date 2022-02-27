//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

bool Razmak (char znak)
{
    if ((znak>='a' && znak<='z') || (znak>='0' && znak<='9')) return false;
    return true;
}

std::string ZamijeniPremaRjecniku (std::string s, std::map<std::string,std::string> m)
{
    bool razmak=true;
    for (int i=0; i<s.length(); i++) {
        int broj=0;
        if (Razmak(s[i])) razmak=true;
        else if (razmak) {
            razmak=false;
            int pocetak=i;
            while (!Razmak(s[i]) && i!=s.length()) {
                broj++;
                i++;
            }
            std::string rijec=s.substr(pocetak,broj);
            if (m.find(rijec)!=m.end()) {
                auto zamjena=m.find(rijec);
                s.replace(pocetak,broj,zamjena->second);
            }
            i--;
        }
    }
    return s;
}

int main ()
{
    std::map<std::string,std::string> moj_rjecnik {{"jabuka","apple"},{"da","yes"},{"kako","how"},{"ne","no"},{"majmun","monkey"}};
    std::cout << ZamijeniPremaRjecniku("kako da ne",moj_rjecnik);

    return 0;
}
