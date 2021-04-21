#include "bmp.h"

int main() {
	string inputName, outputName;
	int times;
	bool T;
	cin >> inputName >> outputName >> times>>T;
	bmp bmp_file;
	bmp_file.read_file(inputName);
	bmp_file.setTimes(times);
	bmp_file.change_img(T);
	bmp_file.write_file(outputName);
	cout << "Written result to " << outputName;
}