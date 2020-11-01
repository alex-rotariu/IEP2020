#include <iostream>
#include "../src/rectangle.cpp"
using namespace std;

int main() {
    int l1,l2;
    cout<<"Enter first line of the rectangle";
    cin>>l1;
    cout<<"Enter second line of the rectangle";
    cin>>l2;

    Rectangle r(l1,l2);
    Rectangle r1;

    cout<<"Results with introduced numbers\n";
    r.area();
    r.perimeter();

    cout<<"Results with default numbers\n";
    r.area();
    r.perimeter();
}