#include "2017-3.h"
/*3c)  map<Date, vector<Image>> Esta estrutura de dados permite que a cada data possam corresponder várias imagens e que se possa aceder facilmente a uma determinada imagem a partir
da data correspondente.

e) cpp template class Image { 
public: void setPixel(size_t lin, size_t col, T pixVal); //...
private: vector <vector> img; // image representation // 
};

*/
Image Image::getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const {
	Image final(nLins, nCols,0);
	for (int y = 0; y < nCols; y++) {
		for (int x = 0; x < nLins; x++) {
			final.setPixel(y, x, img[x][y]);
		}
	}
	return final;
}

int main() {//3 d)
	map<Date, vector<Image>>data;
	Date inputDate;
	string filename;
	vector<Image> images;

	cout << "Insert a date: ";
	cin >> inputDate;
	while (cin >> filename && filename != "") {
		Image image;
		Image.read(filename);//considerar que esta implementada
		images.push_back(image);
	}

	data.insert(pair<Date, vector<Image>>(inputDate, images));
	return 0;

}