#include "line.h"
#include <cmath>

line::line(Point p1, Point p2)
: point1(p1.getX(),p1.getY()), point2(p2.getX(),p2.getY())
{
}
double line::length(){
    double tempX = 0;
    tempX = abs(point1.getX() - point2.getX());

    double tempY = 0;
    tempY = abs(point1.getY() - point2.getY());

    double length = 0;
    length = sqrt((pow(tempX, 2)) + (pow(tempY, 2) ));

    return length;
}
double line::slope(){
    double tempX = 0;
    tempX = (point1.getX() - point2.getX());

    double tempY = 0;
    tempY = (point1.getY() - point2.getY());

    double slope = 0;
    slope = tempY / tempX;
    return slope;
}
string line::midpoint(){
    
    double tempX = 0;
    tempX = abs(point1.getX() + point2.getX());

    double tempY = 0;
    tempY = abs(point1.getY() + point2.getY());

    Point midpoint = Point(tempX / 2, tempY / 2);

    return midpoint.printString();

}
void line::extendLine(double distanceExtend){

    double x = 0;
    double y = 0;
    if(point1.getX() == point2.getX() && point1.getY() == point1.getX()){
        x = distanceExtend;
        y = 0;
    }else{
        
        x = point2.getX() - point1.getX();
        x = (distanceExtend * x) / length();

        y = point2.getY() - point1.getY();
        y = (distanceExtend * y) / length();
    }


    

    //adjust y 
    //doesn't work for same points
    if(point1.getY() > point2.getY()){
        point1.setY(point1.getY() + y);
        point2.setY(point2.getY() - y);
    }
    else{
        point1.setY(point1.getY() - y);
        point2.setY(point2.getY() + y);
    }
    //adjust x
    if(point1.getX() > point2.getX()){
        point1.setX(point1.getX() + x);
        point2.setX(point2.getX() - x);
    }
    else{
        point1.setX(point1.getX() - x);
        point2.setX(point2.getX() + x);
    }




}
bool line::isOnLine(Point p3){
    
    line tempL(point1, p3);

    double yHigh = 0.0;
    double yLow = 0.0;

    if(slope() == tempL.slope()){
        if(point1.getY() > point2.getY()){
            yHigh = point1.getY();
            yLow = point2.getY();
        }else{
            yHigh = point2.getY();
            yLow = point1.getY();
        }
        
        if(yHigh >= p3.getY() && yLow <= p3.getY()){
            return true;
        }else{
            return false;
        }

    }else{
        return false;
    }




}
//Line- Point 1: [X: 1.2, Y: 3.4], Point 2: [X: 5.6, Y: 7.8], Length: 6.2
string line::printPoints(){
    string tempStr = "Line- Point 1: [X: " + point1.printString() 
    + "], Point 2: [X: " + point2.printString() + "], Length: " + point1.purifyStrOutput(point1.round1Place(length()));
    return tempStr;
}