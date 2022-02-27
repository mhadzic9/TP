//TP 2018/2019: ZSR 2, Zadatak 32
#include <iostream>
#include <vector>
#include <cmath>

void Izbaci (std::vector<int> &v)
{
    for (int i=0; i<v.size(); i++) {
        int tmp1=v.at(i);
        int temp1=v.at(i);
        int c1;
        bool paran=true;
        while (tmp1!=0) {
            c1=abs(tmp1%10);
            if (c1%2!=0) {
                paran=false;
                break;
            }
            tmp1/=10;
        }
        if (paran==true) {
            for (int k=i;k<v.size()-1;k++) {
                temp1=v.at(k);
                v.at(k)=v.at(k+1);
                v.at(k+1)=temp1;
            }
            v.resize(v.size()-1);
            i--;
        }
    }
    for (int i=0; i<v.size(); i++) {
        int tmp2=v.at(i);
        int temp2=v.at(i);
        int c2;
        bool neparan=true;
        while (tmp2!=0) {
            c2=abs(tmp2%10);
            if (c2%2!=0) {
                neparan=false;
                break;
            }
            tmp2/=10;
        }
        if (neparan==true) {
            for (int k=i;k<v.size()-1;k++) {
                temp2=v.at(k);
                v.at(k)=v.at(k+1);
                v.at(k+1)=temp2;
            }
            v.resize(v.size()-1);
            i--;
        }
    }
}

int main ()
{
    std::vector<int> v;
    int a;
    std::cout << "Unosite elemente vektora (0 za kraj): ";
    do {
        std::cin >> a;
        if (a==0) break;
        v.push_back(a);
    } while (a!=0);
    Izbaci(v);
    for (int x:v) {
        std::cout << x << " ";
    }

    return 0;
}
