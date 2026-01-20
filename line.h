#include "point.h"

class line
{
public:
    line(Point p1, Point p2);
    double length();
    double slope();

    string midpoint();
    void extendLine(double distanceExtend);

    bool isOnLine(Point p3);

    string printPoints();
    
private:
    Point point1;
    Point point2;

};
