#pragma once
#include <string>


using namespace std;

class Point
{
    public:
        Point(double pointX, double pointY);

        void setX(double pointX);
        void setY(double pointY);

        double getX();
        double getY();

        string printString();

    private:
        double X;
        double Y;

};