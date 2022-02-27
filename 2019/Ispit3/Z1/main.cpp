#include <iostream>
#include <cmath>

using namespace std;

class Tacka
{
    double x;
    double y;
    
    public:
    Tacka (double x, double y) : x(x), y(y){};
    Tacka () = delete;
    
    double DajX()const {return x;};
    double DajY()const {return y;};
    
    Tacka &PostaviX(double x1){x=x1; return *this;};
    Tacka &PostaviY (double y1){y=y1; return *this;};
    
    static double Rastojanje(Tacka prva, Tacka druga);
    
    friend ostream &operator << (ostream &tok, const Tacka &t);
};

ostream &operator << (ostream &tok, const Tacka &t)
{
    tok << "(" << t.DajX() << "," << t.DajY() << ")";
    return tok;
}

double Tacka::Rastojanje(Tacka prva, Tacka druga)
{
    return sqrt(pow(druga.DajX()-prva.DajX(), 2)+pow(druga.DajY()-prva.DajY(), 2));
}

class Krug
{
    Tacka centar;
    double r;
    
    public:
    
    Krug(Tacka t, double poluprecnik) : centar(t), r(poluprecnik) {if (poluprecnik < 0) throw domain_error("Neispravan poluprecnik");};
    Krug(double x, double y, double r) : centar(x, y){if (r < 0) throw domain_error("Neispravan poluprecnik"); Krug::r = r;};
    Krug(Tacka c, Tacka rubna) : centar(c){double rastojanje = Tacka::Rastojanje(c, rubna); if (rastojanje < 0) throw domain_error("Neispravan poluprecnik"); r= rastojanje;};
    void Postavi(Tacka t, double poluprecnik){if (poluprecnik < 0) throw domain_error("Neispravan poluprecnik"); centar = t; r = poluprecnik;};
    void Postavi (double x, double y, double poluprecnik){if (poluprecnik < 0) throw domain_error("Neispravan poluprecnik"); centar = Tacka(x,y); r = poluprecnik;};
    void Postavi (Tacka c, Tacka rubna){centar = c; double rastojanje = Tacka::Rastojanje(c, rubna); if (rastojanje < 0) throw domain_error("Neispravan poluprecnik"); r= rastojanje;};
    
    Tacka DajCentar() const{return centar;};
    double DajCentarX() const{return centar.DajX();};
    double DajCentarY() const {return centar.DajY();};
    double DajPoluprecnik() const{return r;};
    
    double DajObim() const{return (4*atan(1)) * 2 * r;};
    double DajPovrsinu()const {return r*r*4*atan(1);};
    
    Krug &operator+=(Tacka t)
    {
        this->Postavi(this->DajCentarX()+t.DajX(), this->DajCentarY()+t.DajY(), this->DajPoluprecnik());
        return *this;
    }
    Krug &operator *=(double s)
    {
        if (s < 0) throw domain_error ("Neispravno skaliranje");
        this->Postavi(this->DajCentar(), this->DajPoluprecnik()*s);
        return *this;
    }
    
    Krug operator++(int)
    {
        Krug kopija = *this;
        this->Postavi(this->DajCentar(), this->DajPoluprecnik()+1);
        return kopija;
    }
    Krug& operator++()
    {
        this->Postavi(this->DajCentar(), this-> DajPoluprecnik()+1);
        return *this;
    }
    
    friend ostream &operator << (ostream &tok, const Krug &K);
};

Krug operator+(Krug K, Tacka t)
{
    K.Postavi(K.DajCentarX()+t.DajX(), K.DajCentarY()+t.DajY(), K.DajPoluprecnik());
    return K;
}

Krug operator*(Krug K, double s)
{
    if (s < 0) throw domain_error ("Neispravno skaliranje");
    K.Postavi(K.DajCentar(), K.DajPoluprecnik()*s);
    return K;
}

Krug operator*(double s, Krug  K)
{
    if (s < 0) throw domain_error ("Neispravno skaliranje");
    return K*s;
}

ostream &operator << (ostream &tok, const Krug &K)
{
    tok << "{" << K.DajCentar() << "," << K.DajPoluprecnik() << "}";
    return tok;
}

int main ()
{
	Krug k(1, 23 , 4);
	cout << "Obim kruga je: " << k.DajObim() << endl;;
	cout << "Povrsina kruga je: " << k.DajPovrsinu() << endl;
	k*= 4;
	k++;
	cout << "Obim kruga je: " << k.DajObim() << endl;;
	cout << "Povrsina kruga je: " << k.DajPovrsinu() << endl;
	
	cout <<  endl << "Krug k: " << k << endl;
}