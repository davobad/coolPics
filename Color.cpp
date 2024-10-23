/**
 * Color.cpp
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

#include "Color.h"
class Color {
public:
	Color() {
		red = 0;
		blue = 0;
		green = 0;
	}
	
	Color(int redVal, int greenVal, int blueVal) {
		red = redVal;
		green = greenVal;
		blue = blueVal;
	}

    void setRed(int redVal) {
        red = redVal;
    }

    int getRed() {
        return red;
    }

    void setGreen(int greenVal) {
        green = greenVal;
    }

    int getGreen() {
        return green;
    }

    void setBlue(int blueVal) {
        blue = blueVal;
    }

    int getBlue() {
        return blue;
    }

    void read(istream& ins) {
        ins;
    }

    void write(ostream& outs) {
        outs << red << " " << green << " " << blue;
    }
private: 
	int red;
	int green;
	int blue;


    int checkRange(int val) {
        if (val >= 0 && val <= 255) {
            return val;
        }
        else if(0 - val < val - 255) {
            return 0;
        }
        else {
            return 255;
        }
    }

};
 // TODO: implement first checkRange, then two constructors, setRed, getRed,
 //       setGreen, getGreen, setBlue, getBlue, read, write.



 // Your code goes above this line.
 // Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
	color.read(ins);
	return ins;
}

ostream& operator << (ostream& outs, Color color)
{
	color.write(outs);
	return outs;
}
