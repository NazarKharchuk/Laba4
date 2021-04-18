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
	cout << "bmp_head.width is :" << bmp_head.width << endl;


	in_file.close();
}