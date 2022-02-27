/* 
    TP 2018/2019: Tutorijal 6, Zadatak 4
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>

int **KreirajTrougao(int n) {
	if (n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	int **a=nullptr;
	try {
		a=new int *[n];
		a[0]=new int[n*n];
	}
	catch (std::bad_alloc) {
		delete[] a;
		throw;
	}
		
		for (int i=1;i<n;i++) {
			a[i]=a[i-1]+2*(i-1)+1;
		}
			for (int i=0;i<n;i++) {
				int broj=i+1;
				for (int j=0;j<2*i+1;j++) {
					a[i][j]=broj;
					if (j<(2*i+1)/2) broj--;
					else broj++;
				}
			}
		return a;
}

int main ()
{
	int n;
	std::cout << "Koliko zelite redova: ";
	std::cin >> n;
	try {
		auto matrica=KreirajTrougao(n);
		for(int i=0; i<n; i++) {
			for(int j=0; j<(i*2)+1; j++) {
				std::cout << matrica[i][j] << " ";
			}
			std::cout << std::endl;
		}
		delete[] matrica[0];
		delete[] matrica;
	} catch(std::domain_error n) {
		std::cout << "Izuzetak: " << n.what();
	} catch(std::bad_alloc) {
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	return 0;
}