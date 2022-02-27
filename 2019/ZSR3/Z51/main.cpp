//TP 2018/2019: ZSR 3, Zadatak 51
#include <iostream>
#include <string>
#include <vector>

std::string Funkcija (std::string s,std::vector<double> v) {
    std::string novi_string;
    int broj=0;
    for (int i=0;i<s.length();i++) {
        if (s.at(i)=='%' && s.at(i+1)=='d' && i<s.length()-1 && broj<v.size()-1) {
        novi_string=novi_string+std::to_string(int(v.at(broj)));
        i+=2;
        if (i==s.length()) break;
        broj++;
    }
    if (s.at(i)=='%' && s.at(i+1)=='f' && i<s.length()-2 && broj<v.size()-1) {
        novi_string=novi_string+std::to_string((v.at(broj)));
        i+=2;
        if (i==s.length()) break;
        broj++;
}
    novi_string.push_back(s.at(i));
}
return novi_string;
}

int main ()
{
    std::cout << Funkcija("abc%dxx%fyy %d " , {12.25, 34.13, 25 , 47});
    
	return 0;
}