//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>

template <typename Tip>
std::vector<Tip> Presjek (std::vector<Tip> v1,std::vector<Tip> v2)
{
    std::vector<Tip> v3;
    for (int i=0; i<v1.size(); i++) {
        for (int j=0; j<v2.size(); j++) {
            if (v1.at(i)==v2.at(j)) {
                v3.push_back(v1.at(i));
            }
        }
    }
    int i=0,j=0;
    while (i<v3.size()) {
        j=i+1;
        while (j<v3.size()) {
            if (v3.at(i)==v3.at(j)) {
                v3.erase(v3.begin()+j);
                j--;
            }
            j++;
        }
        i++;
    }

    return v3;
}

int main ()
{
    std::cout << "Test za realne brojeve..." << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int n1;
    std::cin >> n1;
    std::cout << "Unesite elemente prvog vektora: ";
    std::vector <double> v1;
    double a1;
    int brojac1=0;
    do {
        std::cin >> a1;
        v1.push_back(a1);
        brojac1++;
        if (brojac1==n1) break;
    } while (brojac1!=n1);

    std::cout << "Unesite broj elemenata drugog vektora: ";
    int n2;
    std::cin >> n2;
    std::cout << "Unesite elemente drugog vektora: ";
    std::vector <double> v2;
    double a2;
    int brojac2=0;
    do {
        std::cin >> a2;
        v2.push_back(a2);
        brojac2++;
        if (brojac2==n2) break;
    } while (brojac2!=n2);

    std::cout << "Zajednicki elementi su: ";
    auto v3 = Presjek(v1, v2);
    for(auto x : v3) std::cout << x << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Test za stringove..." << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int n3;
    std::cin >> n3;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa):" << std::endl;
    std::vector <std::string> v4;
    std::string s1;
    do {
        std::getline(std::cin,s1);
        v4.push_back(s1);
    } while (v4.size()<n3);

    std::cout << "Unesite broj elemenata drugog vektora: ";
    int n4;
    std::cin >> n4;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa):" << std::endl;
    std::vector<std::string> v5;
    std::string s2;
    do {
        std::getline(std::cin,s2);
        v5.push_back(s2);
    } while (v5.size()<n4);
    std::cout << "Zajednicki elementi su: ";
    auto v6 = Presjek(v4, v5);
    for(auto y : v6) {
        std::cout << std::endl;
        std::cout << y << " ";
    }

    return 0;
}
