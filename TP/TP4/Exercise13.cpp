/*Desenvolver um programa que ordene os nomes de um conjunto de pessoas contidos num ficheiro de texto. guardando o resultado noutro ficheiro de texto. 
O nome do ficheiro original, com a extensão .txt, deve ser indicado pelo utilizador (ex: names.txt); o nome do ficheiro resultante deve ser igual ao do ficheiro original, 
acrescentando a string "_sorted" e mantendo a extensão (ex: names_sorted.txt). */
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
/**
 * Allows user to input a file to sort it
 * Sorted files doesn't override original file
 *
 * @brief sorts file given by user
 */

 /**
  * Sorts an vector of strings in ascending order
  *
  * @overload void quickSort(std::vector<int> &v, size_t start, size_t end)
  */
  /**
   * Swaps two elements on the vector
   *
   * @overload void swap(std::vector<std::string> &v, size_t i, size_t j)
   */
void swap(std::vector<std::string> &v, size_t i, size_t j) {
	std::string aux = v.at(i);
	v.at(i) = v.at(j);
	v.at(j) = aux;
}

  /**
   * Creates two partitions, rightmost has the small values, rightmost high values
   * Pivot is chosen randomly
   *
   * @brief splits interval into two partitions
   * @param v vector of strings
   * @param start start position of the interval to split
   * @param end stop position of the interval to split
   * @return the index of the separator of partitions
   */
size_t partition(std::vector<std::string> &v, size_t start, size_t end) {

	size_t pivotIndex = (int)(start + ((double)rand() / RAND_MAX) * (end + 1 - start));
	std::string pivot = v.at(pivotIndex);
	size_t i = start - 1;
	size_t j = end + 1;

	while (true) {

		i++;
		while (i < end && v.at(i).compare(pivot) == -1)
			i++;

		j--;
		while (j > start && v.at(j).compare(pivot) == 1)
			j--;

		if (i < j)
			swap(v, i, j);
		else
			return j;
	}
}





void quickSort(std::vector<std::string> &v, size_t start, size_t end) {
	if (start < end) {
		size_t pivot = partition(v, start, end);
		quickSort(v, start, pivot);
		quickSort(v, pivot + 1, end);
	}
}



int sortFile(std::string file);


void runFiles(void) {
	/* 4.13 */
	std::cout << "\nExercise 4.13\n";
	std::cout << "Sorting file\nEnter the filename(or path to file): ";
	std::string path;
	std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
	std::getline(std::cin, path, '\n');
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	if (sortFile(path)) {
		std::cout << "Invalid file\n";
		return;
	}

	std::cout << "Finished\n";
}

/**
 * Creates a new file derived from original file
 * New file is the content of original file sorted
 *
 * @brief sorts file in lexicographically order
 * @param filename path to the file to sort
 * @return 0 if successful process, otherwise -1
 */
int sortFile(std::string file) {

	std::ifstream inFile;
	inFile.open(file, std::ios::in);

	if (!inFile.is_open() || inFile.fail() || inFile.eof())
		return -1;

	size_t sep = file.find_last_of("\\/");
	std::string filename;
	std::string path;
	if (sep == std::string::npos) {
		filename = file;
		path = "";
		sep = filename.find_last_of(".");
		if (sep != std::string::npos) {
			filename = filename.substr(0, sep);
		}
	}
	else {
		path = file.substr(0, sep);
		filename = file.substr(sep + 1);
		sep = filename.find_last_of(".");
		if (sep != std::string::npos) {
			filename = filename.substr(0, sep);
		}
	}

	std::vector < std::string > lines;
	std::string line;
	while (!inFile.eof()) {
		std::getline(inFile, line, '\n');
		lines.push_back(line);
	}
	inFile.close();
	quickSort(lines, 0, lines.size() - 1);
	filename += "_sorted.txt";

	std::ofstream outfile;
	outfile.open(path + filename, std::ios::out);
	for (size_t i = 0; i < lines.size(); i++)
		outfile << lines.at(i) << "\n";

	outfile.close();

	return 0;
}