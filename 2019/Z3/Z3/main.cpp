#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica 
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
    char ime_matrice;
 };

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> &mat) 
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
 }

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona, char ime = 0, int vrijednost = 0) 
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.ime_matrice = ime;
    mat.elementi = new TipElemenata*[br_redova]{};
    try {
    for(int i = 0; i < br_redova; i++)
    mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) {
    UnistiMatricu(mat);
    throw;
    }
    
    for (int i = 0; i < mat.br_redova; i++)
    {
        for (int j = 0; j < mat.br_kolona; j++)
        {
            mat.elementi[i][j] = vrijednost;
        }
    }
    
    return mat;
 }

template <typename TipElemenata>
void UnesiMatricu(Matrica<TipElemenata> &mat) 
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) 
        {
            std::cout << mat.ime_matrice
            << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 2, bool treba_brisati = false) 
{
    for(int i = 0; i < mat.br_redova; i++) 
    {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    
    if (treba_brisati)
    {
        Matrica<TipElemenata> brisi = mat; //Zeza nas const
        UnistiMatricu<TipElemenata>(brisi);
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_kolona != m2.br_redova)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for (int i =  0; i < m1.br_redova; i++)
    {
        for (int j = 0; j < m2.br_kolona; j++)
        {
            m3.elementi[i][j] = 0;
            for (int k = 0; k < m2.br_redova; k++)
            {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename TipElemenata>
void PomnoziMatricuSkalarom(Matrica<TipElemenata> &matrica, double skalar)
{
    for (int i = 0; i < matrica.br_redova; i++)
    {
        for (int j = 0; j < matrica.br_kolona; j++)
        {
            matrica.elementi[i][j]*=skalar;
        }
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> DubokaKopija(const Matrica<TipElemenata> &matrica)
{
    Matrica<TipElemenata> losaKopija = StvoriMatricu<TipElemenata>(matrica.br_redova, matrica.br_kolona);
    for (int i = 0; i < matrica.br_redova; i++)
    {
        for (int j = 0; j < matrica.br_kolona; j++)
        {
            losaKopija.elementi[i][j] = matrica.elementi[i][j];
        }
    }
    return losaKopija;
}

template <typename TipElemenata>
Matrica <TipElemenata> MatricniHarmonijskiPolinom (const Matrica <TipElemenata> &mat, int stepen)
{
    if (mat.br_kolona != mat.br_redova)
        throw std::domain_error("Matrica nije kvadratna");
    if (stepen <= 0)
        throw std::domain_error("Pogresan parametar n");
    
    Matrica<TipElemenata> matrica = StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona); //Pocinjemo s jedinicnom matricom
    try
    {
        for (int i = 1; i <= stepen; i++)
        {
            Matrica<TipElemenata> nova = DubokaKopija(mat);
            for (int j = 1; j < i; j++)
            {
                Matrica<TipElemenata> brisalica = nova;
                nova = ProduktMatrica(nova, mat);
                UnistiMatricu(brisalica);
            }
            PomnoziMatricuSkalarom(nova, double(1)/i);
            Matrica<TipElemenata> brisalica = matrica;
            matrica = ZbirMatrica(matrica, nova);
            UnistiMatricu(brisalica);
            UnistiMatricu(nova);
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout << izuzetak.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Memorijska greska!" << std::endl;
    }
    
    return matrica;
}

int main()
{
    // std::cout << "Unesite dimenziju kvadratne matrice: ";
    // int n;
    // std::cin>>n;
    // auto matrica = StvoriMatricu<double>(n,n);
    
    // std::cout << "Unesite elemente matrice A: " << std::endl;
    // UnesiMatricu(matrica);
    // std::cout << "Unesite stepen matrice: ";
    // int stepen;
    // std::cin >> stepen;
    
    // auto nova = MatricniHarmonijskiPolinom(matrica, stepen);
    
    // IspisiMatricu(nova, 10);
    // UnistiMatricu(nova);
    // UnistiMatricu(matrica);
    
    return 0;
}