#include <iostream>
#include <vector>

using namespace std;

int NZD (vector<int> brojevi)
{
    if (brojevi.size() == 0)
        return 0;
    bool nule = true;
    int najveci = 0;
    for (auto &x : brojevi)
    {
        if (x != 0)
        {
            nule = false;
        }
        if (x < 0) x*=-1;
        if (x > najveci)
            najveci = x;
    }
    if (nule) return 0;
    int nzd = 0;
    for (int i = najveci; i > 0; i--)
    {
        bool pronadjen = true;
        for (auto x : brojevi)
        {
            if (x % i != 0)
                pronadjen = false;
        }
        if (pronadjen)
        {
            nzd = i;
            break;
        }
            
    }
    
    return nzd;
}


int main ()
{
	int n;
	cout << "Koliko ima brojeva: ";
	cin >> n;
	vector <int> brojevi(n);
	cout << "Unesite brojeve: ";
	for (auto &x : brojevi)
	{
	    cin >> x;
	}
	cout << "Njihov najveci zajednicki djelilac je " << NZD(brojevi);
	return 0;
	
}