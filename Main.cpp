#include "bmp.h"

int main() {
	bmp bmp_file;
	bmp_file.read_file("bmp.bmp");
	bmp_file.change_img();
	bmp_file.write_file("out_bmp.bmp");
}