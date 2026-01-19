#include "point.h"


Point::Point(double pointX, double pointY){
    setX(pointX);
    setY(pointY);
}

void Point::setX(double pointX){
    X = pointX;
}   

void Point::setY(double pointY){
    Y = pointY;
}


double Point::getX(){
    return X;
}

double Point::getY(){
    return Y;
}

string Point::printString(){
    return ("X: " + to_string(X).substr(0, 3) + ", Y: " + to_string(Y).substr(0, 3));
}