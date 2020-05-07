#pragma once
#include <list>
#include <iostream>
#include<iterator>
using namespace std; 
class Point {
	friend double dist(const Point& p1, const Point& p2); //calcula a distância entre p1 e p2
public:
	Point(double x, double y);    
	double getX() const;   // devolve coordenada x    
	double getY() const;   // devolve coordenada y
	// outros métodos da classe Point 
private:    double x, y;  // coordenadas do ponto 
}; 

	class Polygon {
	public:    Polygon();    
			   Polygon& addVertex(Point p);  // acrescenta vértice ao polígono    
			   Polygon& addVertex(Point p, size_t pos);  // acrescenta vértice na posição pos   
			   size_t getSize() const;   // devolve nº de lados do polígono = nº de vértices
			   Point getVertex(size_t pos) const; // devolve vértice na posição pos    
			   double mystery() const;  //  ver alínea c)    // outros métodos da classe Polygon 
	private:    list<Point> v;  // vértices do polígono 
	};