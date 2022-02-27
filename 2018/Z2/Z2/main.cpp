/* TP, 2018/2019
*/
#include <iostream>
#include <cmath>
#include <stdexcept>
bool Kvadrat(int n) {
    for(int i=1;i<n/2;i++) {
        if(i*i==n)
        return true;
    }
    return false;
}

void RastavaBroja (int n,int& p,int& q) {
    if((n!=int (n)) || (n<=0)) throw std::domain_error("Broj koji se rastavlja mora biti prirodan");
    if(n>1) {
        int i;
        for(i=n/2;i>1;i--) {
            if((n%i==0) && (Kvadrat(i))) {break;}
        }
        if(i==1) {
            p=n;
            q=1;
        }
        if(i!=1) {
            q=sqrt(i);
            p=n/(q*q);
        }
        
    }
}

int main () {
    int a,b;
    RastavaBroja(22360800,a,b);
    std::cout << a << " " << b;
	return 0;
}