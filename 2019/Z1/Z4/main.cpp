//TP 2016/2017: Zadaća 1, Zadatak 4
#include <iostream>
#include <string>

bool Samoglasnik (char x)
{
    if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U') {
        return true;
    }
    return false;
}
bool Suglasnik (char y)
{
    if (Samoglasnik(y)==0 && y!=' ') {
        return true;
    }
    return false;
}
std::string IstakniSavrsenoRitmicneRijeci (std::string s)
{
    std::string rijec;
    int valja;
    if (s.length()==1) return s;
    for (int i=0; i<s.size(); i++) {
        if(s.at(i)==' ') {
            while (s.at(i)==' ') {
                rijec=rijec + " ";
                i++;
                if (i==s.length()) {
                    return rijec;
                }

            }
        }
        valja=1;
        int p=i;
        if (p==s.size()-1) rijec=rijec+s.at(i);
        else {
            while (s.at(p+1)!=' ' && p<s.size()-1) {
                if (((Samoglasnik(s.at(p)) && Samoglasnik(s.at(p+1))) || (Suglasnik(s.at(p)) && Suglasnik(s.at(p+1)))))
                    valja=0;
                p++;
                if (p==s.size()-1) break;
            }
            int razlika=p-i;
            if (valja && razlika>=1) {
                rijec=rijec+'(';
                while (s.at(i)!=' ' && i<s.size()) {
                    rijec=rijec+s.at(i);
                    i++;
                    if (i==s.size()) break;
                }
                rijec=rijec+')';
                i--;
            } else {
                while (s.at(i)!=' ' && i<s.size()) {
                    rijec=rijec+s.at(i);
                    i++;
                    if (i==s.size()) break;
                }
                rijec=rijec+" ";
            }
        }

    }
    return rijec;
}

int main ()
{
    std::string s;
    std::cout << "Unesite recenicu (ENTER za kraj): ";
    std::getline(std::cin,s);
    if (s.size()!=0) {
        std::cout << "Recenica sa istaknutim savrseno ritmicnim rijecima glasi: " << std::endl;
        std::cout << IstakniSavrsenoRitmicneRijeci(s);
    } else  std::cout << "Recenica sa istaknutim savrseno ritmicnim rijecima glasi: " << std::endl;


    return 0;
}
