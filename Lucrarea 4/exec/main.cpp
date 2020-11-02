#include <iostream>
#include "../src/Rectangle.cpp"
#include "../src/Square.cpp"
using namespace std;

int main() {
    int l1,l2;
    cout<<"Enter first line of the rectangle ";
    cin>>l1;
    cout<<"Enter second line of the rectangle ";
    cin>>l2;

    Rectangle r1(l1,l2);
    Rectangle r2;
    Square s1;
    
    cout<<"-> Rectangle results with given numbers\n";
    r1.area();
    r1.perimeter();

    cout<<"-> Rectangle results with default constructor numbers\n";
    r2.area();
    r2.perimeter();

    Rectangle r3(r1);
    cout << "\n" << r3.getL1() << ", " << r3.getL2() << "\n";

    r3 = r2;
    cout << r3.getL1() << ", " << r3.getL2() << "\n";

    Square s2;
    // The next lines doen't compile as 
    // copy assignment operator and copy constructor are private
    /*
    s2(s1);
    s2 = s1; 
    */
}