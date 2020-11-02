#include <iostream>
#include "GeomFig.h"
using namespace std;

class Rectangle: public GeomFig{ 
    private:
        int l1,l2;
        
    public:
        // Copy constructor
        Rectangle(const Rectangle &r){
            cout << "Rectangle copy constructor\n";
            l1 = r.l1;
            l2 = r.l2;
        };
        // Copy assignment operator
        Rectangle& operator=(const Rectangle &r){
            cout << "Rectangle copy assignment operator\n";
            l1 = 1;
            l2 = 1;
            return *this;
        }; 
        // Default constructor in case no values are specified
        Rectangle() : GeomFig(), l1(5), l2(10){}; 
        Rectangle(int &x, int &y) : GeomFig(), l1(x), l2(y){}; // Constructor given with values

        void area(){
            cout << "Area is " << l1*l2 << "\n";
        }
        
        void perimeter(){
            cout << "Perimeter is " << 2*l1 + 2*l2 << "\n";
        }

        int getL1(){
            return l1;
        }

        int getL2(){
            return l2;
        }

        // Using a local static object for Rectangle to avoid using static non-local object
        Rectangle& rec(){
            static Rectangle rc;
            return rc;
        }
};