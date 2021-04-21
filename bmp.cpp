#include "bmp.h"

void bmp::read_file(string file_name) {
	ifstream in_file(file_name, ios::binary);
	if (!in_file.is_open()) {
		cout << "File open error!(\n";
		return;
	}

	in_file.read((char*)&bmp_head.id[0], sizeof(bmp_head.id[0]));
	in_file.read((char*)&bmp_head.id[1], sizeof(bmp_head.id[1]));
	//cout << "b/m " << bmp_head.id[0] << " " << bmp_head.id[1] << endl;
	in_file.read((char*)&bmp_head.filesize, sizeof(bmp_head.filesize));
	//cout << "bmp_head.filesize is :" << bmp_head.filesize <<endl;
	in_file.read((char*)&bmp_head.reserved[0], sizeof(bmp_head.reserved[0]));
	in_file.read((char*)&bmp_head.reserved[1], sizeof(bmp_head.reserved[1]));
	//cout << "reserved is: " << bmp_head.reserved[0] << " " << bmp_head.reserved[1] << endl;
	in_file.read((char*)&bmp_head.headersize, sizeof(bmp_head.headersize));
	//cout << "bmp_head.headersize is :" << bmp_head.headersize << endl;
	in_file.read((char*)&bmp_head.infoSize, sizeof(bmp_head.infoSize));
	//cout << "bmp_head.infoSize is :" << bmp_head.infoSize << endl;
	in_file.read((char*)&bmp_head.width, sizeof(bmp_head.width));
	//cout << "bmp_head.width is :" << bmp_head.width << endl;
	in_file.read((char*)&bmp_head.depth, sizeof(bmp_head.depth));
	//cout << "bmp_head.depth is :" << bmp_head.depth << endl;
	in_file.read((char*)&bmp_head.biPlanes, sizeof(bmp_head.biPlanes));
	//cout << "bmp_head.biPlanes is :" << bmp_head.biPlanes << endl;
	in_file.read((char*)&bmp_head.bits, sizeof(bmp_head.bits));
	//cout << "bmp_head.bits is :" << bmp_head.bits << endl;
	in_file.read((char*)&bmp_head.biCompression, sizeof(bmp_head.biCompression));
	//cout << "bmp_head.biCompression is :" << bmp_head.biCompression << endl;
	in_file.read((char*)&bmp_head.biSizeImage, sizeof(bmp_head.biSizeImage));
	//cout << "bmp_head.biSizeImage is :" << bmp_head.biSizeImage << endl;
	in_file.read((char*)&bmp_head.biXPelsPerMeter, sizeof(bmp_head.biXPelsPerMeter));
	//cout << "bmp_head.biXPelsPerMeter is :" << bmp_head.biXPelsPerMeter << endl;
	in_file.read((char*)&bmp_head.biYPelsPerMeter, sizeof(bmp_head.biYPelsPerMeter));
	//cout << "bmp_head.biYPelsPerMeter is :" << bmp_head.biYPelsPerMeter << endl;
	in_file.read((char*)&bmp_head.biClrUsed, sizeof(bmp_head.biClrUsed));
	//cout << "bmp_head.biClrUsed is :" << bmp_head.biClrUsed << endl;
	in_file.read((char*)&bmp_head.biClrImportant, sizeof(bmp_head.biClrImportant));
	//cout << "bmp_head.biClrImportant is :" << bmp_head.biClrImportant << endl;

	in_matr = new PIXELDATA * [bmp_head.depth];
	for (int n = 0; n < bmp_head.depth; n++) {
		in_matr[n] = new PIXELDATA[bmp_head.width];
	}

	int8_t pix;
	for (int i = 0; i < bmp_head.depth; i++) {
		for (int j = 0; j < bmp_head.width; j++) {
			in_file.read((char*)&in_matr[i][j].redComponent, sizeof(in_matr[i][j].redComponent));
			in_file.read((char*)&in_matr[i][j].greenComponent, sizeof(in_matr[i][j].greenComponent));
			in_file.read((char*)&in_matr[i][j].blueComponent, sizeof(in_matr[i][j].blueComponent));
		}
		for (int n = 0; n < (bmp_head.width % 4); n++) {
			in_file.read((char*)& pix, sizeof(pix));
		}
	}


	in_file.close();
}

