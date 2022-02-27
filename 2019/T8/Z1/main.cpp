//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>

struct Vrijeme {
    int sati,minute,sekunde;
};

void TestirajVrijeme (const Vrijeme &vrijeme)
{
    if (vrijeme.sati<0 || vrijeme.sati>23 || vrijeme.minute<0 || vrijeme.minute>59 || vrijeme.sekunde<0 || vrijeme.sekunde>59) {
        throw std::domain_error ("Neispravno vrijeme");
    }

}
void IspisiVrijeme (const Vrijeme &vrijeme)
{
    try {
        TestirajVrijeme(vrijeme);

    } catch (std::domain_error k) {
        throw;
    }
    std::cout << std::setw(2) << std::setfill('0') << vrijeme.sati << ":" << std::setw(2) << std::setfill('0') << vrijeme.minute << ":" << std::setw(2) << std::setfill('0') << vrijeme.sekunde;
}

Vrijeme SaberiVrijeme(const Vrijeme &vrijeme1,const Vrijeme &vrijeme2)
{
    Vrijeme vrijeme3;
    try {
        TestirajVrijeme(vrijeme1);
        TestirajVrijeme(vrijeme2);
        vrijeme3.sati=vrijeme1.sati+vrijeme2.sati;
        vrijeme3.minute=vrijeme1.minute+vrijeme2.minute;
        vrijeme3.sekunde=vrijeme1.sekunde+vrijeme2.sekunde;
        if (vrijeme3.sekunde>59) {
            vrijeme3.sekunde-=60;
            vrijeme3.minute++;
        }
        if (vrijeme3.minute>59) {
            vrijeme3.minute-=60;
            vrijeme3.sati++;
        }
        if (vrijeme3.sati>23) {
            vrijeme3.sati%=24;
        }
    } catch (std::domain_error) {
        throw;
    }
    return vrijeme3;
}

int main ()
{
    Vrijeme v1,v2;
    std::cout << "Unesite prvo vrijeme (h m s): ";
    std::cin >> v1.sati >> v1.minute >> v1.sekunde;
    try {
        TestirajVrijeme(v1);
    } catch (std::domain_error izuzetak1) {
        std::cout << izuzetak1.what();
        return 0;
    }
    std::cout << "Unesite drugo vrijeme (h m s): ";
    std::cin >> v2.sati >> v2.minute >> v2.sekunde;
    try {
        TestirajVrijeme(v2);
    } catch (std::domain_error izuzetak2) {
        std::cout << izuzetak2.what();
        return 0;
    }
    std::cout << "Prvo vrijeme: ";
    try {
        IspisiVrijeme(v1);
    } catch (std::domain_error k1) {
        std::cout << k1.what();
    }
    std::cout << "\nDrugo vrijeme: ";
    try {
        IspisiVrijeme(v2);
    } catch (std::domain_error k2) {
        std::cout << k2.what();
    }
    std::cout << std::endl;
    std::cout << "Zbir vremena: ";
    try {
        IspisiVrijeme(SaberiVrijeme(v1,v2));
    } catch (std::domain_error a) {
        std::cout << a.what();
    }

    return 0;
}
