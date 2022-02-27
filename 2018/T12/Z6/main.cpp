/*
    TP 16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>

template <typename TipEl>
class Matrica
{
	int br_redova,br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova,int br_kolona);
	static void DeAlocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
	void TestIndeksa(int index1,int index2) const
	{
		if(index1<1 || index2<1 || index1>br_redova || index2 >br_kolona)
			throw std::range_error("Neispravan indeks");
	}
public:
	Matrica(int br_redova,int br_kolona,char ime=0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica()
	{
		DeAlocirajMemoriju(elementi,br_redova);
	}
	Matrica &operator=(const Matrica &m);
	Matrica &operator=(Matrica &&m);
	void Unesi();
	void Ispisi(int sirina_ispisa) const;

	friend Matrica operator +(const Matrica &m1,const Matrica &m2)
	{
		if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++)
				m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
		return m3;
	}
	friend std::ostream &operator << (std::ostream &tok,const Matrica &m)
	{
		int kojije(tok.width());
		for(int i=0; i<m.br_redova; i++) {
			for(int j=0; j<m.br_kolona; j++)
				std::cout << std::setw(kojije) << m.elementi[i][j];
			std::cout << std::endl;
		}
		return tok;
	}
	friend std::istream &operator >> (std::istream &tok,const Matrica &m)
	{
		int kojaje(tok.width());
		for(int i=0; i<m.br_redova; i++)
			for (int j=0; j<m.br_kolona; j++) {
				std::cout << m.ime_matrice << "(" <<i+1 <<"," << j+1 << ") = ";
				tok>>m.elementi[i][j];
			}
		return tok;
	}
	TipEl* operator [](int indeks) const
	{
		return elementi[indeks];
	}
	TipEl* &operator [](int indeks)
	{
		return elementi[indeks];
	}
	friend Matrica operator *(const Matrica &m1,const Matrica &m2)
	{
		if(m1.br_redova!=m2.br_kolona)
			throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica<TipEl> m3(m1.br_redova,m2.br_kolona);
		for(int i=0; i<m1.br_redova; i++) {
			int k=0;
			for(int j=0; j<m3.br_kolona; j++) {
				double suma=0;
				for(int l=0; l<m2.br_redova; l++) {
					suma+=m1.elementi[i][l]*m2.elementi[l][j];
					l++;
				}
				k++;
				m3.elementi[i][j]=suma;
			}
		}
		return m3;
	}
	TipEl &operator ()(int a,int b)
	{
		TestIndeksa(a,b);
		return elementi[a-1][b-1];
	}
	TipEl operator ()(int a,int b) const
	{
		TestIndeksa(a,b);
		return elementi[a-1][b-1];
	}
	friend Matrica operator -(const Matrica &m1,const Matrica &m2)
	{
		if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++)
				m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
		return m3;
	}
	friend Matrica operator *(double x,const Matrica &m2)
	{
		Matrica<TipEl> m3(m2.br_redova,m2.br_kolona);
		for(int i=0; i<m2.br_redova; i++)
			for(int j=0; j<m2.br_kolona; j++)
				m3.elementi[i][j]=x*m2.elementi[i][j];
		return m3;
	}
	friend Matrica operator *(const Matrica &m2,double x)
	{
		Matrica <TipEl> m3(m2.br_redova,m2.br_kolona);
		for(int i=0; i<m2.br_redova; i++)
			for(int j=0; j<m2.br_kolona; j++)
				m3.elementi[i][j]=x*m2.elementi[i][j];
		return m3;
	}
	Matrica operator *=(const Matrica &m2)
	{
		if(m2.br_redova!=m2.br_kolona)
			throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica<TipEl> m3(br_redova,m2.br_kolona);
		for(int i=0; i<br_redova; i++) {
			int k=0;
			for(int j=0; j<m2.br_kolona; j++) {
				double suma=0;
				for(int l=0; l<m2.br_redova; l++) {
					suma+=elementi[i][l]*m2.elementi[l][j];
					l++;
				}
				k++;
				m3.elementi[i][j]=suma;
			}
		}
		*this=m3;
		return *this;
	}
}
int main ()
{
	return 0;
}
