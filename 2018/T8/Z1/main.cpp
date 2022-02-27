//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>
struct Vrijeme {
    int sati;
    int minute;
    int sekunde;
};
void TestirajVrijeme(const Vrijeme &vrijeme)
{
    if(vrijeme.sati<0 || vrijeme.sati>23 || vrijeme.sekunde<0 || vrijeme.sekunde>59 || vrijeme.minute<0 || vrijeme.minute>59)
        throw std::domain_error("Neispravno vrijeme");
}
void IspisiVrijeme(const Vrijeme &vrijeme)
{
    try {
        TestirajVrijeme(vrijeme);
    } catch(std::domain_error k) {
        throw;
    }
    std::cout << std::setw(2) << std::setfill('0') << vrijeme.sati << ":" << std::setw(2) << std::setfill('0') << vrijeme.minute << ":" << std::setw(2) << std::setfill('0') << vrijeme.sekunde;
}
Vrijeme SaberiVrijeme(const Vrijeme &v1, const Vrijeme &v2)
{
    Vrijeme v3;
    try {
        TestirajVrijeme(v1);
        TestirajVrijeme(v2);
    } catch(std::domain_error k) {
        std::cout << k.what() << std::endl;
    }
    v3.sekunde=v1.sekunde+v2.sekunde;
    v3.minute=v1.minute+v2.minute;
    v3.sati=v1.sati+v2.sati;
    if(v3.sekunde>59) {
        v3.sekunde-=60;
        v3.minute++;
    }
    if(v3.minute>59) {
        v3.minute-=60;
        v3.sati++;
    }
    if(v3.sati>23) {
        v3.sati%=24;
    }
    return v3;
}

int main ()
{
    Vrijeme vrijeme1,vrijeme2;
    std::cout << "Unesite prvo vrijeme (h m s): ";
    std::cin >> vrijeme1.sati >> vrijeme1.minute >> vrijeme1.sekunde;
    try {
        TestirajVrijeme(vrijeme1);
    } catch (std::domain_error k) {
        std::cout << k.what();
        return 0;
    }
    std::cout << "Unesite drugo vrijeme (h m s): ";
    std::cin >> vrijeme2.sati >> vrijeme2.minute >> vrijeme2.sekunde;
    try {
        TestirajVrijeme(vrijeme2);
    } catch (std::domain_error k) {
        std::cout << k.what();
        return 0;
    }
    std::cout << "Prvo vrijeme: ";
    try {
        IspisiVrijeme(vrijeme1);
    } catch(std::domain_error k) {
        std::cout << k.what();
        return 0;
    }
    std::cout << "\nDrugo vrijeme: ";
    try {
        IspisiVrijeme(vrijeme2);
    } catch (std::domain_error k) {
        std::cout << k.what();
        return 0;
    }
    std::cout << std::endl << "Zbir vremena: ";
    try {
        IspisiVrijeme(SaberiVrijeme(vrijeme1,vrijeme2));
    } catch(std::domain_error k) {
        std::cout << k.what();
        return 0;
    }

    return 0;
}
