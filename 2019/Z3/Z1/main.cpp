#include <iostream>
#include <cmath> //zbog fabs-a, sinusa i logaritma
#include <functional> //funkcijski omotaci
#include <utility>  //pair
#include <vector>

using namespace std;

function<double(double)> LagrangeovaInterpolacija(vector<pair<double, double>> cvoroviInterpolacije)
{
    //Ne smijemo primiti dvije iste x-koordinate
    if (cvoroviInterpolacije.size())
    {
        for (int i = 0; i < cvoroviInterpolacije.size()-1; i++)
        {
            for (int j = i+1; j < cvoroviInterpolacije.size(); j++)
            {
                if (fabs(cvoroviInterpolacije.at(i).first - cvoroviInterpolacije.at(j).first) < 0.0000001)
                    throw domain_error ("Neispravni cvorovi");
            }
        }
    }
    
    return [cvoroviInterpolacije](double x)
    {
        double suma = 0;
        for (int i = 0; i < cvoroviInterpolacije.size(); i++)
        {
            double proizvod = cvoroviInterpolacije.at(i).second; 
            for (int j = 0; j < cvoroviInterpolacije.size(); j++)
            {
                if (j==i) continue;
                double brojnik = x - cvoroviInterpolacije.at(j).first;
                double nazivnik = cvoroviInterpolacije.at(i).first - cvoroviInterpolacije.at(j).first;
                proizvod *= brojnik/nazivnik;
            }
            suma+=proizvod;
        }
        return suma;
    };
}

function<double(double)> LagrangeovaInterpolacija (double funkcija (double x), double xMin, double xMax, double xDelta)
{
    //Rukovanje izuzetcima
    if (xMin > xMax || xDelta <= 0)
        throw domain_error ("Nekorektni parametri");
    
    vector<pair<double, double>> cvoroviInterpolacije;
    double x = xMin;
    
    while (x <= xMax)
    {
        cvoroviInterpolacije.push_back(make_pair(x, funkcija(x)));
        x+=xDelta;
    }
    return LagrangeovaInterpolacija(cvoroviInterpolacije);
}


int main()
{
    while (true)
    {
        cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int izbor = 0;
        cin >> izbor;
        if (!cin) break;
        
        if (izbor == 1)
        {
            cout << "Unesite broj cvorova: ";
            int n;
            cin >> n;
            if (n<=0)
            {
                cout << "Broj cvorova mora biti pozitivan broj!" << endl;
                break;
            }
                
            vector<pair<double,double>> cvoroviInterpolacije(n);
            cout << "Unesite cvorove kao parove x y: ";
            
            for (auto &cvor : cvoroviInterpolacije)
            {
                cin >> cvor.first;
                cin >> cvor.second;
            }
            
            try
            {
               auto funkcija = LagrangeovaInterpolacija(cvoroviInterpolacije);
                while (true)
                {
                    cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    cin >> argument;
                    if (!cin) return 0;
                    
                    cout << "f(" << argument << ") = " << funkcija(argument);
                    double min = cvoroviInterpolacije.at(0).first, max = cvoroviInterpolacije.at(0).first; 
                    for (auto tacka : cvoroviInterpolacije)
                    {
                        if (tacka.first < min)
                            min = tacka.first;
                        if (tacka.first > max)
                            max = tacka.first;
                    }
                    if (argument < min || argument > max) cout << " [ekstrapolacija]";
                    
                    cout << endl;
                }
            }
            catch(domain_error izuzetak)
            {
                cout << "IZUZETAK: " << izuzetak.what() << "!" << endl;
                return 0;
            }
        }
        
        else if (izbor == 2)
        {
            cout << "Unesite krajeve intervala i korak: ";
            double xMin, xMax, xDelta;
            cin >> xMin >> xMax >> xDelta;
            
            while(true)
            {
                try
                {
                    auto funkcija = LagrangeovaInterpolacija([](double x) {return pow(x,2) + sin(x) + log(x+1);}, xMin, xMax, xDelta);
                    cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    cin >> argument;
                    if (!cin) return 0;
                    
                    cout << "f(" << argument << ") = " << pow(argument,2) + sin(argument) + log(argument+1) << " P(" << argument << ") = ";
                    cout << funkcija(argument);
                    if (argument < xMin || argument > xMax) cout << " [ekstrapolacija]";
                    cout << endl;
                }
                catch(domain_error izuzetak)
                {
                    cout << "IZUZETAK: " << izuzetak.what() << "!" << endl;
                    return 0;
                }
            }
        }
        else
        {
            cout << "Nepoznat slucaj!" << endl;
            break;
        }
    }
    return 0;
}