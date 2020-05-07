#pragma once
#include <list>
#include <iostream>
#include<iterator>
using namespace std; 
class Point {
	friend double dist(const Point& p1, const Point& p2); //calcula a dist�ncia entre p1 e p2
public:
	Point(double x, double y);    
	double getX() const;   // devolve coordenada x    
	double getY() const;   // devolve coordenada y
	// outros m�todos da classe Point 
private:    double x, y;  // coordenadas do ponto 
}; 

	class Polygon {
	public:    Polygon();    
			   Polygon& addVertex(Point p);  // acrescenta v�rtice ao pol�gono    
			   Polygon& addVertex(Point p, size_t pos);  // acrescenta v�rtice na posi��o pos   
			   size_t getSize() const;   // devolve n� de lados do pol�gono = n� de v�rtices
			   Point getVertex(size_t pos) const; // devolve v�rtice na posi��o pos    
			   double mystery() const;  //  ver al�nea c)    // outros m�todos da classe Polygon 
	private:    list<Point> v;  // v�rtices do pol�gono 
	};