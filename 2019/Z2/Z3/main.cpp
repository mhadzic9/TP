#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

using namespace std;

long long int sterling(long long int, long long int);

long long int sterlingNovi(long long int i, long long int j)
{
    if (i == 0 && j==0)
        return 1;
    else if (i==0)
        return 0;
    else if (i>j)
        return 0;
    else return sterling(i, j);
}

long long int sterling(long long int i, long long int j)
{
    if (i == 0 && j==0)
        return 1;
    else if (i==0)
        return 0;
    else if (i>j)
        return 0;
    else return sterlingNovi(i-1, j-1)+i*sterlingNovi(i,j-1);
}

long long int** StirlingoviBrojeviF(int velicina)
{
    if (velicina < 0)
        throw domain_error("Parametar ne smije biti negativan");
    long long int** brojevi = nullptr;
    
    try
    {
        brojevi = new long long int* [velicina+1];
        int ucitano = 0;
        try
        {
            for (int i = 0; i < velicina+1; i++)
            {
                brojevi[i] = new long long int[i+1];
                ucitano++;
            }
        }
        catch(bad_alloc izuzetak)
        {
            for (int i = 0; i < ucitano; i++)
            {
                delete[] brojevi[i];
            }
            throw;
        }
    }
    catch (bad_alloc izuzetak)
    {
        delete[] brojevi;
        brojevi = nullptr;
        throw domain_error("Parametar prevelik za raspolozivu memoriju");
    }
    
    for (int i = 0; i < velicina+1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            brojevi[i][j] = sterling(j, i);
        }
    }
    
    return brojevi;
}

long long int** StirlingoviBrojeviK(int velicina)
{
    if (velicina < 0)
        throw domain_error("Parametar ne smije biti negativan");
    
    long long int** brojevi = nullptr;
    
    try
    {
        brojevi = new long long int* [velicina+1]{};
        try
        {
            brojevi[0] = new long long int[(velicina+1)*(velicina+2)/2];
            for (int i = 1; i < velicina+1; i++)
            {
                brojevi[i] = brojevi[i-1]+i;
            }
        }
        catch(bad_alloc izuzetak)
        {
            delete[] brojevi[0];
            brojevi[0] = nullptr;
            throw;
        }
    }
    catch(bad_alloc izuzetak)
    {
        delete[] brojevi;
        brojevi = nullptr;
        throw domain_error("Parametar prevelik za raspolozivu memoriju");
    }
    
    for (int i = 0; i < velicina+1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            brojevi[i][j] = sterling(j, i);
        }
    }
    
    return brojevi;
}

int NajsiriBroj (long long int** brojevi, int velicina)
{
    int najsiri = 0;
    for (int i = 0; i < velicina+1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            if (to_string(brojevi[i][j]).length() > najsiri)
                najsiri = to_string(brojevi[i][j]).length();
        }
    }
    return ++najsiri;
}

int main ()
{
	try
	{
	    int n;
	    cout << "Unesite broj n: " ;
	    cin >> n;
	    auto brojevi = StirlingoviBrojeviF(n);
	    int najsiri = NajsiriBroj(brojevi, n);
	    cout << endl;
	    cout << "Stirlingovi brojevi - fragmentirana alokacija: " << endl;
	    for (int i = 0; i < n+1; i++)
	    {
	        for (int j = 0; j <= i; j++)
	        {
	            cout <<setw(najsiri) << brojevi[i][j];
	        }
	        cout << endl;
	        delete[] brojevi[i];
	        brojevi[i] = nullptr;
	    }
	    delete[] brojevi;
	    brojevi = nullptr;
	    
	    brojevi = StirlingoviBrojeviK(n);
	    cout << endl;
	    cout << "Stirlingovi brojevi - kontinualna alokacija: " << endl;
	    
	    for (int i = 0; i < n+1; i++)
	    {
	        for (int j = 0; j <= i; j++)
	        {
	            cout <<setw(najsiri)<< brojevi[i][j];
	        }
	        cout << endl;
	    }
	    delete[] brojevi[0];
	    delete[] brojevi;
	}
	catch (domain_error izuzetak)
	{
	    cout << "Izuzetak: " << izuzetak.what() << "!" << endl;
	}
	return 0;
}