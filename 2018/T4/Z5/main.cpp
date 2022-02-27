//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
template <typename TipNE>
std::vector<TipNE> Presjek(std::vector<TipNE> n, std::vector<TipNE> e) {
    std::vector<TipNE> s;
    for (int i=0;i<n.size();i++) {
        for(int j=0;j<e.size();j++) {
            if(n[i]==e[j]) {
                s.push_back(n[i]);
            }
        }
        
    }
    int i=0;
    int j=0;
    while(i<s.size()) {
        j=i+1;
        while(j<s.size()) {
            if(s[i]==s[j]) {
                s.erase(s.begin()+j);
                j--;
            }
            j++;
        }
        i++;
    }
    return s;
}
int main ()
{
	return 0;
}