//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <vector>
#include <string>

void VelikaUMala (std::string &s)
{
    for (char &x:s) {
        if (x>='A' && x<='Z') x+=32;
    }
}

void IzdvojiKrajnjeRijeci (std::vector<std::string> v,std::string &s1, std::string &s2)
{
    if (v.size()==0) {
        s1="";
        s2="";
    } else {
        std::vector<std::string> v1(v);
        for (int i=0; i<v1.size(); i++) {
            VelikaUMala(v1.at(i));
        }
        int max=0,min=0;
        s1=v1.at(0);
        s2=v1.at(0);
        for (int i=1; i<v1.size(); i++) {
            if (v1.at(i)<s1) {
                max=i;
                s1=v1.at(i);
            } else if (v1.at(i)>s2) {
                min=i;
                s2=v1.at(i);
            }
        }
        s1=v.at(max);
        s2=v.at(min);
    }
}

void ZadrziDuplikate (std::vector<std::string> &v)
{
    std::vector<std::string> vek;
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            int duplikat=0;
            std::string rijec=v.at(i);
            if (rijec==v.at(j)) {
                for (int k=0; k<vek.size(); k++) {
                    if (rijec==vek.at(k)) duplikat++;
                }
                if (duplikat==0) vek.push_back(rijec);
            }
        }
    }
    v=std::move(vek);

}

int main ()
{
    int n;
    std::cout << "Koliko zelite unijeti rijeci: ";
    std::cin >> n;
    std::cin.ignore (10000,'\n');
    std::cout << "Unesite rijeci: ";
    std::string s;
    std::vector<std::string> v;
    do {
        std::cin >> s;
        v.push_back(s);
    } while (v.size()<n);
    std::string prva;
    std::string druga;
    IzdvojiKrajnjeRijeci(v,prva,druga);
    std::cout <<"Prva rijec po abecednom poretku je: " << prva << std::endl;
    std::cout << "Posljednja rijec po abecednom poretku je: " << druga << std::endl;
    ZadrziDuplikate(v);
    std::cout << "Rijeci koje se ponavljaju su: ";
    for (int i=0; i<v.size(); i++)
        std::cout << v.at(i) << " ";
    return 0;
}
