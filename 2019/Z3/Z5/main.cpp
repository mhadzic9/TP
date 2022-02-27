#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

struct Clan
{
    int redni_broj;
    Clan* sljedeci;
};

int Poglavica (int brojClanova, int korak, bool printanje = false)
{
    //Kreiranje i popunjavanje cvorova
    Clan* pocetak = nullptr;
    Clan* prethodni = nullptr;
    for (int i = 1; i <= brojClanova; i++)
    {
        Clan *novi = new Clan{i, nullptr};
        if (!pocetak)
            pocetak = novi;
        else
            prethodni -> sljedeci = novi;
        prethodni = novi;
    }
    prethodni -> sljedeci = pocetak;
    
    //Brojanje
    Clan* pokazivac = pocetak;
    Clan* prethodniPokazivac = prethodni;
    int poglavica = 0;
    while (true)
    {
        //Brojanje
        for (int i = 0; i < korak-1; i++)
        {
            pokazivac = pokazivac -> sljedeci;
            prethodniPokazivac = prethodniPokazivac -> sljedeci;
        }
        //Printanje
        if (printanje)
        {
            cout << pokazivac->redni_broj << endl;
        }
        
        //Izbacivanje
        pokazivac = pokazivac -> sljedeci;
        delete prethodniPokazivac -> sljedeci;
        prethodniPokazivac -> sljedeci = pokazivac;
        
        //Kraj?!
        if (prethodniPokazivac -> sljedeci == prethodniPokazivac)
        {
            poglavica = prethodniPokazivac -> redni_broj;
            delete prethodniPokazivac -> sljedeci;
            break;
        }
    }
    return poglavica;
}

int SigurnoMjesto (int korak, int najmanje, int najvise)
{
    unordered_set<int> poglavice;
    for (int i = najmanje; i <= najvise; i++)
    {
        poglavice.insert(Poglavica(i, korak, 0));
    }
    
    for (int i = 1; i <= najmanje; i++)
    {
        if (!poglavice.count(i))
            return i;
    }
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
    cout << "Redni broj osobe koja postaje poglavica: " << Poglavica(N, M,1);
    cout << " Sigurno mjesto: " << SigurnoMjesto(M, N1, M1);
    return 0;
}