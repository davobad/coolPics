/**
 * Circle.cpp
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

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;



Circle::Circle() {
    Point pt;
    int r = 0;
    Color color;
    center = pt;
    radius = r;
    color = color;
}

Circle::Circle(Point pt, int r, Color c) {
    center = pt;
    radius = r;
    color = c;
}

void Circle::setCenter(Point pt) {
    center = pt;
}
    
Point Circle::getCenter() {
    return center;
}

void Circle::setRadius(int r) {
    radius = r;
}

int Circle::getRadius() {
    return radius;
}

void Circle::setColor(Color c) {
    color = c;
}

Color Circle::getColor() {
    return color;
}

void Circle::read(istream& ins) {
    char junk;
    int x, y, red, green, blue;
    ins >> junk >> junk >> x >> junk >> y >> 
        junk >> radius >> red >> green >> blue;
}
 
void Circle::write(ostream& outs) {
    outs << "C (" << center.getX() << "," << center.getY() << ") " << radius << " " 
        << color.getRed() << " " << color.getGreen() << color.getBlue();
}


int Circle::checkRadius(int radius) {
    if (radius >= 0) {
        return radius;
    }
    else {
        return -radius;
    }
}


    /**
     * Helper functions for drawing triangle.
     */
    void plot8points(int x, int y, Color c, Graphics& drawer);
    void plot4points(int x, int y, Color c, Graphics& drawer);



// Don't change the implementations below!

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics& drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();

    while (x >= y)
    {
        plot8points(x, y, c, drawer);

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();

    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);

    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
