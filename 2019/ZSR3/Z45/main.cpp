//TP 2018/2019: ZSR 3, Zadatak 45
#include <iostream>
#include <string>

std::string Razmaci (std::string s,char znak) {
    std::string novi_string;
    int a=0;
    if (s.at(a)==' ') {
        while (s.at(a)==' ') {
            a++;
        }
    }
    for (int i=a;i<s.length();i++) {
        if (s.at(i)==' ' && i<s.length()-1) {
            novi_string.push_back(znak);
            i++;
            while (s.at(i)==' ') {
                i++;
                if (i==s.length()) return novi_string;
            }
        }
        novi_string.push_back(s.at(i));
    }
    return novi_string;
}

int main ()
{ 
    std::cout << Razmaci(" Danas je ispit iz TP-a ",',');
    
	return 0;
}