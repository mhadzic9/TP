//TP 2018/2019: Ispit 1, Zadatak 3
#include <iostream>
#include <string>

int OgradiRijec (std::string s,int n) {
        int broj_rijeci=0,razmak=1;
        for (int i=0;i<s.length();i++) {
            if (s.at(i)==' ') {
                razmak=1;
                while (s.at(i)==' '){ 
                    i++;
                    if (i==s.length()-1)break;
                }
            }
            else if (razmak==1) {
                razmak=0;
                broj_rijeci++;
            }
            if(broj_rijeci==n) {
                s.insert(s.begin()+i,'(');
            }
        }
            if (n<=0 || n>broj_rijeci) throw std::range_error ("Nema toliko rijeci u tom stringu!");
            
            /*for (int i=0;i<s.length();i++) {
                
            }*/
            
        
        return broj_rijeci;
}

int main ()
{
    try{
    int broj=OgradiRijec("  ja sam string",2);
    std::cout << broj;
    }
    catch(std:: range_error izuzetak) {
        std::cout << izuzetak.what();
    }
    
	return 0;
}