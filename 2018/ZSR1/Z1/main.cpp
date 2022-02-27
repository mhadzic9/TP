//TP 2017/2018: ZSR 1, Zadatak 1
#include <iostream>

int main ()
{
    int a,b,c;
    std::cout << "Unesi prvo vrijeme (h min s)" << std::endl;
    std::cin >> a >> b >> c;
    int q,w,e;
    std::cout << "Unesi drugo vrijeme (h min s)" << std:: endl;
    std::cin >> q >> w >> e;
    int t;
    t=(((q*3600)+w*60)+e) - (((a*3600)+b*60)+c);
    double g,h,j;
    g=t/3600;
    h=(t/60)-g*60;
    j=t-g*3600-h*60;
    std::cout << "Izmedu ova dva trenutka proteklo je " << g << "h " << h << "min " << "i " << j << "s." << std::endl;
	return 0;
}
