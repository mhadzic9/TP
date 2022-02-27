#include <iostream>

template <typename TipElemenata>
struct Cvor {
    TipElemenata element;
    Cvor *veza;
};

template <typename TipElemenata>
class Stek
{
    Cvor<TipElemenata> vrh;
    
    public:
    
    //Zabrane
    Stek operator=(const Stek &o) = delete;
    Stek operator=(Stek &&o) = delete;
    Stek (const Stek &o) = delete;
    Stek (Stek &&o) = delete;
    
    bool empty()const{if (vrh.veza==nullptr) return true;};
    // TipElementa &top() {return vrh.element;};
    // TipElementa top() {return vrh.element;};
    
};


int main ()
{
	return 0;
}