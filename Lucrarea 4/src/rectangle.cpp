#include <iostream>
using namespace std;

class Rectangle{

private:
    int l1,l2;

public:
    Rectangle() : l1(5), l2(10){};
    Rectangle(int &x, int &y) : l1(x), l2(y){};

Rectangle& rec(){
    static Rectangle rc;
    return rc;
}
};