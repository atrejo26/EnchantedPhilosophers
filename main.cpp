#include <iostream>
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN   
#include "catch.hpp"

#include "point.h"
#include "line.h"

using namespace std;

//--
TEST_CASE("Point Implementation")  
{ 
	Point p(1.2, 1.4);

	REQUIRE(p.printString() == "X: 1.2, Y: 1.4"); 
}

TEST_CASE("Test 2")
{
	Point p1(2.0, 0.0);
	Point p2(3.0, 4.0);

	line l(p1, p2);


	REQUIRE(l.length() == 5.0);
}
TEST_CASE("Test 3")
{
	Point p1(2.0, 0.0);
	Point p2(3.0, 4.0);

	line l(p1, p2);



	REQUIRE(l.slope() == 4.0);
}

TEST_CASE("Test 4")
{
	Point p1(2.0, 0.0);
	Point p2(3.0, 4.0);

	line l(p1, p2);


	Point p3(2.5, 2.0);

	REQUIRE(l.midpoint() == p3.printString());
}

TEST_CASE("Test 5")
{
	Point p1(0.0, 0.0);
	Point p2(2.0, 2.0);

	line l(p1, p2);


	Point p3(-3.0, -3.0);

	REQUIRE(l.isOnLine(p3) == true);
}
TEST_CASE("Test 6")
{
	Point p1(0.0, 0.0);
	Point p2(3.0, 4.0);

	line l(p1, p2);

	l.extendLine(5.0);

	REQUIRE(l.printPoints() ==  "Line- Point 1: [X: X: -3.0, Y: -4.0], Point 2: [X: X: 6.0, Y: 8.0], Length: 15.0");
}


TEST_CASE("TEST 7"){
	Point p1(1.656, 1.4);

	p1.setX(p1.round1Place(p1.getX()));

	REQUIRE(p1.getX() == 1.7);

}

TEST_CASE("TEST 8"){
	Point p1(-1.656, 1.4);

	p1.setX(p1.round1Place(p1.getX()));

	REQUIRE(p1.getX() == -1.7);

}


TEST_CASE("TEST 9"){
	Point p1(-1.656, 1.4);

	cout << p1.printString() << endl;

	p1.setX(p1.round1Place(p1.getX()));

	REQUIRE(p1.getX() == -1.7);

}

TEST_CASE("Test 10"){
	Point p1(-10.656, 1.4);

	REQUIRE(p1.purifyStrOutput(p1.round1Place(p1.getX())) == "-10.7");
}