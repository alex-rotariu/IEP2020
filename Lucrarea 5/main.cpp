#include <iostream>

using namespace std;

class Pizza{
    private:
        string name;
        int price;
    
    public:
        Pizza() : name("pizzoasa"), price(15){};
        Pizza(string n, int p):
            name(n),
            price(p),
        {};
        Pizza(const Pizza& rhs);
        Pizza& operator=(const Pizza& rhs){
            this->name=rhs.name;
            this->price=rhs.price;
            return *this;
        };
        void toString(){
            cout<<name<<" "<<price;
        }  
};

class Capriciosa : public Pizza{

}

class Diavola : public Pizza {

}

class Sos {

}

int main(){
    Pizza *p1 = new Pizza("bomba",10);
    Pizza p2;
    p1->toString();
    cout<<endl;
    p2.toString();
    return 0;
}