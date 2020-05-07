#include <string>
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

template <typename T>
string maxValue(vector<T> v) {
	T min = v[0];
	T max = v[0];
	string resul;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > max)
			max = v[i];
		if (v[i] < min)
			min = v[i];
	}
	cout << fixed << setprecision(2);

	resul.append(to_string(max));
	resul.push_back(' ');
	resul.append(to_string(min));
	return resul;
}


int main() {
	vector<float> v = { 1,3.6,8.3,1,2,9.8,5.0,4.1,10,6.2 };
	cout << "maximum and minimum : " << maxValue(v);
	return 0;

}