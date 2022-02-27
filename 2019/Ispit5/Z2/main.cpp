#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

enum class VrstaMatrice {Grbava, Nekvadratna, KvadratnaNeortogonalna, Ortogonalna};

vector<vector<double>> Transponuj(vector<vector<double>> matrica)
{
    vector<vector<double>> transponovana(matrica.size());
    for (auto &red : transponovana)
    {
        red.resize(matrica.at(0).size());
    }
    
    for (int i = 0; i < matrica.size(); i++)
    {
        transponovana.at(i).resize(matrica.at(0).size());
        for (int j = 0; j < matrica.at(0).size(); j++)
        {
            transponovana.at(j).at(i) = matrica.at(i).at(j);
        }
        
    }
    return transponovana;
}

vector<vector<double>> ProizvodMatrica(vector<vector<double>> a, vector<vector<double>> b)
{
    vector<vector<double>> proizvod (a.size());
    for (auto &x : proizvod)
    {
        x.resize(a.size());
        for (auto &r : x)
            r = 0;
    }
        
    
    
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.at(0).size(); j++)
        {
            for (int k = 0; k < a.at(0).size(); k++)
            {
                proizvod.at(i).at(j) += a.at(i).at(k) + b.at(k).at(j);
            }
        }
    }
    
    return proizvod;
}


VrstaMatrice OdrediVrstuMatrice (vector<vector<double>> matrica)
{
    //Da li je prazna
    if (matrica.size() == 0)
        return VrstaMatrice::Ortogonalna;
    
    //Provjera da li je matrica grbava
    int brElemenata = matrica.at(0).size();
    for (auto red:matrica)
    {
        if (red.size() != brElemenata)
            return VrstaMatrice::Grbava;
    }
    
    //Provjera da li je matrica kvadratna
    int brRedova = matrica.size();
    for (auto red : matrica)
    {
        if (red.size() != brRedova)
            return VrstaMatrice::Nekvadratna;
    }
    
    //Mnozenje matrica
    bool ortagonalna = true;
    auto rezultantnaMatrica = ProizvodMatrica(Transponuj(matrica), matrica);
    for (int i = 0; i < rezultantnaMatrica.size(); i++)
    {
        for (int j = 0; j < rezultantnaMatrica.at(0).size(); j++)
        {
            if (i == j)
            {
                if (fabs(rezultantnaMatrica.at(i).at(j)-1) < 0.00001)
                    ortagonalna = false;
            }
            else
            {
                if (fabs(rezultantnaMatrica.at(i).at(j)-1) < 0.00001)
                    ortagonalna = false;
            }
        }
    }
    
    if (ortagonalna)
        return VrstaMatrice::Ortogonalna;
    
    return VrstaMatrice::KvadratnaNeortogonalna;
    
}

int main ()
{
	cout << "Unesite dimenziju kvadratne matrice: ";
	int n;
	cin >> n;
	vector<vector<double>> matrica(n);
	
	cout << "Unesite elemente matrice: ";
	for (auto &red : matrica)
	{
	    red.resize(n);
	    for (auto &x : red)
	        cin >> x;
	}
	
	if (OdrediVrstuMatrice(matrica) == VrstaMatrice::Ortogonalna)
	    cout << "Matrica je ortogonalna";
	else cout << "Matrica nije ortogonalna";
	
}