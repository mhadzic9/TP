#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

vector<vector<vector<char>>> KreirajMatrice(int m, int n)
{
    //Rukovanje nedozvoljenim vrijednostima parametara funkcije
    if (m <= 0 || n <= 0)
        throw domain_error("Dimenzije matrica moraju biti pozitivne");
    else if (m >=100 || n >= 100)
        throw domain_error("Prevelike dimenzije");
    else if (m!=n)
        throw domain_error("Matrice moraju biti kvadratne");
    
    //Kreiranje vektora vektora vektora karaktera
    vector<vector<vector<char>>> table(2);
    vector<vector<char>> matrica(m);
    for (auto &vektor:matrica)
    {
        vektor.resize(n);
        fill(vektor.begin(), vektor.end(), '-');
    }
    table.at(0) = matrica;
    table.at(1) = matrica;
    
    return table;
}

void Nacrtaj(const std::vector<std::vector<std::vector<char>>> &table, int n)
{
    for (auto vektor : table.at(n))
    {
        for (auto c : vektor)
        {
            if (c != 'X' && c!='x' && c!='o' && c!='O' && c!='-')
                cout << 'R' << ' ';
            else
                cout << c << ' ';
        }
        cout << endl;
    }
}

int DaLiJePotopljen(const vector<vector<char>> &tabla, char roboti)
{
    int brojac = 0;
    for (auto vektor : tabla)
    {
        for (auto robot : vektor)
        {
            if (robot == roboti)
                brojac++;
        }
    }
    return brojac;
}

bool PogadjanjeRobota(std::vector<std::vector<std::vector<char>>> &table, int p)
{
    
    int osteceni[2] = {0,0};
    int roboti[2] = {p,p};
    // Nacrtaj(table, 0);
    // cout << endl;
    // cout << endl;
    // Nacrtaj(table, 1);
    for (int i = 0; ;i++)
    {
        
        int x, y;
        if(i%2 ==1)
        {
            cout << "Alina unesi koordinate koje zelis gadjati: " << endl;
        }
        else
        {
            cout << "Naida unesi koordinate koje zelis gadjati:" << endl;
        }
        cin >> x >> y;
        if (!cin)
        {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Pogresne koordinate gdje zelite gadjati" << endl;
                continue;
        }
        
        if (x == -1 && y == -1)//Prekid igre
        {
            cout << "Naida ima " << p-roboti[0] << " unistenih, " << osteceni[0] << " ostecenih i " << roboti[0]-osteceni[0] <<" citavih robota." << endl;
            cout << "Alina ima " << p-roboti[1] << " unistenih, " << osteceni[1] << " ostecenih i " << roboti[1]-osteceni[1] <<" citavih robota." << endl;
            
            return false;
        }
            
        else if (x ==-2 && y ==-2)//Poziv crtanja
        {
            Nacrtaj(table, i%2);
            i--;
            continue;
        }
        else if (x < 0 || y < 0 || x >= table.at(0).at(0).size() || y >= table.at(0).size())//Neispravan unos
        {
            cout << "Pogresne koordinate gdje zelite gadjati" << endl;
            continue;
        }
        if (table.at((i+1)%2).at(y).at(x) == 'X' || table.at((i+1)%2).at(y).at(x) == 'O') //Vec gadjanjo
        {
            cout << "Vec ste gadjali ovo polje" << endl;
            continue;
        }
        else if (table.at((i+1)%2).at(y).at(x) == '-') //Promasaj
        {
            table.at((i+1)%2).at(y).at(x) = 'O';
            cout << "Promasaj"<<endl;
        }
        else
        {
            char brod = table.at((i+1)%2).at(y).at(x);
            table.at((i+1)%2).at(y).at(x) = 'X';
            int ostalo = DaLiJePotopljen(table.at((i+1)%2), brod);
            if (ostalo == 0)
            {
                cout << "Unisteno" << endl;
                roboti[(i+1)%2]--;
                if (brod != '1') osteceni[(i+1)%2]--;
                if (roboti[(i+1)%2] == 0)
                {
                    if (i%2 ==0)
                    {
                        cout << "Naida je pobijedila. " << "Naida ima " << p-roboti[0] << " unistenih, " << osteceni[0] << " ostecenih i " << roboti[0]-osteceni[0] <<" citavih robota." << endl;
                        return true;
                    }
                    if (i%2 ==1)
                    {
                        cout << "Alina je pobijedila. " << "Alina ima " << p-roboti[1] << " unistenih, " << osteceni[1] << " ostecenih i " << roboti[1]-osteceni[1] <<" citavih robota." << endl;
                        return true;
                    }
                }
                
            }
            else
            {
                if (ostalo != int(brod-'0'))
                    osteceni[(i+1)%2]+=1;
                cout << "Pogodak" << endl;
            }
            
        }
        // Nacrtaj(table, (i+1)%2);
    }
    return false;
}

