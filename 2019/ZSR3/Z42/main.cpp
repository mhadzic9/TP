//TP 2018/2019: ZSR 3, Zadatak 42
#include <iostream>
#include <string>

std::string UkloniSuvisneRazmake (std::string s) {
    std::string novi_string;
    for (int i=0;i<s.length()-1;i++) {
        while (s.at(i)!=' ' && i<s.length()) {
            novi_string.push_back(s.at(i));
            i++;
            if (i==s.length()) return novi_string;
            if (s.at(i)==' ') {
                novi_string.push_back(s.at(i));
                break;
            }
        }
    }
    return novi_string;
}

int main ()
{
    std::cout << UkloniSuvisneRazmake("Ovo   mi               je          skola.");
    
	return 0;
}