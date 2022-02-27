//TP 2018/2019: Ispit 5, Zadatak 5
#include <iostream>

using namespace std;

void KreirajPascalovTrougao (int **&A, int n)
{
    if (n <= 0)
        throw domain_error ("Pogresan broj redova");
    
    try
    {
        A = new int*[n]{};
        int broj_el = 0;
        try
        {
            for (int i = 1; i <= n; i++)
            {
                broj_el+=i;
            }
            A[0] = new int[broj_el];
            for (int i = 1; i < n; i++)
                A[i] = A[i-1]+i;
        }
        catch(...)
        {
            delete[] A[0];

            throw;
        }
    }
    catch(...)
    {
        delete[] A;
        throw range_error("Kreiranje nije uspjelo");
    }
    
    int koeficijent = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                koeficijent = 1;
            else
            {
                koeficijent = koeficijent*(i-j+1)/j;
            }
            A[i][j] = koeficijent;
        }
    }
    
}


int main ()
{
	int n;
	int** A = nullptr;
	
	cout << "Broj redova: ";
	cin >> n;
	try
	{
	    KreirajPascalovTrougao(A, n);
	    for (int i = 0; i < n; i++)
    	{
    	    for (int j = 0; j <= i; j++)
    	    {
    	        cout << A[i][j] << " ";
    	    }
    	    cout << endl;
    	}
    	
	    delete[] A[0];
    	delete[] A;
	}
	catch(domain_error izuzetak1)
	{
	    cout << "Problem: " << izuzetak1.what() << "!";
	}
	catch(range_error izuzetak2)
	{
	    cout << "Problem: " << izuzetak2.what() << "!";
	}
	
	
}