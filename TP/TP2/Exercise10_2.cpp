/* Generalize o programa da alínea a) por forma a tratar inteiros com um maior número de dígitos*/

#include <iostream>
#include<cmath>
using namespace std;
int main() {
	int num, reverse = 0, original;

	cout << "Number? ";
	cin >> num;

	original = num;

	while (num != 0) {
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}

	if (original == reverse)
		cout << "The number is a palindrome!";
	else
		cout << "The number is not a palindrome";

	return 0;
}
/*int main() {
	unsigned long long int n, first, last, length = 1, divider = 1;
	bool palindrome = true;
	
	cout << "Insert a number: ";
	cin >> n;

	unsigned long long int nCopy = n;

	while (nCopy /= 10) {
		length++;
	}

	while (length > 1) {
		first = n / pow(10, length - 1); 
		last = n % 10; 

		cout << first << ' ' << last << endl;
		
		if (first != last) {
			palindrome = false;
			break;
		}

		n -=  first * pow(10, length - 1);
		n /= 10;
		cout << n << endl;
		length -= 2;

		if (length == 0) {
			break;
		}
	}

	if (palindrome) {
		cout << "The number is palindromic.";
	}

	else {
		cout << "The number is not palindromic.";
	}

	return 0;
}*/