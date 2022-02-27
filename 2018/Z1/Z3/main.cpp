#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu(int broj_redova,int broj_kolona)
{
	return Matrica(broj_redova,std::vector<int>(broj_kolona));
}
Matrica UnesiMatricu(int br_redova,int br_kolona)
{
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++)
		for(int j=0; j<br_kolona; j++) {
			std::cin>>m.at(i).at(j);
		}
	return m;
}
Matrica KroneckerovProizvod(Matrica A,Matrica B)
{
	Matrica D;
	D.resize(0);
	if((A.size()==0) || (B.size()==0))return D;
	bool a1=1,b1=1;
	for(int i=0; i<A.size(); i++) {
		if(A.at(i).size()!=A.at(0).size()) {
			a1=0;
			break;
		}
	}
	for(int i=0; i<B.size(); i++) {
		if(B.at(i).size()!=B.at(0).size()) {
			b1=0;
			break;
		}
	}
	if((a1==0) && b1)throw std::domain_error ("Prvi parametar nema formu matrice");
	if(a1 && (b1==0))throw std::domain_error ("Drugi parametar nema formu matrice");
	if ((a1==0) && (b1==0)) throw std::domain_error ("Parametri nemaju formu matrice");

	int broj_redova(A.size()*B.size());
	int broj_kolona(A.at(0).size()*B.at(0).size());
	Matrica C(KreirajMatricu(broj_redova,broj_kolona));
	for(int i=0; i<broj_redova; i++) {
		for(int j=0; j<broj_kolona; j++)
			C[i][j]=A[i/B.size()][j/B.at(0).size()]*B[i%B.size()][j%B.at(0).size()];
	}
	return C;
}
int main()
{
	int a,b,c,d;
	std::cout << "Unesite dimenzije prve matrice:";
	std::cin >> a >> b;
	std::cout << "\nUnesite elemente prve matrice:";
	Matrica A(UnesiMatricu(a,b));
	std::cout <<"\nUnesite dimenzije druge matrice:";
	std::cin >> c >> d;
	std::cout << "\nUnesite elemente druge matrice:";
	Matrica B(UnesiMatricu(c,d));
	Matrica C;
	try {
		C=(KroneckerovProizvod(A,B));
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	int s=0;
	for (int i=0; i<C.size(); i++) {
		for(int j=0; j<C[0].size(); j++) {
			if(((C.at(i).at(j)>0) && (log(C.at(i).at(j)>s)))) s=log(C.at(i).at(j));
			if((C[i][j]<0) && (((log(-C.at(i).at(j)+1))>s))) s=log(-C.at(i).at(j))+1;
		}
	}

	std::cout << "\nNjihov Kroneckerov proizvod glasi:" << std::endl;
	for(int i=0; i<C.size(); i++) {
		for(int j=0; j<C.at(0).size(); j++) {
			if(j==0)std::cout.width(s);
			if(j<(C.at(0).size()-1)) {
				std::cout << C.at(i).at(j) ;
				std::cout.width(s);
			}
			if(j==(C.at(0).size()-1)) {
				std::cout<<C.at(i).at(j);

			}

		}
		std::cout<<std::endl;
	}
	return 0;
}
