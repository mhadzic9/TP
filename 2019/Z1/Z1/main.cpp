//TP 2016/2017: Zadaća 1, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

int NaopakiBroj (int n)
{
    int naopako=0,c;
    while (n!=0) {
        c=abs(n%10);
        naopako=naopako*10+c;
        n/=10;
    }
    return naopako;
}

std::vector<int> TernarBroja (int n)
{
    int c;
    std::vector<int> v;
    while (n!=0) {
        c=abs(n%3);
        v.push_back(c);
        n/=3;
    }
    return v;
}
std::vector<int> Obrni (std::vector<int> v)
{
    std::vector<int> ve;
    for (int i=v.size()-1; i>=0; i--) {
        ve.push_back(v.at(i));
    }
    return ve;
}
bool UporediVektore (std::vector<int> v1, std::vector<int> v2)
{
    for (int i=0; i<v1.size(); i++) {
        if(v1.at(i)!=v2.at(i)) {
            return false;
        }
    }
    return true;
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool vrijednost=true)
{
    std::vector<int> vek;
    if (v.size()==0) {
        return v;
    }
    if (vrijednost==true) {
        for (int i=0; i<v.size(); i++) {
            if (abs(v.at(i))==NaopakiBroj(abs(v.at(i))) && UporediVektore(TernarBroja(v.at(i)),Obrni(TernarBroja(v.at(i)))))  {
                vek.push_back(v.at(i));
            }
        }
    }
    if (vrijednost==false) {
        for (int i=0; i<v.size(); i++) {
            if (abs(v.at(i))!=NaopakiBroj(abs(v.at(i))) && UporediVektore(TernarBroja(v.at(i)),Obrni(TernarBroja(v.at(i))))) {
                vek.push_back(v.at(i));
            }
        }
    }
    if (vek.size()==0) {
        return vek;
    }
    for (int i=0; i<vek.size()-1; i++) {
        for (int j=i+1; j<vek.size(); j++) {
            if (vek.at(j)==vek.at(i)) {
                vek.erase(vek.begin()+j);
                j--;
            }
        }
    }
    return vek;

}

int main ()
{
    int n,brojac=0;
    std::cout << "Unesite broj elemenata niza: ";
    std::cin >> n;
    std::vector<int> v1;
    std::cout << "Unesite elemente niza: ";
    int a;
    do {
        if (n==0) break;
        std::cin >> a;
        v1.push_back(a);
        brojac++;
        if (brojac==n) break;

    } while (brojac<n);
    int m;
    std::cout << "Unesite parametar (1 ili 0): ";
    std::cin >> m;
    std::vector<int> v2;
    std::cout << "Izdvojeni elementi su: ";
    if (n==0) {
        return 0;
    }
    if (m==1) {
        v2=IzdvojiSimetricneTernarne(v1,true);
        if (v2.size()==0) return 0;
        for (int i=0; i<v2.size(); i++) {
            if(i<v2.size()-1) {
                std::cout << v2.at(i) << ", ";
            } else if (i==v2.size()-1) {
                std::cout << v2.at(i);
            }
        }
    }
    if (m==0) {
        v2=IzdvojiSimetricneTernarne(v1,false);
        if (v2.size()==0) return 0;
        for (int i=0; i<v2.size(); i++) {
            if(i<v2.size()-1) {
                std::cout << v2.at(i) << ", ";
            } else if (i==v2.size()-1) {
                std::cout << v2.at(i);
            }
        }
    }

    return 0;
}
