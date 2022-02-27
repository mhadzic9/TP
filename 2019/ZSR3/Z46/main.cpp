//TP 2018/2019: ZSR 3, Zadatak 46
#include <iostream>
#include <string>

std::string Satrovacki (std::string s) {
    std::string novi_string;
    for (int i=0;i<s.length();i++) {
        novi_string.push_back(s.at(i));
        if (s.at(i)=='a' || s.at(i)=='e' || s.at(i)=='i' || s.at(i)=='o' || s.at(i)=='u' || s.at(i)=='A' || s.at(i)=='E' || s.at(i)=='I' || s.at(i)=='O' || s.at(i)=='U') {
            novi_string.push_back('p');
            novi_string.push_back(s.at(i));
        }
    }
    
    return novi_string;
}

int main ()
{
    std::cout << Satrovacki("Dobar dan");
    
	return 0;
}