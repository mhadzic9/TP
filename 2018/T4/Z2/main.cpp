//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>

void IzvrniString (std::string &s)
{
    int i=0;
    int j=s.length()-1;
    while (i<j) {
        char c=s.at(i);
        s.at(i)=s.at(j);
        s.at(j)=c;
        i++;
        j--;
    }
}


int main ()
{
    std::string s;
    std::cout << "Unesi string: ";
    std::getline(std::cin,s);
    IzvrniString(s);
    std::cout << "Izvrnuti string je: " << s;

    return 0;
}
