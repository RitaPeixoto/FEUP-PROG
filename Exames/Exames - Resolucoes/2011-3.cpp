#include"2011-3.h"



double Point::getX() const {
	return x;
}
double Point::getY() const {
	return y;
}



/*alinea 3a) ----- é utilizado o qualificativo friend para poder aceder aos parametros privados da classe point*/
double dist(const Point& p1, const Point& p2) {
	double x1, x2, y1, y2;
	double result;
	x1 = p1.getX();
	x2 = p2.getX();
	y1 = p1.getY();
	y2 = p2.getY();

	result = pow((x1 - x2), 2) + pow((y1 - y2), 2);
	result = sqrt(result);

	return result;

}



size_t Polygon::getSize() const {
	return size(points);
}

void Polygon::addVertex(Point p) {
	points.push_back(p);
}



int main() {
	Point p1(0, 1), p2(1, 1), p3(1, 0);
	Polygon triangle;

	triangle.addVertex(p1);
	triangle.addVertex(p2);
	triangle.addVertex(p3);



}