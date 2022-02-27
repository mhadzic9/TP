//TP 2018/2019: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <exception>
#include <algorithm>
#include <cmath>
#include <functional>
typedef std::vector<std::pair<int,double> > TipVektoraParova;
int VeciOdDva (int x,int y) {
    if(x>y) return x;
    else return y;
}
int ManjiOdDva (int x,int y) {
    if(x<y) return x;
    else return y;
}
template <typename tip1>
double clan1 (tip1 x,tip1 y) {
    int suma=0;
    for(int i=x;i<y;i++) {
        suma+=i;
    }
    return suma;
}
template <typename tip2>
double clan2(tip2 b) {
    return pow(-1,b-1);
}
long double clan3a(long double x,long double y) {
    return 1./(x-y);
}
std::function<double(double)>BaricentricnaInterpolacija(TipVektoraParova S,int d) {
    if((d<0) || (d>S.size()))
    throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<(S.size()-1);i++) {
        for(int j=i+1;j<S.size();j++) {
            if(S[i].first==S[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<int> v1;
    std::vector<double> v2;
    for(int i=0;i<S.size();i++){
        v1.push_back(S[i].first);
    }
    for(int i=0;i<S.size();i++) {
        v2.push_back(S[i].second);
    }
    int n=S.size();
    std::vector<long double> W(n,0);
    std::vector<long double> Vd;
    std::vector<int> Vr;
    for(int i=0;i<n;i++) {
        Vr.push_back(v1[i+1]-v1[i]);
    }
    for(int i=0;i<n;i++) {
        for(int k=VeciOdDva(1,i-d);k<=ManjiOdDva(i,n-d);k++) {
            long double c=1;
            for(int j=k;j<=(k+d);j++) {
                if(j!=i) c*=clan3a(Vd[i],Vd[j]);
            }
            W[i]+=c*clan2(k);
        }
    }
    return [S,W,Vd,v2] (long double x) {
        for(int i=0;i<Vd.size();i++) {
            if(Vd[i]==x) {
                return v2[i];break;}}
                double suma1=0,suma2=0;
                for(int i=0;i<S.size();i++) {
                    suma1+=(long double) (W[i]*v2[i])/(long double)(x-Vd[i]);
                }
                for(int i=0;i<S.size();i++) {
                    suma2+=(long double) (W[i])/(long double) (x-Vd[i]);
                }
                return suma1/suma2;
            };
        }
        std::function <double (double)> BaricentricnaInterpolacija(double fun(double),double xmin,double xmax,double dx,int d) {
            TipVektoraParova V;
            int br=(xmax-xmin)/dx+1;
            for(int i=0;i<br;i++) {
                double t=fun(xmin+dx*i);
                std::pair<int,double> P (i,t);
                V.push_back(P);
            }
            auto f1 (BaricentricnaInterpolacija(V,d));
            return f1;
        }
        
    int main () {
        std::pair<int,double> p1=std::make_pair(1,3);
        std::pair<int,double> p2=std::make_pair(2,5);
        std::pair<int,double> p3=std::make_pair(4,4);
        std::pair<int,double> p4=std::make_pair(5,2);
        std::pair<int,double> p5=std::make_pair(7,1);
        TipVektoraParova V;
        V.push_back(p1);
        V.push_back(p2);
        V.push_back(p3);
        V.push_back(p4);
        V.push_back(p5);
        auto f(BaricentricnaInterpolacija(V,2));
        std::cout << f(2.5);
	return 0;
}