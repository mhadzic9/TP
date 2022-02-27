//TP 2018/2019: Tutorijal 8, Zadatak 5
#include <iostream>
#include <tuple>
typedef std::tuple<double,double,double> Vektor3d;
void UnesiVektor(Vektor3d &v)
{
    std::cout << "X = ";
    std::cin >> std::get<0>(v);
    std::cout << "Y = ";
    std::cin >> std::get<1>(v);
    std::cout << "Z = ";
    std::cin >> std::get<2>(v);
}
Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
    auto a=std::get<0>(v1) + std::get<0>(v2);
    auto b=std::get<1>(v1) + std::get<1>(v2);
    auto c=std::get<2>(v1) + std::get<2>(v2);
    auto m=std::tie(a,b,c);
    return {std::get<0>(m), std::get<1>(m), std::get<2>(m)};
}
Vektor3d VektorskiProizvod(const Vektor3d &v1, const Vektor3d &v2)
{
    auto a=std::get<1>(v1) * std::get<2>(v2) - std::get<2>(v1) * std::get<1>(v2);
    auto b=std::get<2>(v1) * std::get<0>(v2) - std::get<0>(v1) * std::get<2>(v2);
    auto c=std::get<0>(v1) * std::get<1>(v2) - std::get<1>(v1) * std::get<0>(v2);
    auto m=std::tie(a,b,c);
    return {std::get<0>(m), std::get<1>(m), std::get<2>(m)};
}
void IspisiVektor (const Vektor3d &v)
{
    std::cout << "{" << std::get<0>(v) << "," << std::get<1>(v) << "," << std::get<2>(v) << "}";
}

int main ()
{
    Vektor3d a,b;
    std::cout << "Unesi prvi vektor:\n";
    UnesiVektor(a);
    std::cout << "Unesi drugi vektor:\n";
    UnesiVektor(b);
    std::cout << "Suma ova dva vektora je: ";
    IspisiVektor(ZbirVektora(a,b));
    std::cout << std::endl << "Njihov vektorski prozivod je: ";
    IspisiVektor(VektorskiProizvod(a,b));
    return 0;
}
