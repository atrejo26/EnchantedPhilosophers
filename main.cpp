#include <iostream>
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN   
#include "catch.hpp"

#include "point.h"

using namespace std;

//--
TEST_CASE("Point Implementation")  
{ 
	Point p(1.2, 1.4);

	REQUIRE(p.printString() == "X: 1.2, Y: 1.4"); 
}