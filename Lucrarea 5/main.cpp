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
        Pizza() : name("Casei"), price(15), sos(new Sos("fara sos")){};

        Pizza(string n, int p, Sos *s):
            name(n),
            price(p),
            sos(s)
        {};

        Pizza(const Pizza& rhs):
            name(rhs.name),
            price(rhs.price),
            sos(rhs.sos)
        {};

        Pizza& operator=(const Pizza& rhs){
            this->name=rhs.name;
            this->price=rhs.price;

            Sos *orig = sos;
            this->sos=new Sos(*rhs.sos);
            delete orig;

            return *this;
        };

        void toString(){
            cout<<name<<" -> "<<price<< " lei cu "<<sos->getTipSos();
        }    
};

class Capriciosa : public Pizza{
    private:
        string topping;
    public:
        Capriciosa(string n, int p, Sos *s, string t):
            Pizza(n, p, s),
            topping(t)
        {};
        Capriciosa(const Capriciosa& rhs):
            Pizza(rhs),
            topping(rhs.topping)
        {};
        Capriciosa& operator=(const Capriciosa& rhs){
            Pizza::operator=(rhs);
            topping=rhs.topping;

            return *this;
        }
        void toString(){
            Pizza::toString();
            cout<<" "<<topping;
        }
};

int main(){
    Sos *s1 = new Sos("ardei");
    Sos *s2 = new Sos("rosii");
    Sos *s3 = new Sos("usturoi");

    Pizza p1("La 15 lei",15,s1);
    Pizza p2("La 20 de lei",20,s2);
    Capriciosa c1("Capriciosa", 22, s3, "porumb");
    Capriciosa c2("Capriciosa", 22, s3, "ciuperci");

    cout<<"Pizza 1: ";
    p1.toString();
    cout<<endl<<"Pizza 2: ";
    p2.toString();
    Pizza p3(p1);
    cout<<endl<<"Pizza 3 copy constructor: ";
    p3.toString();
    Pizza p4("La 10 lei", 10, s1);
    p4=p2;
    cout<<endl<<"Pizza 4 assignment operator: ";
    p4.toString();
    cout<<endl;

    cout<<endl<<"Capriciosa 1: ";
    c1.toString();
    cout<<endl<<"Capriciosa 2: ";
    c2.toString();
    Capriciosa c3(c1);
    cout<<endl<<"Capriciosa 3 copy constructor: ";
    c3.toString();
    Capriciosa c4=c2;
    cout<<endl<<"Capriciosa 4 assignment operator: ";
    c4.toString();
    cout<<endl;
    return 0;
}