void bmp::write_file(string file_name) {
	ofstream out_file(file_name, ios::binary);
	if (!out_file.is_open()) {
		cout << "File open error!(\n";
		return;
	}

	int32_t new_width = bmp_head.width * times;
	cout << "New width: " << new_width <<endl;
	int32_t new_depth = bmp_head.depth * times;
	cout << "New depth: " << new_depth << endl;
	int32_t new_filesize = bmp_head.headersize + (new_width * new_depth * 3) + (new_width % 4) * new_depth;
	cout << "New size: " << new_filesize << endl;

	out_file.write((char*)&bmp_head.id[0], sizeof(bmp_head.id[0]));
	out_file.write((char*)&bmp_head.id[1], sizeof(bmp_head.id[1]));
	out_file.write((char*)&new_filesize, sizeof(new_filesize));
	out_file.write((char*)&bmp_head.reserved[0], sizeof(bmp_head.reserved[0]));
	out_file.write((char*)&bmp_head.reserved[1], sizeof(bmp_head.reserved[1]));
	out_file.write((char*)&bmp_head.headersize, sizeof(bmp_head.headersize));
	out_file.write((char*)&bmp_head.infoSize, sizeof(bmp_head.infoSize));
	out_file.write((char*)&new_width, sizeof(new_width));
	out_file.write((char*)&new_depth, sizeof(new_depth));
	out_file.write((char*)&bmp_head.biPlanes, sizeof(bmp_head.biPlanes));
	out_file.write((char*)&bmp_head.bits, sizeof(bmp_head.bits));
	out_file.write((char*)&bmp_head.biCompression, sizeof(bmp_head.biCompression));
	out_file.write((char*)&bmp_head.biSizeImage, sizeof(bmp_head.biSizeImage));
	out_file.write((char*)&bmp_head.biXPelsPerMeter, sizeof(bmp_head.biXPelsPerMeter));
	out_file.write((char*)&bmp_head.biYPelsPerMeter, sizeof(bmp_head.biYPelsPerMeter));
	out_file.write((char*)&bmp_head.biClrUsed, sizeof(bmp_head.biClrUsed));
	out_file.write((char*)&bmp_head.biClrImportant, sizeof(bmp_head.biClrImportant));

	int8_t pix;

	for (int i = 0; i < bmp_head.depth * times; i++) {
		for (int j = 0; j < bmp_head.width * times; j++) {
			out_file.write((char*)&out_matr[i][j].redComponent, sizeof(out_matr[i][j].redComponent));
			out_file.write((char*)&out_matr[i][j].greenComponent, sizeof(out_matr[i][j].greenComponent));
			out_file.write((char*)&out_matr[i][j].blueComponent, sizeof(out_matr[i][j].blueComponent));
		}
		for (int n = 0; n < ((bmp_head.width*times) % 4); n++) {
			out_file.write((char*)&pix, sizeof(pix));
		}
	}

	out_file.close();
}

<<<<<<< Updated upstream
bmp::~bmp() {
	for (int n = 0; n < bmp_head.depth; n++) {
		delete [] in_matr[n];
	}
	delete[]in_matr;
	for (int n = 0; n < bmp_head.depth * times; n++) {
		delete[] out_matr[n];
	}
	delete[]out_matr;
}

void bmp::change_img() {
	cout << "Enlarging image " << times << " times...";
	out_matr = new PIXELDATA * [bmp_head.depth * times];
	for (int n = 0; n < bmp_head.depth * times; n++) {
		out_matr[n] = new PIXELDATA[bmp_head.width * times];
	}
	for (int i = 0; i < bmp_head.depth; i++) {
		for (int j = 0; j < bmp_head.width; j++) {
			for (int t = 0; t < times; t++) {
				out_matr[i * times + t][j * times] = in_matr[i][j];
				for (int h = 0; h < times; h++) {
					out_matr[i * times + t][j * times + h] = out_matr[i * times + t][j * times];
				}
			}
		}
	}
	cout << "Done!" << endl;
}

void bmp::setTimes(int X) 
{
	times = X;
}

=======
RGBQUAD* rgbInfo = new RGBQUAD[fileInfoHeader.biHeight];

for (unsigned int i = 0; i < fileInfoHeader.depth; i++) {
	rgbInfo[i] = new RGBQUAD[fileInfoHeader.width];
}

// чтение
unsigned int bufer;

for (unsigned int i = 0; i < fileInfoHeader.depth; i++) {
	for (unsigned int j = 0; j < fileInfoHeader.width; j++) {
		read(fileStream, bufer, fileInfoHeader.biBitCount / 8);

		rgbInfo[i][j].rgbRed = bitextract(bufer, fileInfoHeader.biRedMask);
		rgbInfo[i][j].rgbGreen = bitextract(bufer, fileInfoHeader.biGreenMask);
		rgbInfo[i][j].rgbBlue = bitextract(bufer, fileInfoHeader.biBlueMask);
		rgbInfo[i][j].rgbReserved = bitextract(bufer, fileInfoHeader.biAlphaMask);
	}
	fileStream.seekg(linePadding, std::ios_base::cur)
>>>>>>> Stashed changes
