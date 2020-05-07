﻿#pragma once
#include <vector>
#include<string>
#include<iostream>
#include <fstream>
#include<map>
#include "2017-2.h"
using namespace std;




//template< class T> alinea e
class Image{
public:   Image(size_t nLins = 0, size_t nCols = 0, int pixVal = 0); //nLins & nCols are the dimensions 
//  of the image; pixVal is the initial value of every pixel   
		  void setPixel(size_t lin, size_t col, int pixVal); // modifies the value of the pixel at (lin,col)
		  bool read(string fileName); // reads the image saved in file fileName , storing it in img ; //  returns true if sucessful, false otherwise    
		  Image getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const;                                // returns an image containing a rectangular region of img   // ... other methods 
		  int getPixel(size_t lin, size_t col) const;// 3a)
private:   
	vector < vector<int> > img; // image representation   // ... other attributes 
};