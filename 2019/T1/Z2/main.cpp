//TP 2018/2019: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>

int main ()
{
    double a,b,c;
    std::cout << "Unesite tri broja: ";
    std::cin >> a >> b >> c;
    if (a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a) {
        std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!" << std::endl;
        return 0;
    }
    double s=(a+b+c)/2;
    double o,p;
    o=a+b+c;
    p=std::sqrt(s*(s-a)*(s-b)*(s-c));
    double gama_a,gama_b,gama_c;
    gama_c=acos((a*a+b*b-c*c)/(2*a*b));
    gama_b=acos ((a*a+c*c-b*b)/(2*a*c));
    gama_a=acos ((b*b+c*c-a*a)/(2*b*c));
    double PI=4*atan(1);
    double min_ugao=gama_a;
    if (gama_a<gama_b && gama_a<gama_c) {
        min_ugao=gama_a;
    }
    if (gama_b<gama_a && gama_b<gama_c) {
        min_ugao=gama_b;
    }
    if (gama_c<gama_b && gama_c<gama_a) {
        min_ugao=gama_c;
    }
    double ugao=min_ugao*180/PI;
    int stepeni,minute,sekunde;
    double minute1,sekunde1;
    stepeni=int(ugao);
    minute1=(ugao-int(ugao))*60;
    sekunde1=(minute1-int(minute1))*60;
    minute=int(minute1);
    sekunde=int(sekunde1);
    std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << o << "." << std::endl;
    std::cout << "Njegova povrsina iznosi " << p << "." << std::endl;
    std::cout << "Njegov najmanji ugao ima " << stepeni << " stepeni, " << minute << " minuta i " << sekunde << " sekundi." << std::endl;

    return 0;
}
