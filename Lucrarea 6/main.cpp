#include <iostream>
#include <memory>
#include "Rectangle.cpp"

using namespace std;

Rectangle* createRectangle(int &x, int &y){
    return new Rectangle(x, y);
}

static void cleanup(Rectangle *r){  
    r->~Rectangle();
    cout<<"The rectangle "<<r<<" has been deleted\n";
}

int main(){
    int x, y;
    cout<<"Enter rectangle width: ";
    cin>>x;
    cout<<"Enter rectangle length: ";
    cin>>y;
    shared_ptr<Rectangle> r1(createRectangle(x,y),cleanup);
    shared_ptr<Rectangle> r2;
    auto_ptr<Rectangle> r3(createRectangle(x,y));
    auto_ptr<Rectangle> r4;
    r2=r1; // both shared_ptr pointers point to the same object
    r4=r3; // only r4 points to the object
    
    // Class methods for both shared_ptr pointers
    r1->area();
    r2->area();
    r1->perimeter();
    r2->perimeter();

    cout<<endl;
    // Class methods for auto_ptr
    r4->area();
    r4->perimeter();
    // Calling the methods on r3 would lead to segmentation fault
    // r3->area();
    // r3->perimeter();
    return 0;
}