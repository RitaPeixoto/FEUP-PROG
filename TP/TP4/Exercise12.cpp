/*
Escreva uma função double executeOperation(string op) que tem como parâmetro uma string representando uma operação aritmética simples (soma, subracção, multiplicação ou divisão)
de dois números que podem ter ou não parte decimal e que devolve o resultado da operação (do tipo double). Por exemplo, se for executada a seguinte chamada à função 
executeOperation("12.3 + 5")ela deve devolver o valor 17.3. Sugestão: use stringstreams para extrair o valor dos operandos e do operador.
 */

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cctype>
#include <sstream>
using namespace std;

double executeOperation(std::string operation) {
	operation.erase(std::remove_if(operation.begin(), operation.end(), std::isspace), operation.end());

	std::vector<std::string> ops;
	bool control = true;
	size_t start, end;

	while (control) {

		start = operation.find_first_of("({[");
		end = operation.find_last_of(")}]");

		if (start == std::string::npos || end == std::string::npos) {
			if (start != end) // invalid operation
				return 0;

			control = false;
			ops.push_back(operation);
		}
		else {
			ops.push_back(operation.substr(0, start) + "x" + operation.substr(end + 1));
			operation = operation.substr(start + 1, end - start - 1);
		}
	}

	double result = 0, x = 0, y = 0;
	char op;
	std::stringstream ss;
	size_t pivot;

	for (size_t i = ops.size() - 1; i < ops.size(); i--) {

		pivot = ops.at(i).find_first_of("*/");
		while (pivot != std::string::npos) {
			start = ops.at(i).find_last_of("+-*/", pivot - 1);
			end = ops.at(i).find_first_of("+-*/", pivot + 1);

			if (start == std::string::npos)
				start = 0;
			else
				start++;
			if (end == std::string::npos)
				end = ops.at(i).size();

			ss << ops.at(i).substr(start, end - start);
			ss >> x >> op >> y;
			if (ss.fail())
				return 0;

			switch (op) {
			case '*':
				result = x * y;
				break;
			case '/':
				result = x / y;
				break;
			default:
				return 0;
			}

			ops.at(i).replace(start, end - start, std::to_string(result));
			std::stringstream().swap(ss);
			pivot = ops.at(i).find_first_of("*/");
		}

		pivot = ops.at(i).find_first_of("+-");
		while (pivot != std::string::npos) {

			if (pivot == 0) {
				start = 0;
				switch (ops.at(i).at(pivot)) {
				case '+':
					ops.at(i) = ops.at(i).substr(1);
					break;
				case '-':
					end = ops.at(i).find_first_of("+-", pivot + 1);
					if (end == std::string::npos)
						end = ops.at(i).size();

					std::cout << ops.at(i).substr(start, end - start) << "\n";
					ss << ops.at(i).substr(start, end - start);
					ss >> x >> op >> y;
					if (ss.fail())
						return 0;

					switch (op) {
					case '+':
						result = x + y;
						break;
					case '-':
						result = x - y;
						break;
					default:
						return 0;
					}
					break;
				default:
					return 0;
				}
			}
			else {

				start = ops.at(i).find_last_of("+-", pivot - 1);
				end = ops.at(i).find_first_of("+-", pivot + 1);

				if (start == std::string::npos)
					start = 0;
				else
					start++;
				if (end == std::string::npos)
					end = ops.at(i).size();

				ss << ops.at(i).substr(start, end - start);
				ss >> x >> op >> y;
				if (ss.fail())
					return 0;

				switch (op) {
				case '+':
					result = x + y;
					break;
				case '-':
					result = x - y;
					break;
				default:
					return 0;
				}
			}

			ops.at(i).replace(start, end - start, std::to_string(result));
			std::stringstream().swap(ss);
			pivot = ops.at(i).find_first_of("+-");
		}

		if (i == 0) {
			try {
				result = std::stod(ops.at(i));
			}
			catch (std::invalid_argument e) {
				return 0;
			}
			catch (std::out_of_range e) {
				return 0;
			}
		}
		else {
			ops.at(i - 1).replace(ops.at(i - 1).find('x'), 1, std::to_string(result));
		}
	}
	return result;
}

int main() {
	return 0;
}