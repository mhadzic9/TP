//TP 2018/2019: Ispit 5, Zadatak 4
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename prviTip, typename drugiTip>
auto ZbirKontejnera(prviTip prvi, drugiTip drugi) -> vector<decltype(*(prvi.begin())+*(drugi.begin()))>
{
    using vek = vector< decltype(*(prvi.begin())+*(drugi.begin()))>;
    auto it1 = prvi.begin();
    auto it2 = drugi.begin();
    
    vek zbirovi;
    
    int brojac1 = 0, brojac2 = 0;
    
    while (it1 != prvi.end())
    {
        brojac1++; it1++;    
    }
    
    while (it2 != drugi.end())
    {
        brojac2++;
        it2++;
    }
    
    if (brojac1 > brojac2)
    {
        it1 = prvi.begin();
        it2 = drugi.begin();
        while (it1 != prvi.end())
        {
            if (it2 != drugi.end())
            {
                zbirovi.push_back(*it1 + *it2);
                it2++;
            }
            else
            {
                zbirovi.push_back(*it1);
            }
            it1++;
        }
    }
    else
    {
        it1 = prvi.begin();
        it2 = drugi.begin();
        while (it2 != drugi.end())
        {
            if (it1 != prvi.end())
            {
                zbirovi.push_back(*it1 + *it2);
                it1++;
            }
            else
            {
                zbirovi.push_back(*it2);
            }
            it2++;
        }
    }
    return zbirovi;
}



int main ()
{
// 	vector <int> veka {1, 2, 3, 5};
// 	queue<double> deki {1.4, 2.3, 1.1};
	
// 	auto ispis = ZbirKontejnera(veka, deki);
// 	for (auto k : ispis)
// 	{
// 	    cout << k << " ";
// 	}
}