bool daLiJeGrbava(const vector<vector<char>> &tabla)
{
    int prvaVelicina = tabla.at(0).size();
    for (auto vektor:tabla)
    {
        if (vektor.size() != prvaVelicina)
            return true;
    }
    return false;
}
bool daLiNIJEkvadratna(const vector<vector<char>> &tabla)
{
    
    int prvaVelicina = tabla.at(0).size();
    if (tabla.size() != prvaVelicina)
        return true;
    for (auto vektor : tabla)
    {
        if (vektor.size() != prvaVelicina)
            return true;
    }
    return false;
}

bool ProvjeriPrekid (const vector<vector<char>> &matrica, int y1, int x1, int y2, int x2)
{
    if (x1 == x2)
    {
        if (y1 >= y2)
        {
            for (int i = y2; i <= y1; i++)
            {
                if (matrica.at(x1).at(i)!='-')
                    return true;
            }
        }
        else
        {
            for (int i = y1; i <= y2; i++)
            {
                if(matrica.at(x1).at(i) != '-')
                    return true;
            }
        }
    }
    else
    {
        if (x1 >= x2)
        {
            for (int i = x2; i <= x1; i++)
            {
                if(matrica.at(i).at(y1) != '-')
                    return true;
            }
        }
        else
        {
            for (int i = x1; i <= x2; i++)
            {
                if(matrica.at(i).at(y1) != '-')
                    return true;
            }
        }
    }
    return false;
}

bool ImaLiMjesta(const vector<vector<char>> &matrica, int velicina)
{
    // vector<vector<vector<char>>> novi;
    // novi.push_back(matrica);
    // Nacrtaj(novi, 0);
    int brojac = 0;
    for (int i = 0; i < matrica.size(); i++)
    {
        brojac = 0;
        for (int j = 0; j < matrica.at(i).size();j++)
        {
            if (matrica.at(i).at(j) == '-')
            {
                 brojac++;
                 if(brojac>=velicina)
                    return true;
            }
               
            else
            {
                if (brojac >= velicina)
                    return true;
                else brojac = 0;
            }
        }
    }
    brojac = 0;
    for (int j = 0; j < matrica.at(0).size(); j++)
    {
        brojac = 0;
        for(int i = 0; i < matrica.size(); i++)
        {
            if (matrica.at(i).at(j) == '-')
                brojac++;
            else
            {
                if (brojac >= velicina)
                    return true;
                else brojac = 0;
            }
        }
    }
    return false;
}


void Ukucaj (vector<vector<char>> &matrica, int y1, int x1, int y2, int x2, char karakter)
{
    if (x1 == x2)
    {
        if (y1 >= y2)
        {
            for (int i = y2; i <= y1; i++)
            {
                matrica.at(x1).at(i) = karakter;
            }
        }
        else
        {
            for (int i = y1; i <= y2; i++)
            {
                matrica.at(x1).at(i) = karakter;
            }
        }
    }
    else
    {
        if (x1 >= x2)
        {
            for (int i = x2; i <= x1; i++)
            {
                matrica.at(i).at(y1) = karakter;
            }
        }
        else
        {
            for (int i = x1; i <= x2; i++)
            {
                matrica.at(i).at(y1) = karakter;
            }
        }
    }
}

