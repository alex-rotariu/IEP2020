#include <iostream>

using namespace std;
class Sos {
    private:
        string tipSos;
    
    public:
        Sos(string ts): tipSos(ts){};
        string getTipSos(){
            return this->tipSos;
        }
};

class Pizza{
    private:
        string name;
        int price;
        Sos *sos;
    
    public:
        Pizza() : name("pizzoasa"), price(15){};

        Pizza(string n, int p, Sos *s):
            name(n),
            price(p),
            sos(s)
        {};

        Pizza(const Pizza& rhs);

        Pizza& operator=(const Pizza& rhs){
            this->name=rhs.name;
            this->price=rhs.price;

            Sos *orig = sos;
            this->sos=new Sos(*rhs.sos);
            delete orig;

            return *this;
        };

        void toStringDefault(){
            cout<<"Pizza:"<<name<<"-> "<<price<< "lei";
        }
        void toString(){
            cout<<"Pizza:"<<name<<"-> "<<price<< "lei cu "<<sos->getTipSos();
        }    
};

class Capriciosa : public Pizza{

};

class Diavola : public Pizza {

};

int main(){
    Sos *s1 = new Sos("sos de muiere(comanda speciala pt Roata)");

    Pizza *p1 = new Pizza("bomba",10,s1);
    Pizza p2;
    p1->toString();
    cout<<endl;
    p2.toStringDefault();
    return 0;
}