#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <type_traits>

using namespace std;

template <typename cjelobrojniTip>
bool ImaKvadrata(cjelobrojniTip broj)
{
    if (broj < 0)
        broj*=-1;
    for (int i = 2; i*i <= broj; i++)
    {
        if (broj % (i*i) == 0)
            return true;
    }
    return false;
}

template <typename cjelobrojniTip>
int DajSumuProstih(cjelobrojniTip broj)
{
    if (broj < 0)
        broj*=-1;
    
    int suma = 0;
    cjelobrojniTip broj_rezervni = broj;
    int i = 2; 
    while(broj != 1)
    {
        if (i > broj_rezervni)
            break;
        if (broj%i == 0)
        {
            suma+=i;
            while(broj % i == 0)
            {
                broj/=i;
            }
        }
        i++;
    }
    return suma;
}

template <typename itertip, typename cjelobrojniTip>
bool PonavljaSe(itertip pocetak, itertip kraj, cjelobrojniTip vrijednost)
{
    while(pocetak != kraj)
    {
        if (*pocetak == vrijednost)
            return true;
        pocetak++;
    }
    return false;
}

template <typename itertip>
void Izbaci(itertip pocetak, itertip &kraj)
{
    itertip novi = ++pocetak;
    pocetak--;
    while (novi!=kraj)
    {
        *pocetak = *novi;
        pocetak++;
        novi++;
    }
    kraj--;
}

template <typename itertip>
auto Izdvajanje(itertip pocetak, itertip &kraj, int &brojac) -> typename remove_reference<decltype(*pocetak)>::type*
{
    itertip rezervni = pocetak;
    typedef typename remove_reference<decltype(*pocetak)>::type cjelobrojniTip;
    
    brojac = 0;
    
    //Prebrojojavanje slobodnih od kvadrata
    while (pocetak!=kraj)
    {
        if (!ImaKvadrata(*pocetak) && !PonavljaSe(rezervni, pocetak, *pocetak))
            brojac++;
        pocetak++;
    }
    pocetak = rezervni; //Restart 'pokazivaca'
    
    //Din alokacija niza
    if (brojac == 0)//Prazan niz, nema potrebe za alokacijom
        return nullptr;
    cjelobrojniTip* slobodniOdKvadrata = nullptr;
    try
    {
        slobodniOdKvadrata = new cjelobrojniTip[brojac]{};
    }
    catch(...)
    {
        delete[] slobodniOdKvadrata;
        throw range_error ("Nedovoljno memorije!");
    }
    auto slobodniOdKvadrataUnos = slobodniOdKvadrata;
    while(pocetak!=kraj)
    {
        if (!ImaKvadrata(*pocetak) && !PonavljaSe(rezervni, pocetak, *pocetak))
        {
            *slobodniOdKvadrataUnos = *pocetak;
            slobodniOdKvadrataUnos++;   
        }
        pocetak++;
    }
    
    //Izbacivanje brojeva s istim zbirom prostih faktora
    pocetak = rezervni;
    bool izbacivanje = false;
    while(pocetak != kraj)
    {
        itertip poredbeni = pocetak+1;
        int sumaPrvog = DajSumuProstih(*pocetak);
        while (poredbeni != kraj)
        {
            if(DajSumuProstih(*poredbeni) == sumaPrvog)
            {
                Izbaci(poredbeni, kraj);
                poredbeni--;
                izbacivanje = true;
            }
            poredbeni++;
        }
        if (izbacivanje != true)
            pocetak++;
        else
        {
            izbacivanje = false;
            Izbaci(pocetak, kraj);
        }
    }
    return slobodniOdKvadrata;
}

template <typename itertip>
int razlikaPokazivaca(itertip pocetak, itertip kraj)
{
    int brojac = 0;
    while (pocetak!=kraj)
    {
        brojac++;
        pocetak++;
    }
    return brojac;
}

template <typename cjelobrojniTip>
int dajProduktCifara(cjelobrojniTip broj)
{
    if (broj == 0)
        return 0;
        
    int produkt = 1;
    while (broj != 0)
    {
        produkt*= broj%10;
        broj/=10;
    }
    return produkt;
}

int main ()
{
	vector<int> kontejner;
	int unos = 0;
	cout << "Unesite brojeve: ";
	while(true)
	{
	    cin >> unos;
	    if (unos==-1) break;
	    kontejner.push_back(unos);
	}
	
	try
	{
	    int duzina = kontejner.size();
	    auto kraj = kontejner.end();
    	auto izdvojeniBrojevi = Izdvajanje(kontejner.begin(), kraj, duzina);
    	
    	//ISPIS IDVOJENIH BROJEVA
    	cout <<"Izdvojeni brojevi: ";
    	auto zaIspisa = izdvojeniBrojevi;
        for (int i = 0; i < duzina; i++)
        {
            if (i == duzina-1)
            {
                cout << *zaIspisa;
                break;
            }
            else cout << *zaIspisa << ", ";
            zaIspisa++;
        }
        cout << endl;
	    delete[] izdvojeniBrojevi;
	    izdvojeniBrojevi = nullptr;
	    
	    //ISPIS KONTEJNERA
	    cout << "Modificirani kontejner (prije sortiranja): ";
	    auto zaIspisaKontejnera = kontejner.begin();
	    int novaVelicina = razlikaPokazivaca(zaIspisaKontejnera, kraj);
	    for (int i = 0; i < novaVelicina; i++)
	    {
	        if (i == novaVelicina-1)
	            cout << *zaIspisaKontejnera;
	        else
	            cout << *zaIspisaKontejnera << ", ";
	       zaIspisaKontejnera++;
	    }
	    cout << endl;
	    
	    //ISPIS SORTIRANOG KONTEJNERA
    	sort(kontejner.begin(), kraj, [](int prvi, int drugi){if (dajProduktCifara(prvi) == dajProduktCifara(drugi)) return prvi<drugi; else return dajProduktCifara(prvi) < dajProduktCifara(drugi);});
    	zaIspisaKontejnera = kontejner.begin();
    	cout << "Modificirani kontejner (nakon sortiranja): ";
    	for (int i = 0; i < novaVelicina; i++)
	    {
	        if (i == novaVelicina-1)
	            cout << *zaIspisaKontejnera;
	        else
	            cout << *zaIspisaKontejnera << ", ";
	       zaIspisaKontejnera++;
	    }
	    cout << endl;
	}
	catch(range_error izuzetak)
	{
	    cout << izuzetak.what() << endl;
	}
	
	return 0;
}