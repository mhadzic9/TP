/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 1) *** */
#include <iostream>

int main ()
{
    int a,b,c;
    std::cout << "Unesi prvo vrijeme (h min s): ";
    std::cin >> a >> b >> c;
    int q,w,e;
    std::cout << "Unesi drugo vrijeme (h min s): ";
    std::cin >> q >> w >> e;
    int x,y;
    x=a*3600+b*60+c;
    y=q*3600+w*60+e;
    z=y-x;
    int p=int(z/3600);
    int o=int(p)
	return 0;
}