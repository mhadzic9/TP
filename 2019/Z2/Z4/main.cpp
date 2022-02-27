//TP 2018/2019: Zadaća 2, Zadatak 4
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool ManjiString (string s1,string s2)
{
    if (s1.length()==s2.length()) {
        for (int i=0; i<s1.length(); i++) {
            if (toupper(s1.at(i))<toupper(s2.at(i)) || toupper(s2.at(i))<toupper(s1.at(i))) return true;
        }
    }
    if (s1.length()<s2.length() || s2.length()<s1.length())
        return true;
    return false;
}

void SortirajRecenice (string *pocetak, string *iza_kraja)
{
    if (iza_kraja<pocetak) throw domain_error ("Nije moguce sortiranje");
    sort (pocetak,iza_kraja,ManjiString);

}

int main ()
{
    int n;
    cout << "Unesite broj recenica: ";
    cin >> n;
    cin.ignore(10000,'\n');
    try {
        cout << "Unesite recenice: " << endl;
        string *niz=new string[n];
        for (int i=0; i<n; i++) {
            getline(cin,niz[i]);
        }
        SortirajRecenice(niz,niz+n);
        cout << "Recenice nakon sortiranja: " << endl;
        for (int i=0; i<n; i++) {
            cout << niz[i] << endl;
        }
        cout << endl;
        cout << "Unesite recenicu za pretragu: ";
        string recenica;
        getline(cin,recenica);
        if (binary_search(niz,niz+n,recenica,ManjiString)==true) {
            int indeks=0;
            for (int i=0; i<n; i++) {
                if (niz[i]==recenica) {
                    indeks=i;
                    break;
                }
            }
            cout << "Recenica se nalazi na poziciji: " << indeks;
        } else {
            cout << "Trazena recenica se ne nalazi u nizu!";
        }
        delete [] niz;
    } catch (bad_alloc) {
        cout << "Nedovoljno memorije!";
    } catch (domain_error izuzetak) {
        cout << izuzetak.what();
    }

    return 0;
}
