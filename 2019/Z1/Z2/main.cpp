//TP 2016/2017: Zadaća 1, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>

typedef std::vector<std::vector<double>> Matrica;
enum Smjer {Opadajuci,Rastuci};

bool DaLiJeBalansiran (std::vector<double> v)
{
    double suma1=0,suma2=0;
    const double EPSILON=0.00001;
    if (v.size()%2==0) {
        for (int i=0; i<v.size()/2; i++) {
            suma1+=v.at(i);
        }
        for (int j=v.size()/2; j<v.size(); j++) {
            suma2+=v.at(j);
        }
        if (suma1-suma2>-EPSILON && suma1-suma2<EPSILON) {
            return true;
        }
    }
    if (v.size()%2!=0) {
        for (int i=0; i<v.size()/2; i++) {
            suma1+=v.at(i);
        }
        for (int j=v.size()/2+1; j<v.size(); j++) {
            suma2+=v.at(j);
        }
        if (suma1-suma2>-EPSILON && suma1-suma2<EPSILON) {
            return true;
        }
    }
    return false;
}

std::vector<double> FormirajPodniz (std::vector<double> ve,int clan,int duzina)
{
    std::vector<double> vektor;
    for (int i=0; i<duzina; i++) {
        vektor.push_back(ve.at(clan+i));
    }
    return vektor;
}

Matrica FormirajSvePodnizove (std::vector<double> v1)
{
    Matrica m;
    for (int i=0; i<v1.size(); i++) {
        for (int j=i+1; j<v1.size(); j++) {
            int k=j-i+1;
            m.push_back(FormirajPodniz(v1,i,k));
        }
    }
    return m;
}

bool DaLiJePodniz (std::vector<double> v1,std::vector<double> v2)
{
    if (v1.size()==v2.size()) {
        return false;
    }
    if (v1.size()>v2.size()) {
        Matrica m=FormirajSvePodnizove(v1);
        for (int i=0; i<m.size(); i++) {
            if (v2==m.at(i)) return true;
        }
    }
    if (v1.size()<v2.size()) {
        Matrica m=FormirajSvePodnizove(v2);
        for (int i=0; i<m.size(); i++) {
            if (v1==m.at(i)) return true;
        }
    }
    return false;
}

std::deque<std::vector<double>> MaksimalniBalansiraniPodniz (std::vector<double> v)
{
    std::deque<std::vector<double>> d;
    if (v.size()==0 || v.size()==1) {
        return d;
    }
    if (DaLiJeBalansiran(v)) {
        d.push_back(v);
        return d;
    }
    auto m=(FormirajSvePodnizove(v));
    for (int i=0; i<m.size(); i++) {
        if (DaLiJeBalansiran(m.at(i))) {
            d.push_back(m.at(i));
        }
    }
    for (int i=0; i<d.size(); i++) {
        for (int j=0; j<d.size(); j++) {
            if(DaLiJePodniz(d.at(i),d.at(j))) {
                d.erase(d.begin()+j);
            }
        }
    }
    for (int i=0; i<d.size(); i++) {
        if (d.at(i).size()<3) {
            d.erase(d.begin()+i);
        }
    }
    return d;
}

std::vector<double> Rastenje (std::vector<double> v)
{
    double temp;
    if (v.size()%2==0) {
        for (int i=0; i<v.size()/2; i++) {
            int min=i;
            for (int j=i+1; j<v.size()/2; j++) {
                if (v.at(j)<v.at(min)) {
                    min=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(min);
            v.at(min)=temp;
        }
        for (int i=v.size()/2; i<v.size(); i++) {
            int max=i;
            for (int j=i+1; j<v.size(); j++) {
                if (v.at(j)>v.at(max)) {
                    max=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(max);
            v.at(max)=temp;
        }
    }
    if (v.size()%2!=0) {
        for (int i=0; i<v.size()/2; i++) {
            int min=i;
            for (int j=i+1; j<v.size()/2; j++) {
                if (v.at(j)<v.at(min)) {
                    min=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(min);
            v.at(min)=temp;
        }
        for (int i=v.size()/2+1; i<v.size(); i++) {
            int max=i;
            for (int j=i+1; j<v.size(); j++) {
                if (v.at(j)>v.at(max)) {
                    max=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(max);
            v.at(max)=temp;
        }
    }
    return v;
}
std::vector<double> Opadanje (std::vector<double> v)
{
    double temp;
    if (v.size()%2==0) {
        for (int i=0; i<v.size()/2; i++) {
            int max=i;
            for (int j=i+1; j<v.size()/2; j++) {
                if (v.at(j)>v.at(max)) {
                    max=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(max);
            v.at(max)=temp;
        }
        for (int i=v.size()/2; i<v.size(); i++) {
            int min=i;
            for (int j=i+1; j<v.size(); j++) {
                if (v.at(j)<v.at(min)) {
                    min=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(min);
            v.at(min)=temp;
        }
    }
    if (v.size()%2!=0) {
        for (int i=0; i<v.size()/2; i++) {
            int max=i;
            for (int j=i+1; j<v.size()/2; j++) {
                if (v.at(j)>v.at(max)) {
                    max=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(max);
            v.at(max)=temp;
        }
        for (int i=v.size()/2+1; i<v.size(); i++) {
            int min=i;
            for (int j=i+1; j<v.size(); j++) {
                if (v.at(j)<v.at(min)) {
                    min=j;
                }
            }
            temp=v.at(i);
            v.at(i)=v.at(min);
            v.at(min)=temp;
        }
    }
    return v;
}

std::deque<std::vector<double>> Transformacija (std::deque<std::vector<double>> d,Smjer s)
{
    for (int i=0; i<d.size(); i++) {
        if (DaLiJeBalansiran(d.at(i))==false) {
            throw std::domain_error ("Dek vektora je neispravan.");
        }
    }
    if (s==Rastuci) {
        for (int i=0; i<d.size(); i++) {
            d.at(i)=Rastenje(d.at(i));
        }
    }
    if(s==Opadajuci) {
        for (int i=0; i<d.size(); i++) {
            d.at(i)=Opadanje(d.at(i));
        }
    }
    return d;
}


int main ()
{
    int n;
    std::cout << "Unesite broj elemenata niza: ";
    std::cin >> n;
    double a;
    std::vector <double> v;
    std::cout << "Unesite elemente niza: ";
    do {
        std::cin >> a;
        v.push_back(a);
        if(v.size()==n) break;
    } while (v.size()<n);
    int tip;
    std::cout << "Unesite tip: (1 - rastuci, 0 - opadajuci): ";
    std::cin >> tip;
    std::cout << std::endl;
    std::deque<std::vector<double>> d;
    d=MaksimalniBalansiraniPodniz(v);
    std::cout << "Maksimalni balansirani podnizovi: ";
    std::cout << std::endl;
    for (std::vector<double> r:d) {
        for (double x:r) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Savrseni balansirani podnizovi nakon transformacije: " << std::endl;
    if (tip==1) {
        try {
            d=Transformacija(d,Rastuci);
            for (std::vector<double> r:d) {
                for (double x:r) {
                    std::cout << x << " ";
                }
                std::cout << std::endl;
            }
        } catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what();
        }
    }
    if (tip==0) {
        try {
            d=Transformacija(d,Opadajuci);
            for (std::vector<double> r:d) {
                for (double x:r) {
                    std::cout << x << " ";
                }
                std::cout << std::endl;
            }
        } catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what();
        }
    }
    return 0;
}
