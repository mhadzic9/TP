//TP 2018/2019: Ispit 1, Zadatak 1
#include <iostream>
#include <vector>
#include <list>
//#include <stdexception>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu (int br_redova,int br_kolona) {
    return Matrica (br_redova,std::vector<double> (br_kolona));
}
Matrica UnesiMatricu (int br_redova,int br_kolona) {
    auto m=KreirajMatricu(br_redova,br_kolona);
    for (int i=0;i<br_redova;i++) {
        for (int j=0;j<br_kolona;j++) {
            std::cin >> m.at(i).at(j);
        }
    }
    return m;
}
double Suma (std::vector<double> v){
    double s=0;
    for (auto x:v){
        s+=x;
    }
    return s;
}
std::list<bool>TransformirajMatricu (Matrica &m) {
    for (int i=0;i<m.size();i++) {
        if (m.at(i).size()!=m.at(0).size()) {
            throw std::domain_error ("Parametar nema formu matrice");
        }
    }
    Matrica m1;
    for (int i=m.size();i>=0;i--) {
        m1.push_back(m.at(i));
    }
    m=m1;
    std::list<bool> l1;
    for (auto x:m) {
        if (Suma(x)==int(Suma(x))) {
            l1.push_back(true);
        }
        if (Suma(x)!=int(Suma(x))){
            l1.push_back(false);
        }
    }
    return l1;
}

int main ()
{
    int a,b;
    std::cout << "Unesite broj redova: ";
    std::cin >> a;
    std::cout << "Unesite broj kolona: ";
    std::cin >> b;
    std::cout << "Unesite elemente matrice: ";
    auto m(UnesiMatricu(a,b));
    auto l(TransformirajMatricu(m));
    std::cout << "Transformirana matrica: ";
    for (int i=0;i<m.size();i++){
        for (int j=0;j<m.at(0).size();j++) {
            std::cout << m.at(i).at(j);
        }
        std::cout << std::endl;
    }
    for (auto x:l) {
        std::cout << std::boolalpha << x <<" ";
    }
    
	return 0;
}