#include <iostream>
#include <complex>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu (int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<int>(br_kolona));
}

Matrica UnesiMatricu (int br_redova, int br_kolona)
{
	Matrica m=KreirajMatricu(br_redova,br_kolona);
	for (int i=0; i<br_redova; i++)
		for (int j=0; j<br_kolona; j++) {
			std::cin>>m.at(i).at(j);
		}

	return m;
}
std::vector<int> VektorSusjeda(Matrica M,int a,int b)
{
	std::vector<int> V;
	if((a>0) && (b>0) && (a<(M.size()-1)) && (b<(M.at(0).size()-1))) {

		V.push_back(M.at(a-1).at(b));
		V.push_back(M.at(a-1).at(b+1));
		V.push_back(M.at(a).at(b+1));
		V.push_back(M.at(a+1).at(b+1));
		V.push_back(M.at(a+1).at(b));
		V.push_back(M.at(a+1).at(b-1));
		V.push_back(M.at(a).at(b-1));
		V.push_back(M.at(a-1).at(b-1));

	}

	if((a==0) && (b==0)) {
		V.push_back(M.at(a).at(b+1));
		V.push_back(M.at(a+1).at(b+1));
		V.push_back(M.at(a+1).at(b));

	}
	if((a==0) && (b==(M.at(0).size())-1)) {
		V.push_back(M.at(a+1).at(b));
		V.push_back(M.at(a+1).at(b-1));
		V.push_back(M.at(a).at(b-1));

	}
	if((a==(M.size()-1)) && (b==(M.size()-1))) {
		V.push_back(M.at(a-1).at(b));
		V.push_back(M.at(a).at(b-1));
		V.push_back(M.at(a-1).at(b-1));
	}
	if((a==(M.size()-1)) && (b==0)) {
		V.push_back(M.at(a-1).at(b));
		V.push_back(M.at(a-1).at(b+1));
		V.push_back(M.at(a).at(b+1));
	}
	if((a==0) && (b>0) && (b<(M.at(0).size()-1))) {
		V.push_back(M.at(a).at(b+1));
		V.push_back(M.at(a+1).at(b+1));
		V.push_back(M.at(a+1).at(b));
		V.push_back(M.at(a+1).at(b-1));
		V.push_back(M.at(a).at(b-1));
	}
	if((a>0) && (a<(M.size()-1)) && (b==(M.at(0).size()-1))) {
		V.push_back(M.at(a-1).at(b));
		V.push_back(M.at(a+1).at(b));
		V.push_back(M.at(a+1).at(b-1));
		V.push_back(M.at(a).at(b-1));
		V.push_back(M.at(a-1).at(b-1));
	}
	if(a==(M.size()-1) && (b>0) && (b<(M.at(0).size()-1))) {
		V.push_back(M.at(a-1).at(b));
		V.push_back(M.at(a-1).at(b+1));
		V.push_back(M.at(a).at(b+1));
		V.push_back(M.at(a).at(b-1));
		V.push_back(M.at(a-1).at(b-1));
	}
	if((a>0) && (a<(M.size()-1)) && (b==0)) {
		V.push_back(M.at(a-1).at(b));
		V.push_back(M.at(a-1).at(b+1));
		V.push_back(M.at(a).at(b+1));
		V.push_back(M.at(a+1).at(b+1));
		V.push_back(M.at(a+1).at(b));
	}
	return V;

}
int NajveciClan(std::vector<int> V)
{
	int maxclan(V[0]);
	for(int i=0; i<=(V.size()-1); i++) {
		if(V.at(i)>maxclan)
			maxclan=V.at(i);
	}
	return maxclan;
}
int IndexNajvecegClana(std::vector<int> V)
{
	int j;
	int A(NajveciClan(V));
	for(j=0; j<V.size()-1; j++) {
		if (V.at(j)==A) break;
	}
	return j;
}

std::complex<int> VrhMatrice(Matrica M,int a,int b)
{
	int b1(b);
	if (M.size()==1) {
		std::complex<int> z (0,IndexNajvecegClana(M.at(0)));
		return z;
	}
	if(M.size()>1) {
		int h(0);
		for(int i=0; i<M.size(); i++) {
			if (M.at(i).size()!=M.at(0).size()) {
				h=1;
				break;
			}
		}
		if(h) {
			throw std::domain_error("Nekorektna matrica");
		} else if (h==0) {
			if((a>=M.size()) || (b>=M.at(0).size()) || (a<0) || (b<0)) throw std::range_error ("Nekorektna pocetna pozicija");
			while(M.at(a).at(b)<NajveciClan(VektorSusjeda(M,a,b))) {
				if ((a>0) && (b>0) && (a<(M.size()-1)) && (b<M.at(0).size()-1)) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						a=a-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a-1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==3) {
						a=a+1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==4) {
						a=a+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==5) {
						a=a+1;
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==6) {
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==7) {
						a=a-1;
						b=b-1;
						continue;
					}
				}
				if((a==0) && (b==0)) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a+1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						a=a+1;
						continue;
					}
				}
				if((a==0) && (b==M[0].size()-1)) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						a=a+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a+1;
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						b=b-1;
						continue;
					}
				}
				if ((a==M.size()-1) && (b==(M[0].size()-1))) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						a=a-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						a=a-1;
						b=b-1;
						continue;
					}
				}
				if ((a==M.size()-1) && (b==0)) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						a=a-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a-1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						b=b+1;
						continue;
					}
				}
				if ((a==0) && (b>0) && (b<M[0].size())) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a+1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						a=a+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==3) {
						a=a+1;
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==4) {
						b=b-1;
						continue;
					}
				}
				if ((a>0) && (a<M.size()-1) && (b==M.at(0).size()-1)) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						a=a-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						a=a+1;
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==3) {
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==4) {
						a=a-1;
						b=b-1;
						continue;
					}
				}
				if((a==M.size()-1) && (b>0) && (b<M[0].size()-1)) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						a=a-1;
						continue;

					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a-1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==3) {
						b=b-1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==4) {
						a=a-1;
						b=b-1;
						continue;
					}
				}
				if((a>0) && (a<M.size()-1) && (b==0)) {
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==0) {
						a=a-1;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==1) {
						a=a-1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==2) {
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==3) {
						a=a+1;
						b=b+1;
						continue;
					}
					if(IndexNajvecegClana(VektorSusjeda(M,a,b))==4) {
						a=a+1;
						continue;
					}
				}
			}
		}

	}
	return std::complex<int> (a,b);
}
int main ()
{
	int a,b,c,d;
	Matrica M;
	std::cout << "Unesite broj redova i kolona matrice:";
	std::cin >> a >> b;
	std::cout << "\nUnesite elemente matrice:";
	M=UnesiMatricu(a,b);
	std::cout << "\nUnesite poziciju odakle zapocinje pretraga:";
	std::cin >> c >> d;
	try {
		std::complex<int> z(VrhMatrice(M,c,d));
		std::cout << "\nNadjen je vrh matrice na poziciji " << z.real() << " " << z.imag() << std::endl;
		std::cout << "Njegova vrijednost je " << M[z.real()][z.imag()];
	} catch(std::domain_error izuzetak1) {
		std::cout << izuzetak1.what();
	} catch(std::range_error izuzetak2) {
		std::cout<<izuzetak2.what();
	}
	return 0;
}
