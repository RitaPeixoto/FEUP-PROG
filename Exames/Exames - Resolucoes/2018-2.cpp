/* 
a) N�o � poss�vel fazer a declara��o �Ship s�, uma vez que, ao contr�rio da classe Board, o construtor desta classe n�o possui argumentos definidos por omiss�o. Ao ser feita a declara��o 
�Board b�, como n�o s�o especificados nenhuns par�metros, ser�o utilizados numLines = 10 e numColumns = 10, enquanto que no caso de Ship isso n�o seria poss�vel, pois n�o sendo especificado 
nenhum argumento (identifier, symbol, position, ...) na chamada do construtor, n�o h� nenhum valor que estes possam assumir.
*/

#include"2018-2.h"
#include <iostream>
Board::Board(size_t numLines, size_t numColumns) { //Exercise 2.b)
	vector<int> line;

	for (int y = 0; y < numLines; y++) {
		for (int x = 0; x < numColumns; x++)
			line.push_back(-1);

		board.push_back(line);
		line.clear();
	}

	this->numLines = numLines;
	this->numColumns = numColumns;
}



bool Board::canPutShip(Position pos, char dir, size_t size) { //2.c)
	switch (dir) { // TO DO
	case 'H': // TO DO: test if ship with length 'size' can be put at 'pos', in horizontal direction
		for (int i = pos.line; i < size; i++)
			if (i < board.size() && board[pos.col][i] != -1)
				return false;

	case 'V': // TO DO, just this line: test if ship ... can be put in vertical direction
		for (int i = pos.col; i < size; i++)
			if (i < board.size() && board[i][pos.line] != -1)
				return false;

		// DONE. This piece of code was correctly implemented but was carelessly erased �
	}

	return true;
}

bool Board::putShip(const Ship& s) { // 2 d)
	Position pos = s.pos();
	char dir = s.dir();
	size_t size = s.size();

	if (canPutShip(pos, dir, size)) {
		ships.push_back(s);

		switch (dir) {
		case 'H':
			for (int i = pos.line; i < size; i++)
				board[pos.col][i] = s.id();

		case 'V':
			for (int i = pos.line; i < size; i++)
				board[i][pos.line] = s.id();
		}

		return true;
	}

	return false;
}

void create10x20Board() { //2 e)
	Board b(10, 20);
	unsigned int identifier;
	char symbol, direction;
	Position position;
	size_t size;

	cin >> identifier >> symbol >> position.col >> position.line >> direction >> size;

	Ship s(identifier, symbol, position, direction, size);

	try {
		if (!b.putShip(s))
			throw "Can't put ship!";

		else
			b.putShip(s);
	}

	catch (string s) {
		cerr << s;
	}
}