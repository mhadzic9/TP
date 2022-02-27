//TP 2018/2019: ZSR 3, Zadatak 8
#include <iostream>
#include <vector>

std::vector<double> Napravi (std::vector<double> A, std::vector<int> B) {
    std::vector<double> v;
    for (int i=0;i<B.size();i++) {
        if (B.at(i)<0 || B.at(i)>=A.size()) throw std::range_error ("Ne moze tako!");
    }
    for (int i=0;i<B.size();i++) {
        v.push_back(A.at(B.at(i)));
    }
    return v;
}

int main ()
{
    std::vector<double> v1;
    std::vector<double> v3;
    std::vector<int> v2;
    std::cout << "Unesite broj elemenata vektora A: ";
    int n1;
    std::cin >> n1;
    std::cout << "Unesite elemente vektora A: ";
    double a;
    do {
        std::cin >> a;
        v1.push_back(a);
    } while (v1.size()<n1);
    std::cout << "Unesite broj elemenata vektora B: ";
    int n2;
    std::cin >> n2;
    std::cout << "Unesite elemente vektora B: ";
    int b;
    do {
        std::cin >> b;
        v2.push_back(b);
    } while (v2.size()<n2);
    try {
        v3=Napravi(v1,v2);
        for (double x:v3) {
            std::cout << x << " ";
        }
    }
    catch (std::range_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    
	return 0;
}