#include <iostream>
#include <list>
#include <unordered_set>
// #include <iterator>

using namespace std;

int Poglavica (int brojClanova, int korak, bool printanje = false)
{
    //Kreiranje i popunjavanje liste
    list<int> clanovi (brojClanova);
    int broj = 1;
    for (auto &clan : clanovi)
    {
        clan = broj;
        broj++;
    }
    
    //Brojanje
    auto iteratorListe = clanovi.begin();
    while (clanovi.size() > 1)
    {
        //Brojanje
        for (int i = 0; i < korak-1; i++)
        {
            iteratorListe++;
            if (iteratorListe == clanovi.end())
            {
                iteratorListe = clanovi.begin();
            }
        }
        //Printanje
        if (printanje)
            cout << *iteratorListe << endl;
        
        //Izbacivanje
        iteratorListe = clanovi.erase(iteratorListe);
        if (iteratorListe == clanovi.end()) //Prethodno je izbacen prethodni clan
            iteratorListe = clanovi.begin();
    }
    
    return *clanovi.begin();
}

int SigurnoMjesto (int korak, int najmanje, int najvise)
{
    unordered_set<int> poglavice;
    for (int i = najmanje; i <= najvise; i++)
        poglavice.insert(Poglavica(i, korak, 0));
    
    for (int i = 1; i <= najmanje; i++)
        if (!poglavice.count(i))
            return i;
    return 0;
}

int main ()
{
    int N, M, N1, M1;
    cout << "Unesi broj punoljetnih clanova (N): ";
    cin >> N;
    cout << "Unesi korak razbrajanja (M): ";
    cin >> M;
    cout << "Unesi raspon (N1-N2): ";
    cin >> N1 >> M1;
    cout << "Redni broj osobe koja postaje poglavica: " << Poglavica(N, M);
    cout << " Sigurno mjesto: " << SigurnoMjesto(M, N1, M1);
    return 0;
}