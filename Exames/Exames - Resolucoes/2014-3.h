#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class Text {
public:   Text(string filename);    // other methods
		  bool existsWord(string word); // 'word' exists in the literary text? 
		  bool existsWord(string word,string &where);
		  string getAuthor() const; 
		  string getTitle() const;
		  vector<string> getText() const;
private:   string title;        // title of the literary text   
		   string author;       // author of the literary text
		  vector<string> text; // contents of the literary text, line by line
};