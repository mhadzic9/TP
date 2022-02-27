//TP 2018/2019: ZSR 3, Zadatak 55
#include <iostream>
#include <string>

int NadjiString (std::string s1, std::string s2)
{
    int indeks;
    for (int i=0; i<s1.length(); i++) {
        std::string rijec;
        if (s2.at(0)==s1.at(i)) {
            indeks=i;
            while (rijec.length()<s2.length() && i<s1.length()) {
                rijec.push_back(s1.at(i));
                if (i==s1.length()-1) break;
                i++;

            }
        }
        if (rijec==s2) return indeks;
    }
    return -1;
}

int main ()
{
    std::cout << NadjiString("Danas je lijep", "je lijep");

    return 0;
}
