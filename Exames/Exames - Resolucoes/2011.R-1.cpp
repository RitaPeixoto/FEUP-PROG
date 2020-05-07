#include "2011.R-1.h"



Point::Point(double x, double y ) {
	this->x = x;
	this->y = y;
}



//Point Polygon::getVertex(size_t pos) const {

//}

int main() {
	Polygon t; 
	Point p1(1,2), p2(2,3), p3(3,4);

	t.addVertex(p1).addVertex(p2).addVertex(p3);


	return 0;
}