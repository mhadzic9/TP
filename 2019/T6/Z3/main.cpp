/* 
    TP 2018/2019: Tutorijal 6, Zadatak 3
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>

int **KreirajTrougao(int n) {
	if (n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	try {
	int **a=new int* [n];
	for (int i=0;i<n;i++) a[i]=nullptr;
	try {
		for (int i=0;i<n;i++) a[i]=new int[i*2+1];
		for (int i=0;i<n;i++) {
			int broj=i+1;
			for (int j=0;j<i*2+1;j++) {
				a[i][j]=broj;
				if (j<i) broj--;
				else broj ++;
			}
		}
		return a;
	}
	catch (std::bad_alloc) {
		for (int i=0;i<n;i++) delete [] a[i];
		delete [] a;
		throw;
	}
	}
	catch (std::bad_alloc) {
		throw;
	}
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
		for(int i=0; i<n; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	} catch(std::domain_error n) {
		std::cout << "Izuzetak: " << n.what();
	} catch(std::bad_alloc) {
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	return 0;
}