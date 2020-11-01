#include <iostream>
#include "GeomFig.h"
using namespace std;

class Rectangle: public GeomFig{
    private:
    int l1,l2;

    public:
        Rectangle() : l1(5), l2(10){};
        Rectangle(int &x, int &y) : l1(x), l2(y){};

        void area(){
            cout<< "Area is" <<l1*l2 <<"\n";
        }
        
        void perimeter(){
            cout<< "Perimeter is" <<2*l1+2*l2 <<"\n";
        }

        Rectangle::Rectangle& rec(){
            static Rectangle rc;
            return rc;
        }
};