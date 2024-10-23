/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Point.h"

 // for the declaration of DIMENSION
#include "utility.h"

// TODO: implement two constructors, setX, getX, setY, getY, read, write, checkRange.

class Point
{
public:

    Point() {
        x = 0;
        y = 0;
    }

    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }

    void setX(int xVal) {
        x = xVal;
    }

    int getX() {
        return x;
    }

    void setY(int yVal) {
        y = yVal;
    }

    int getY() {
        return y;
    }

    void read(istream& ins) {
        ins;
    }

    void write(ostream& outs) {
        outs << "(" << x << "," << y << ")";
    }

private:
    int x;
    int y;


    int checkRange(int val) {
        if (val >= 0 && val < DIMENSION) {
            return val;
        }
        else if (0 - val < val - (DIMENSION - 1)) {
            return 0;
        }
        else {
            return DIMENSION - 1;
        }
    }

};

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
