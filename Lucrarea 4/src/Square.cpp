#include <iostream>
#include "GeomFig.h"
using namespace std;

class Square: public GeomFig{
    private:
    int l;

    public:
        Square() : l(5){};
        Square(int &x) : l(x){};

        void area(){
            cout<< "Area is" <<l*l <<"\n";
        }
        
        void perimeter(){
            cout<< "Perimeter is" <<4*l <<"\n";
        }

        Square::Square& rec(){
            static Square rc;
            return rc;
        }
};