//TP 2018/2019: ZSR 3, Zadatak 49
#include <iostream>
#include <string>
#include <vector>

bool DaLiJeStringBroj (std::string s)
{
    if (s.at(0)=='.' || s.at(0)=='?' || s.at(0)=='!') return false;
    for (int i=0; i<s.length()-1; i++) {
        if (s.at(i)!='0' && s.at(i)!='1' && s.at(i)!='2' && s.at(i)!='3' && s.at(i)!='4' && s.at(i)!='5' && s.at(i)!='6' && s.at(i)!='7' && s.at(i)!='8' && s.at(i)!='9') {
            return false;
        }
        if (s.at(i+1)=='.' || s.at(i+1)=='?' || s.at(i+1)=='!') {
            while ((s.at(i+1)=='.' || s.at(i+1)=='?' || s.at(i+1)=='!') && i<s.length()-2) {
                i++;
                if (s.at(i)!='.' && s.at(i)!='?' && s.at(i)!='!') return false;
            }
        }
    }
    return true;
}

std::vector<std::string> BrojeviUStringu (std::string s)
{
    std::vector<std::string> v;
    for (int i=0; i<s.length(); i++) {
        std::string rijec;
        if (s.at(i)==' ' && i<s.length()-1) {
            while (s.at(i)==' ') {
                i++;
            }
        }
        while (s.at(i)!=' ' && i<s.length()) {
            rijec=rijec+s.at(i);
            i++;
            if (i==s.length()) break;
        }
        if (DaLiJeStringBroj(rijec)==true) {
            v.push_back(rijec);
        }
    }
    return v;
}

int main ()
{
    std::string s;
    std::cout << "Unesite neki string: ";
    std::getline(std::cin,s);
    std::vector<std::string> v=BrojeviUStringu(s);
    if (v.size()==0) {
        std::cout << "Niste unijeli nista sto bi se moglo ispisati!";
        return 0;
    }
    for (std::string x:v) {
        std::cout << x << " ";
    }

    return 0;
}