void Unos(vector<vector<vector<char>>> &table, int brojRobota)
{
    //Rukovanje nedozvoljenim vrijednostima parametara funkcije
    if (table.size() ==0)
        throw domain_error("Matrica ne postoji");
    else if (table.size() > 2)
        throw range_error("3D matrica ima pogrešne dimenzije");
    else if (table.at(0).size() == 0 || table.at(1).size() == 0)
        throw domain_error("Neka od dvije matrice je prazna");
    else if (daLiJeGrbava(table.at(0)) || daLiJeGrbava(table.at(1)))
        throw domain_error("Neka matrica je grbava");
    else if (daLiNIJEkvadratna(table.at(0)) || daLiNIJEkvadratna(table.at(0)))
        throw domain_error("Neka od matrica nije kvadratna");
    else if (table.at(0).size() != table.at(1).size() || table.at(0).at(0).size() != table.at(1).at(0).size())
        throw domain_error ("Matrice nemaju iste dimenzije");
    else if (brojRobota <= 0)
        throw domain_error ("Ne mozete igrati bez robota");
    else if (brojRobota > table.at(0).size() && brojRobota > table.at(0).at(0).size())
        throw overflow_error("Zelite igrati sa previse robota");
    else if (brojRobota > 15)
        throw range_error ("Zelite igrati sa previse robota");
    
    
    int x1,y1,x2,y2;
    for(int osoba = 0; osoba < 2; osoba++)
    {
        for (int i = 1; i <= brojRobota; i++)
        {
            if (!ImaLiMjesta(table.at(osoba), i))
                throw overflow_error ("Nemoguce dovrsiti postavljanje robota");
            if (osoba == 0)
                cout << "Naida unesi pocetne i krajnje koordinate " << i <<". robota: " << endl;
            else
                cout << "Alina unesi pocetne i krajnje koordinate " << i <<". robota: " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while(!cin)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Pogresne koordinate gdje zelite smjestiti robota" << endl;
                if (osoba == 0)
                cout << "Naida unesi pocetne i krajnje koordinate " << i <<". robota: " << endl;
                else
                cout << "Alina unesi pocetne i krajnje koordinate " << i <<". robota: " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            
            if (x1<0 || y1<0|| x1 >= table.at(osoba).size() || y1 >= table.at(osoba).at(0).size() || (x2 < 0 && x2!= -2) || (y2 <0 && y2!=-2) || x2 >= table.at(osoba).size() || y2 >= table.at(osoba).at(0).size())
            {
                
                if (x1 == -2 && x2 ==-2 && y1 ==-2 && y2 == -2) //Zatrazeno crtanje
                {
                    Nacrtaj(table, osoba);//Potrebno navesti parametre koje treba
                    i--;
                    continue;
                }
                else
                {
                    i--;
                    cout << "Pogresne koordinate gdje zelite smjestiti robota" << endl;
                    continue;
                }
            }
            
            
            if (x1!=x2 && y1 != y2)// Nisu u istoj liniji
            {
                i--;
                cout << "Pogresne koordinate gdje zelite smjestiti robota" << endl;
                continue;
            }
            if (int(sqrt(pow(x2-x1, 2) + pow(y2-y1, 2))+0.5) != i-1)//Robot nije odgovarajucih dimenzija
            {
                i--;
                cout << "Pogresne koordinate gdje zelite smjestiti robota" << endl;
                continue;
            }
            if (ProvjeriPrekid(table.at(osoba), x1,y1,x2,y2) == true)//Zabranjuje presijecanje robota
            {
                i--;
                cout << "Pogresne koordinate gdje zelite smjestiti robota" << endl;
                continue;
            }
            else Ukucaj(table.at(osoba), x1,y1,x2,y2, '0'+i);
        }
    }
}

int main ()
{
    try
    {
        bool primljenUnos = false;
        int m, n;
    	int brojRobota;
    	vector<vector<vector<char>>>table;
        while (!primljenUnos)
        {
            try
            {
                cout << "Igra je pocela, unesite dimenzije matrica (dva broja): " << endl;
                cin >> m >> n;
            	table = KreirajMatrice(m, n);
            	primljenUnos = true;
            }
            catch(domain_error izuzetak)
            {
                cout << izuzetak.what() << endl;
            }
        }
        primljenUnos = false;
        bool preskociUnos = false;
    	while (!primljenUnos)
        {
            try
            {
                if(!preskociUnos)
                {
                    cout << "Unesite broj robota: " << endl;
            	    cin >> brojRobota;
                }
            	Unos(table, brojRobota);
            	primljenUnos = true;
            }
            catch(domain_error izuzetak)
            {
                cout << izuzetak.what() << endl;
            }
            catch(range_error izuzetak)
            {
                cout << izuzetak.what() << endl;
            }
            catch(overflow_error izuzetak)
            {
                cout << izuzetak.what() << endl;
                if (strcmp (izuzetak.what(), "Nemoguce dovrsiti postavljanje robota")==0)
                {
                    table = KreirajMatrice(m, n);
                    preskociUnos=true;
                }
            }
        }
        
    	cout << "Uspjesno ste unijeli pozicije robota. Sada moze poceti pogadjanje."<<endl;
    	PogadjanjeRobota(table, brojRobota);
    }
    catch(domain_error izuzetak)
    {
        cout << izuzetak.what() << endl;
    }
    catch(range_error izuzetak)
    {
        cout << izuzetak.what() << endl;
    }
    catch(overflow_error izuzetak)
    {
        cout << izuzetak.what() << endl;
    }
    catch(...)
    {
        cout << "Uhvatili smo neki divlji izuzetak" << endl;
    }
	
	return 0;
}