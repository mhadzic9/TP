//TP 2018/2019: Ispit 6, Zadatak 2
#include <iostream>
#include <cstring>
#include <initializer_list>

class String {
    char *niz_znakova;
    int br_znakova;
    public:
    String(const char* niz=""): niz_znakova(new char[std::strlen(niz)]), br_znakova(std::strlen(niz)) {}
    String(int broj, char znak):br_znakova(broj) {
        if(broj<=0) {
            niz_znakova=new char[1];
            niz_znakova[0]='\0';
            br_znakova=0;
        } else {
            niz_znakova=new char[broj];
            for(int i=0;i<broj;i++) niz_znakova[i]=znak;
        }
    }
    String(std::initializer_list<char> lista): br_znakova(lista.size()) {
        niz_znakova=new char[lista.size()];
        int broj=0;
        for(auto it=lista.begin();it!=lista.end();it++) niz_znakova[broj++]=*it;
    }
    String(const String& s) {
        br_znakova=s.br_znakova;
        for(int i=0;i<br_znakova;i++) {
            niz_znakova[i]=s.niz_znakova[i];
        }
    }
    String(String&& s) : niz_znakova(s.niz_znakova) { s.niz_znakova=nullptr;}
    ~String() { delete[] niz_znakova; br_znakova=0;}
    String& operator=(const String& s) {
        delete niz_znakova;
         br_znakova=s.br_znakova;
        for(int i=0;i<br_znakova;i++) {
            niz_znakova[i]=s.niz_znakova[i];
        }
        return *this;
    }
    String& operator=(String&& s) {
        niz_znakova=s.niz_znakova;
        s.niz_znakova=nullptr;
        return *this;
    }
    String& operator=(const char* niz) {
        delete[] niz_znakova;
        br_znakova=std::strlen(niz);
        for(int i=0;i<br_znakova;i++) {
            niz_znakova[i]=niz[i];
    }
    return *this;
    }
    int DajDuzinu() const {
        return br_znakova;
    }
    char* begin() const { return niz_znakova;}
    char* end() const { return niz_znakova+br_znakova;}
    friend std::ostream& operator<<(std::ostream& tok, const String& s) {
        tok<<s.niz_znakova;
        return tok;
    }
    char operator[](int indeks) const {
        if(indeks<0 || indeks>br_znakova-1) throw std::range_error("Neispravan indeks");
        return niz_znakova[indeks];
    }
    char& operator[](int indeks) {
        if(indeks<0 || indeks>br_znakova-1) throw std::range_error("Neispravan indeks");
        return niz_znakova[indeks];
    }
    friend String operator+(const String& s1, const String& s2) {
        String novi;
        novi.br_znakova=s1.br_znakova+s2.br_znakova;
        for(int i=0;i<s1.br_znakova;i++) novi.niz_znakova[i]=s1.niz_znakova[i];
        for(int i=0;i<s2.br_znakova;i++) novi.niz_znakova[i+s1.br_znakova]=s2.niz_znakova[i];
        return novi;
    }
    friend String operator+(const String& s1, const char* s2) {
        String novi;
        novi.br_znakova=s1.br_znakova+std::strlen(s2);
        for(int i=0;i<s1.br_znakova;i++) novi.niz_znakova[i]=s1.niz_znakova[i];
        for(int i=0;i<std::strlen(s2);i++) novi.niz_znakova[i+s1.br_znakova]=s2[i];
        return novi;
    }
     friend String operator+(const char *s1, const String& s2) {
        String novi;
        novi.br_znakova=std::strlen(s1)+s2.br_znakova;
        for(int i=0;i<std::strlen(s1);i++) novi.niz_znakova[i]=s1[i];
        for(int i=0;i<s2.br_znakova;i++) novi.niz_znakova[i+std::strlen(s1)]=s2[i];
        return novi;
    }
    String& operator+=(const String& s) {
        br_znakova+=s.br_znakova;
        for(int i=0;i<s.br_znakova;i++) niz_znakova[i+s.br_znakova]=s.niz_znakova[i];
        return *this;
    }
};
int main ()
{
       String s2 = "Dobar dan", s4{'D', 'a', 'n', 'a', 's', ' ', 'j', 'e', ' ', 'i', 's', 'p', 'i', 't', '.'};
    std::cout << "S2: " << s2 << " S4: " << s4 << std::endl;
    s2 = s4;
    std::cout << "S2: " << s2 << " S4: " << s4 << std::endl;
	return 0;
}