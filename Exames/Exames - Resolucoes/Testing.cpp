//#include <iostream> 
//#include <cstddef> 
//#include <string> 
//
//using namespace std;
//
//
//
//
//template <typename T>  // OR template <class T>  //suggestion: use typename 
//void printArray(ostream &out, const T data[], size_t count) {  
//	out << "[";  
//	for (size_t i = 0; i < count; i++)  {   
//		if (i > 0)    
//			out << ", ";   
//		out << data[i];  
//	}  
//	out << "]"; 
//}
//
//
//void main() {
//
//	int a[] = { 10, 20, 30, 40, 50 }; // an example of array initialization 
//
//	// call integer function-template specialization  
//	printArray(cout,a,5);  cout << endl; 
//
//	double b[] = { 1.1, 1.2, 1.3 };  // call double function-template specialization  
//	printArray (cout,b,3);  
//	cout << endl; 
//
//	string c[] = { "Mary", "John", "Fred" };  // call string function-template specialization 
//	printArray (cout,c,3);  
//	cout << endl; 
//}


//#include<string>
//#include<iostream>
//#include<vector>
//#include<map>
//#include<set>
//using namespace std;
//
//
//
//int main() {
//	map<string, int> ola;
//	vector<string> names = { "Rita", "Maria", "Rita", "Joana", "Rita" };
//	ola.insert(pair<string, int>("Rita", 1));
//	ola.insert(pair<string, int>("Joana", 2));
//
//	for (int i = 0; i < size(names); i++) {
//		map<string, int>::iterator it = ola.find(names[i]);
//		if (it != ola.end()) {
//			ola[names[i]] += 1;
//
//		}
//	}
//	cout << ola["Rita"];
//	int *p;
//	p = new int[5];
//	set<string> Number;
//
//	std::map<char, int> mymap;
//	std::map<char, int>::iterator it;
//
//	// insert some values:
//	mymap['a'] = 10;
//	mymap['b'] = 20;
//	mymap['c'] = 30;
//	mymap['d'] = 40;
//	mymap['e'] = 50;
//	mymap['f'] = 60;
//
//	it = mymap.find('b');
//	mymap.erase(it);                   // erasing by iterator
//
//	mymap.erase('c');                  // erasing by key
//
//	it = mymap.find('e');
//	mymap.erase(it, mymap.end());    // erasing by range
//
//	// show content:
//	for (it = mymap.begin(); it != mymap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//	return 0;
//}


#include<iostream>
#include<string>
#include<map>
#include<utility>
using namespace std;
int main() {
	string line(4, 'a');
	cout << line;



	char a = 'A', b= 'a';
	int i = (int)a;
	int s = (int)b;
	cout << a << endl << i << endl;
	cout << b << endl << s << endl;
	map<int, string> phone_user;
	phone_user.insert(pair<int, string>(1234, "Mary"));
	phone_user.insert(pair<int, string>(1234, "John"));
	phone_user.insert(pair<int, string>(2345, "Ann"));
	for (auto x : phone_user)
		cout << x.first << " - " << x.second << endl;

	return 0;

}
