//TP 2018/2019: ZSR 3, Zadatak 56
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Rijeci (std::string s) {
    std::vector<std::string> v;
    for (int i=0;i<s.length();i++) {
        std::string rijec;
        if (s.at(i)==' ') {
            while (s.at(i)==' ' && i<s.length()) {
                i++;
            }
        }
        while (s.at(i)!=' ' && i<s.length()) {
            rijec.push_back(s.at(i));
             if (i==s.length()-1) break;
            i++;
            
        }
        v.push_back(rijec);
    }
    return v;
}

int main ()
{
    std::vector<std::string> v=Rijeci("Danas je lijep i suncan dan");
    for (std::string x:v) {
        std::cout << x << std::endl;
    }
    
	return 0;
}