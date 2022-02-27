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
template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica()
	{
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	friend std::istream& operator >> (std::istream &tok, Matrica <TipEl> &m)
	{
		for (int i=0; i<m.br_redova; i++)
			for (int j=0; j<m.br_kolona; j++) {
				std::cout << m.ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
				tok >> m.elementi[i][j];
			}
		return tok;
	}
	friend std::ostream& operator << (std::ostream &tok, const Matrica <TipEl> &m)
	{
		int sirina_ispisa=tok.width();
		for (int i=0; i<m.br_redova; i++) {
			for (int j=0; j<m.br_kolona; j++)
				std::cout << std::setw(sirina_ispisa) << m.elementi[i][j];
			std::cout << std::endl;
		}
		return tok;
	}
	operator std::string() const;
	TipEl* operator[](int n) const
	{
		return elementi[n];
	}
	TipEl* &operator[](int n)
	{
		return elementi[n];
	}
	TipEl& operator() (int i,int j)
	{
		if (i<=0 || i>br_redova || j<=0 || j>br_kolona) throw std::domain_error ("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	TipEl& operator() (int i,int j) const
	{
		if (i<=0 || i>br_redova || j<=0 || j>br_kolona) throw std::domain_error ("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m,int n);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(int n,const Matrica<Tip2> &m);
	template <typename Tip2>
	friend Matrica<Tip2> operator +=(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator -=(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *=(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *=(const Matrica<Tip2> &m,int n);
};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi = new TipEl*[br_redova] {};
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	} else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}
template <typename TipEl>
Matrica <TipEl> operator+(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
	if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);
	for (int i=0; i<m1.br_redova; i++)
		for (int j=0; j<m1.br_kolona; j++)
			m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
	return m3;
}
template <typename TipEl>
Matrica <TipEl>& operator +=(Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
	if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	for (int i=0; i<m1.br_redova; i++)
		for (int j=0; j<m1.br_kolona; j++)
			m1.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
	return m1;
}
template <typename TipEl>
Matrica <TipEl> operator-(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
	if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);
	for (int i=0; i<m1.br_redova; i++)
		for (int j=0; j<m1.br_kolona; j++)
			m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
	return m3;
}
template <typename TipEl>
Matrica <TipEl>& operator -=(Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
	if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	for (int i=0; i<m1.br_redova; i++)
		for (int j=0; j<m1.br_kolona; j++)
			m1.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
	return m1;
}
template <typename TipEl>
Matrica <TipEl> operator*(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
	if (m1.br_redova!=m2.br_kolona) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);
	for (int i=0; i<m1.br_redova; i++)
		for (int j=0; j<m1.br_kolona; j++) {
			TipEl suma=0;
			for (int k=0; k<m2.br_redova; k++) suma+=m1[i][k]*m2[k][j];
			m3[i][j]=suma;
		}
	return m3;
}
template <typename TipEl>
Matrica <TipEl> operator*(const Matrica<TipEl> &m,int n)
{
	Matrica<TipEl> m3(m.br_redova,m.br_kolona);
	for (int i=0; i<m.br_redova; i++) {
		for (int j=0; j<m.br_kolona; j++) {
			m3.elementi[i][j]=m.elementi[i][j]*n;
		}
	}
	return m3;
}
template <typename TipEl>
Matrica <TipEl> operator *(int n,const Matrica<TipEl> &m)
{
	return m*n;
}
template <typename TipEl>
Matrica <TipEl>& operator *=(Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
	if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);
	for (int i=0; i<m1.br_redova; i++)
		for (int j=0; j<m1.br_kolona; j++) {
			TipEl suma=0;
			for (int k=0; k<m2.br_redova; k++) suma+=m1[i][k]*m2[k][j];
			m3[i][j]=suma;
		}
	return m1;
}
template <typename TipEl>
Matrica <TipEl>& operator *=(Matrica<TipEl> &m,int n)
{
	for (int i=0; i<m.br_redova; i++) {
		for (int j=0; j<m.br_kolona; j++) {
			m.elementi[i][j]=m.elementi[i][j]*n;
		}
	}
	return m;
}
template <typename TipEl>
Matrica <TipEl>::operator std::string() const
{
	std::string s("{");
	for (int i=0; i<br_redova; i++) {
		s+="{";
		for (int j=0; j<br_kolona; j++) {
			s+=std::to_string(int(elementi[i][j]));
			if (j!=br_kolona-1) s+=",";
		}
		if (i!=br_redova-1) s+="},";
		else s+="}";
	}
	s+="}";
	return s;
}
int main()
{
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	try {
		Matrica<double> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		std::cin >> a;
		std::cout << "Unesi matricu B:\n";
		std::cin >> b;
		std::cout << "Zbir ove dvije matrice je:\n";
		std::cout << std::setw(7) << a+b;
	} catch(...) {
		std::cout << "Nema dovoljno memorije!\n";
	}
	return 0;
}
