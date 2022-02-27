//TP 2017/2018: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>

int main ()
{
    double a,b,c;
    std::cout << "Unesite tri broja: ";
    std::cin >> a >> b >> c;
    if((a<=0 || b<=0 || c<=0) || ((a+b)<=c) || ((a+c)<=b) || ((b+c)<=a)) {
        std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!" << std::endl;
    } else {
        double O;
        O=a+b+c;
        std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << O << "." << std::endl;
        double P,s;
        s=(a+b+c)/2;
        P=sqrt(s*(s-a)*(s-b)*(s-c));
        std::cout << "Njegova povrsina iznosi " << P << "." << std::endl;
        double q,w,e;
        q=acos((a*a+b*b-c*c)/(2*a*b));
        w=acos((a*a+c*c-b*b)/(2*a*c));
        e=acos((b*b+c*c-a*a)/(2*b*c));

        double min=q;
        if(w<min) min=w;
        if(e<min) min=e;

        double const PI=4*atan(1);
        min=min*(180./PI);

        int f=int(min);
        int g=int((min-f)*60);
        int h=int((((min-f)*60)-g)*60);


        std::cout << "Njegov najmanji ugao ima " << f << " stepeni" << ", " << g << " minuta " << "i " << h << " sekundi." << std::endl;
    }
    return 0;
}
