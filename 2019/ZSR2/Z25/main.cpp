//TP 2018/2019: ZSR 2, Zadatak 25
#include <iostream>
#include <vector>

bool DaLiRaste (std::vector<int> v)
{
    for (int i=0; i<v.size()-1; i+=2) {
        if (v.at(i)<v.at(i+1)) return false;
    }
    return true;
}

bool DaLiOpada (std::vector<int> v)
{
    for (int i=0; i<v.size()-1; i+=2) {
        if (v.at(i)>v.at(i+1)) return false;
    }
    return true;
}

bool Oscilatoran (std::vector<int> v)
{
    if (DaLiOpada(v)==false && DaLiRaste(v)==false) {
        return false;
    }
    return true;
}

int main ()
{
    std::vector<int> vekt;
    int a;
    std::cout << "Koliko zelite unijeti elemenata vektora: ";
    int n;
    std::cin >> n;
    do {
        if (n==0) break;
        std::cin >> a;
        vekt.push_back(a);
    } while (vekt.size()<n);
    if (Oscilatoran(vekt)==true && DaLiRaste(vekt)==true) {
        std::cout << "Uneseni vektor brojeva je oscilatoran i to u rastucem poretku.";
    } else if (Oscilatoran(vekt)==true && DaLiOpada(vekt)==true) {
        std::cout << "Uneseni vektor brojeva je oscilatoran i to u opadajucem poretku.";
    } else {
        std::cout << "Uneseni vektor brojeva nije oscilatoran.";
    }

    return 0;
}
