#include <iostream>
// #include "GeomFig.h"
using namespace std;

class Square: public GeomFig{
    // This class won't be able to call the copy constructor
    // or copy assignment operator as they are private
    private:
        int l;
        Square(const Square&); // Copy constructor
        Square& operator=(const Square&); // Copy assignment operator

    public:
        Square() : GeomFig(), l(5){};
        Square(int &x) : GeomFig(), l(x){};
        ~Square(){} // Declaring the destructor to avoid compiler generated destructor

        void area(){
            cout << "Area is " << l*l << "\n";
        }
        
        void perimeter(){
            cout << "Perimeter is " << 4*l << "\n";
        }
};