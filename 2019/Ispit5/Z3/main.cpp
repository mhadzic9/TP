//TP 2018/2019: Ispit 5, Zadatak 3
#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>

using namespace std;

bool Palindrom(string rijec)
{
    for (int i = 0; i < rijec.length()/2; i++)
        if (toupper(rijec.at(i)) != toupper(rijec.at(rijec.size()-i-1)))
            return false;
            
    return true;
}

vector<string> IzdvojiPalindromskeRijeci(string recenica)
{
    vector<string> rijeci;
    string rijec;
    for (auto slovo : recenica)
    {
        if ((slovo >= 'a' && slovo <= 'z') || (slovo >='A' && slovo <='Z'))
            rijec+=slovo;
        else
        {
            if (rijec.length() > 1)
                rijeci.push_back(rijec);
            rijec.clear();
        }
    }
    
    if (rijec.length() > 1)
            rijeci.push_back(rijec);
    
    vector<string> povratni;
    for (auto rijec : rijeci)
    {
        if (Palindrom(rijec))
           povratni.push_back(rijec); 
    }
    
    return povratni;
}


int main ()
{
	cout << "Unesite string: ";
	string a;
	getline(cin, a);
	
	auto vek = IzdvojiPalindromskeRijeci(a);
	for (auto k : vek)
	{
	    cout << k << endl;
	}
	
	return 0;
}