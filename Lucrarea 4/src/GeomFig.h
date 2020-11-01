#include <iostream>
using namespace std;

class GeomFig{

    private:
        GeomFig(const GeomFig&);
        GeomFig& operator=(const GeomFig&);

    public:
        GeomFig();

        void area();

        void perimeter();

    //Rectangle& rec();
};