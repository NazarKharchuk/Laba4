#include "bmp.h"

void bmp::read_file(string file_name) {
	ifstream in_file(file_name, ios::binary);
	if (!in_file.is_open()) {
		cout << "File open error!(\n";
		return;
	}

	in_file.read((char*)&bmp_head.id[0], sizeof(bmp_head.id[0]));
	in_file.read((char*)&bmp_head.id[1], sizeof(bmp_head.id[1]));
	cout << "b/m " << bmp_head.id[0] << " " << bmp_head.id[1] << endl;
	in_file.read((char*)&bmp_head.filesize, sizeof(bmp_head.filesize));
	cout << "bmp_head.filesize is :" << bmp_head.filesize <<endl;
	in_file.read((char*)&bmp_head.reserved[0], sizeof(bmp_head.reserved[0]));
	in_file.read((char*)&bmp_head.reserved[1], sizeof(bmp_head.reserved[1]));
	cout << "reserved is: " << bmp_head.reserved[0] << " " << bmp_head.reserved[1] << endl;
	in_file.read((char*)&bmp_head.headersize, sizeof(bmp_head.headersize));
	cout << "bmp_head.headersize is :" << bmp_head.headersize << endl;
	in_file.read((char*)&bmp_head.infoSize, sizeof(bmp_head.infoSize));
	cout << "bmp_head.infoSize is :" << bmp_head.infoSize << endl;
	in_file.read((char*)&bmp_head.width, sizeof(bmp_head.width));
	cout << "bmp_head.width is :" << bmp_head.width << endl;
	in_file.read((char*)&bmp_head.depth, sizeof(bmp_head.depth));
	cout << "bmp_head.depth is :" << bmp_head.depth << endl;
	in_file.read((char*)&bmp_head.biPlanes, sizeof(bmp_head.biPlanes));
	cout << "bmp_head.biPlanes is :" << bmp_head.biPlanes << endl;
	in_file.read((char*)&bmp_head.bits, sizeof(bmp_head.bits));
	cout << "bmp_head.bits is :" << bmp_head.bits << endl;
	in_file.read((char*)&bmp_head.biCompression, sizeof(bmp_head.biCompression));
	cout << "bmp_head.biCompression is :" << bmp_head.biCompression << endl;
	in_file.read((char*)&bmp_head.biSizeImage, sizeof(bmp_head.biSizeImage));
	cout << "bmp_head.biSizeImage is :" << bmp_head.biSizeImage << endl;
	in_file.read((char*)&bmp_head.biXPelsPerMeter, sizeof(bmp_head.biXPelsPerMeter));
	cout << "bmp_head.biXPelsPerMeter is :" << bmp_head.biXPelsPerMeter << endl;
	in_file.read((char*)&bmp_head.biYPelsPerMeter, sizeof(bmp_head.biYPelsPerMeter));
	cout << "bmp_head.biYPelsPerMeter is :" << bmp_head.biYPelsPerMeter << endl;
	in_file.read((char*)&bmp_head.biClrUsed, sizeof(bmp_head.biClrUsed));
	cout << "bmp_head.biClrUsed is :" << bmp_head.biClrUsed << endl;
	in_file.read((char*)&bmp_head.biClrImportant, sizeof(bmp_head.biClrImportant));
	cout << "bmp_head.biClrImportant is :" << bmp_head.biClrImportant << endl;


	in_file.close();
}