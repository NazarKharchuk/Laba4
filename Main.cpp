#include "bmp.h"

int main() {
	string inputName, outputName;
	int times;
	cin >> inputName >> outputName >> times;
	bmp bmp_file;
	bmp_file.read_file(inputName);
	bmp_file.setTimes(times);
	bmp_file.change_img();
	bmp_file.write_file(outputName);
	cout << "Written result to " << outputName;
}