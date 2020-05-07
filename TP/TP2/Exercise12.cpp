/*Repita o problema 2.11 por forma a que o utilizador possa especificar a precisão com que pretende o resultado, isto é, a máxima variação entre o valor 
da soma da série, entre duas iterações consecutivas. Note que a variação tanto pode ser positiva como negativa*/

#include <iostream>
#include <cmath>
using namespace std;
void sumSeriesPrecision(void) {
	/* 2.12 */
	unsigned int choice = 0;
	std::cout << "\nExercise 2.12\n";
	std::cout << "Select Series\nEnter 1 for series that generates PI\nEnter 2 for series that generates e\nEnter 3 for series that generates e^x\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	unsigned int n = 0;
	unsigned long long factorial = 1;
	double x = 0, precision = 0;
	double sum = 0, term = 0;
	std::cout << "Enter the precision (maximum variance between terms) (0 to disable): ";
	std::cin >> precision;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter n (number of terms): ";
	std::cin >> n;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	precision = fabs(precision);
	switch (choice) {
	case 1:
		for (unsigned int i = 0; i < n; i++) {
			if (precision == 0) {
				sum += ((i % 2 == 0) ? 1.0 : -1.0) * 4.0 / (2 * i + 1);
			}
			else {
				term = ((i % 2 == 0) ? 1.0 : -1.0) * 4.0 / (2 * i + 1);
				sum += (fabs(term - sum) <= precision) ? term : 0.0;
			}
		}
		break;
	case 2:
		for (unsigned int i = 0; i < n; i++) {
			factorial *= ((i == 0) ? 1 : i) % (1ULL << 63);
			if (precision == 0) {
				sum += factorial ? (1.0 / factorial) : 0;
			}
			else {
				term = factorial ? (1.0 / factorial) : 0;
				sum += (fabs(term - sum) <= precision) ? term : 0.0;
			}
		}
		break;
	case 3:
		std::cout << "Enter x: ";
		std::cin >> x;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		for (unsigned int i = 0; i < n; i++) {
			factorial *= ((i == 0) ? 1 : i) % (1ULL << 63);
			x *= (i <= 1) ? 1 : x;
			if (precision == 0) {
				sum += factorial ? (pow(-1, i) * ((i == 0) ? 1 : x) / factorial) : 0;
			}
			else {
				term = factorial ? (pow(-1, i) * ((i == 0) ? 1 : x) / factorial) : 0;
				sum += (fabs(term - sum) <= precision) ? term : 0.0;
			}
		}
		break;
	default:
		std::cout << "Invalid mode\n";
		return;
	}
	std::cout << ((choice == 1) ? "PI" : ((choice == 2) ? "e" : "e^x")) << " ~= " << sum << "\n";
}
int main() {
	return 0;
}