#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <set>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cctype>
void IspisiSkup(std::set <int>s){
    std::vector<int> V;
    for(auto x:s)V.push_back(x);
for(int i=0;i<(V.size()-1);i++) {
        std::cout<<V[i]<<",";}
            std::cout<<V[V.size()-1];}
void IspisiSkupBezZareza(std::set <int>s){
    std::vector<int> V;
    for(auto x:s)V.push_back(x);
for(int i=0;i<(V.size()-1);i++) {
    std::cout<<V[i]<<" ";}
        std::cout<<V[V.size()-1];}
bool ZnakJe(char a){
    if(((a>=48) && (a<=57)) || (a>=65 && a<=90) || (a>=97 && a<=122)) return true;
    return false;}
void IspisiString(std::string S){
for(auto it=S.begin(); it!=S.end(); it++) {
    std::cout <<*it;
}
}
std::string ManjeSlovo(std::string s){
    for(int i=0; i<s.length(); i++) {
        s[i]=tolower(s[i]);
}
return s;}
bool IstiStringovi(std::string s1,std::string s2){
    if(s1.size()!=s2.size()) return false;
for(int i=0; i<s1.size(); i++) {
        if(((s1[i]>=48) && (s1[i]<=57)) || (tolower(s1[i])!=tolower(s2[i]))) return false;}
    return true;
    }
std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string s){
    std::map<std::string,std::set<int>> Mapa;
for(auto i=s.begin(); i!=s.end();) {
        if(ZnakJe(*i)) {std::string rijec;
        auto j=i;
        while (ZnakJe(*j)) {
                rijec.push_back(tolower(*j));
                j++;
            }
            std::set <int> skup;
            for(int b1=0; b1<s.length(); b1++) {
                int b2=b1;
                while(ZnakJe(s[b2])) b2++;
                if(ManjeSlovo(rijec)==ManjeSlovo(s.substr(b1,b2-b1))) {skup.insert(b1);}
                if(ZnakJe(s[b2])==0) b1=b2;
                while(ZnakJe(s[b1])) b1++;
            }
            i=j;
            Mapa.insert(std::make_pair(rijec,skup));
        } 
        else i++;
    }
    return Mapa;
}
void IspisiPar (std::pair<std::string,std::set<int>> p){
    IspisiString(p.first);std::cout << ": ";IspisiSkup(p.second);std::cout << std::endl;
}
std::set <int> PretraziIndeksPojmova (std::string s,std::map<std::string,std::set<int>> Mapa){
    std::set<int> Skup;
    if((s!=".") && (Mapa.count(s)==0)) throw std::logic_error("Unesena rijec nije nadjena!");
    if(Mapa.count(s)) {
        for(auto it=Mapa.begin(); it!=Mapa.end(); it++) {
            if(ManjeSlovo(it->first)==ManjeSlovo(s)) {
                for(auto x:(it->second)) Skup.insert(x);
            }
        }
    }
    return Skup;
}
void IspisiIndeksPojmova (std::map<std::string,std::set<int>> Mapa){
    for(auto IT:Mapa) {
        IspisiPar(IT);}
}

int main (){
std::cout << "Unesite tekst: ";
std::string s;
std::getline(std::cin,s);
auto M(KreirajIndeksPojmova(s));
IspisiIndeksPojmova(M);
std::string rijec;
std::cout << "Unesite rijec: ";
while(rijec!=".") {
std::getline(std::cin,rijec);if(rijec==".") break;
try {
    auto SK(PretraziIndeksPojmova(rijec,M));
    IspisiSkupBezZareza(SK);std::cout << std::endl;} 
    catch(std::logic_error izuzetak) {std::cout << izuzetak.what() << std::endl;}
std::cout <<"Unesite rijec: ";}
    return 0;
}
