//TP 2016/2017: Zadaća 1, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<std::vector<std::vector<double>>> Matrica3D;

Matrica KreirajMatricu (int br_redova, int br_kolona)
{
    return Matrica(br_redova,std::vector<double>(br_kolona));
}
int BrojRedova(Matrica M)
{
    return M.size();
}
int BrojKolona(Matrica M)
{
    return M.at(0).size();

}
Matrica UnesiMatricu (int br_redova,int br_kolona)
{
    Matrica m=KreirajMatricu(br_redova, br_kolona);
    for (int i=0; i<br_redova; i++) {
        std::cout << "Elementi " << i+1 << ". reda: ";
        for (int j=0; j<br_kolona; j++) {
            std::cin >> m.at(i).at(j);
        }
    }
    return m;
}

Matrica MnozenjeMatrica (Matrica m1, Matrica m2)
{
    Matrica x;
    if((m1.size()==0) && (m2.size()==0))return x;

    if (m1.size()==0 || m2.size()==0 || m1.at(0).size()!=m2.size()) {
        throw std::domain_error ("Nije moguce mnozenje matrica!");
    }


    for (int i=0; i<m1.size(); i++) {
        for (int j=0; j<m1.at(0).size(); j++) {

            if ((m1.at(i).size()!=m1.at(0).size()) || (m2.at(i).size()!=m2.at(0).size())) {
                throw std::domain_error ("Neispravna matrica!");
            }
        }
    }
    Matrica m3=KreirajMatricu(m1.size(),m2.at(0).size());
    for (int i=0; i<m1.size(); i++) {
        for (int j=0; j<m2.at(0).size(); j++) {
            double suma=0;
            for (int k=0; k<m2.size(); k++) {
                suma+=m1.at(i).at(k)*m2.at(k).at(j);
            }
            m3.at(i).at(j)=suma;
        }
    }
    return m3;
}
void IspisiMatricu (Matrica m)
{
    for (int i=0; i<BrojRedova(m); i++) {
        for (int j=0; j<BrojKolona(m); j++) {
            
            std::cout <<std::setw(9) << std::fixed << std::setprecision(4)<< m.at(i).at(j);
        }
        std::cout << std::endl;
    }
    
}

Matrica3D DoolitleLU (Matrica H)
{
    Matrica3D LU;
    if(H.size()==0)return LU;
    if (BrojRedova(H)!=BrojKolona(H)) {
        throw std::domain_error ("Matrica mora biti kvadratnog oblika!");
    }
    for (int i=0; i<H.size(); i++) {
        if ((H.at(i).size()!=H.at(0).size())) {
            throw std::domain_error ("Neispravna matrica!");

        }
    }
    Matrica L(H);
    Matrica U(H);
    for (int i=0; i<H.size(); i++) {
        for (int j=0; j<H.at(i).size(); j++) {
            if(j==i) {
                L.at(i).at(j)=1;
            }
            if(j>i) {
                L.at(i).at(j)=0;
            }
            if(j<i) {
                U.at(i).at(j)=0;
            }
        }
    }
    for (int i=0; i<H.size(); i++) {
        for (int j=0; j<H.at(i).size(); j++) {
            if(j>=i) {
                double g1=0;
                for (int m=0; m<i; m++) {
                    g1+=L.at(i).at(m)*U.at(m).at(j);
                }
                U.at(i).at(j)=H.at(i).at(j)-g1;
            }
            
            if(j<i) {
                double g2=0;
                for(int k=0; k<j; k++) {
                    g2+=L.at(i).at(k)*U.at(k).at(j);
                }
                L.at(i).at(j)=(H.at(i).at(j)-g2)/(U.at(j).at(j));
            }
            

        }
    }
    LU.push_back(L);
    LU.push_back(U);
    return LU;

}

bool ProvjeriFaktorizaciju (Matrica H, Matrica3D LU)
{
    if (H.size()==0) return true;
    if(BrojKolona(H)!=BrojRedova(H)) return false;
    for (int i=0; i<H.size(); i++) {
        if ((H.at(i).size()!=H.at(0).size())) {
            return false;
        }
    }
    if (LU==DoolitleLU(H)) return true;
    return false;
}

int main ()
{
    int d;
    std::cout << "Unesite dimenziju kvadratne matrice H: ";
    std::cin >> d;
    std::cout << "Unesite elemente matrice H: "<<std::endl;
    Matrica m=UnesiMatricu(d,d);
    try{
    Matrica3D LU=DoolitleLU(m);
    std::cout << "Matrica L:" << std::endl;
    IspisiMatricu(LU.at(0));
    std::cout << "Matrica U:" << std::endl;
    IspisiMatricu(LU.at(1));}
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
