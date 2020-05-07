#pragma once
#include<vector>
#include<cmath>
using namespace std;

class Point {
	friend double dist(const Point& p1, const Point& p2); //calcula a distância entre p1 e p2
public:    Point();
		   Point(double x, double y);    
		   double getX() const;   // devolve coordenada x    
		   double getY() const;   // devolve coordenada y
		   // outros métodos da classe Point 
private:    double x, y;  // coordenadas do ponto 
}; 

class Polygon {
public:    Polygon();    
			void addVertex(Point p);  // acrescenta vértice ao polígono    
			size_t getSize() const;   // devolve nº de lados do polígono = nº de vértices
			Point getVertex(size_t num) const;    // outros métodos da classe Polygon 
private:    vector<Point> points;
		/* Todos os poligonos sao definidos pelas coordenadas dos seus vertices, cada vertice~´e um ponto (ou sjea um x e um y) logo como  
		a classe point oferece a possibilidade de representar um ponto faz-se um vetor de points */
	
	
	// A COMPLETAR com estrutura de dados para representar os vértices de um polígono
};