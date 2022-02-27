//TP 2017/2018: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<int>> PascalovTrougao(int n)
{
    if(n==0)
        return std::vector<std::vector<int>>(0,std::vector<int>(0));
    if(n<0)
        throw std::domain_error("Broj redova ne smije biti negativan");
    std::vector<std::vector<int>> m(n);
    for(int i=0; i<n; i++)
        m.at(i).resize(i+1);
    for(int i=0; i<n; i++)
        for(int j=0; j<i+1; j++) {
            if(i==j || j==0)
                m.at(i).at(j)=1;
            else
                m.at(i).at(j)=m.at(i-1).at(j)+m.at(i-1).at(j-1);
        }
    return m;
}
int velicina (int n)
{
    int vel=0;
    if(n<0)
        vel++;
    do {
        n/=10;
        vel++;
    } while(n);
    return vel;
}
int NajvecaSirina(std::vector<std::vector<int>> m)
{
    if(!m.size())
        return 0;
    int najduzi=m.at(0).at(0);
    for(std::vector<int> red:m)
        for(int el:red)
            if(velicina(el)>velicina(najduzi))
                najduzi=el;
    return velicina(najduzi);
}

int main()
{
    std::cout<<"Unesite broj redova: ";
    int n;
    std::cin >> n;
    std::cout << std::endl;
    std::vector<std::vector<int>> m=PascalovTrougao(n);
    for (int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++)

            std::cout << std::setw(NajvecaSirina(m)+1) << m.at(i).at(j);
        std::cout << std::endl;


    }

    return 0;
}
