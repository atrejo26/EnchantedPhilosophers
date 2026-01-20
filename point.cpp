#include "point.h"
#include <iostream>

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
    return ("X: " + purifyStrOutput(round1Place(X)) + ", Y: " + purifyStrOutput(round1Place(Y)));
}
//-10.656 -- -106.56 -- -107.06 -- -107 -- -10.7
double Point::round1Place(double val){
    val *= 10;

    if(val > 0){
        val += .5;
    }else if(val == 0){
        return 0;
    }else{
        val -= .5;
    }

    int valRound = (int) val;

    double retVal = (double) valRound / 10;

    return retVal;
}

string Point::purifyStrOutput(double val){
    double tempVal = val;

    int places = 0;
    while(val > 1 || val < -1){
        val /= 10;
        places++;
    }

    val = tempVal;

    if(val == 0){
        return "0.0";
    }else if(val > 0){
        return to_string(val).substr(0, places + 2);
    }else{
        return to_string(val).substr(0, places + 3);
    }
}