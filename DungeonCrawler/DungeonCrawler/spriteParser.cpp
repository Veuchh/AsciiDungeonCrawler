#include <Windows.h>
#include <fstream>
#include "SpriteParser.h"

using namespace std;

SPRITE_DATA* SPRITE_PARSER::ParseSprite(string spriteName)
{
	ifstream ifs;

	ifs.open(spriteName, ios::binary);
	
	if (!ifs)
	{
		system("pause");
	}

	ifs.seekg(2);

	int file_size;
	ifs.read((char*)&file_size, sizeof(int));

	ifs.seekg(10);
	int beg;
	ifs.read((char*)&beg, sizeof(int));

	ifs.seekg(18);
	int columns;
	ifs.read((char*)&columns, sizeof(int));

	ifs.seekg(22);
	int rows;
	ifs.read((char*)&rows, sizeof(int));

	int image_size = 0;
	image_size = 3 * columns * rows;

	ifs.seekg(beg);

	unsigned char R, G, B, A;

	WORD** pixels = new WORD * [columns];

	for (size_t i = 0; i < columns; i++)
	{
		pixels[i] = new WORD[rows];

		//ofs << "Column " << i << " adding an array of size " << rows << "\n";
	}

	for (int i = 0; i < image_size / 3; i++)
	{
		ifs.read((char*)&B, sizeof(unsigned char));
		ifs.read((char*)&G, sizeof(unsigned char));
		ifs.read((char*)&R, sizeof(unsigned char));
		ifs.read((char*)&A, sizeof(unsigned char));

		WORD word = 0;

		if (A == 0)
		{
			word = 0x1000;
		}
		else
		{
			if (R != 0)
				word = word | 0X0004;

			if (G != 0)
				word = word | 0X0002;

			if (B != 0)
				word = word | 0X0001;

			if (R == 255 || G == 255 || B == 255)
				word = word | 0X0008;
		}

		/*
		ofs << std::dec << " R: " << int(R) << " G: " << int(G) << " B: " << int(B) << "  position in file: " << ifs.tellg()
			<< " COLUMN : " << (i % rows) 
			<< " ROW :" << ((int)i / rows) 
			<< "\r\n";
		*/

		//pixels[rowIndex][columnIndex]
		pixels[i % columns][rows - ((int)i / columns) - 1] = word;
	}

	SPRITE_DATA* spriteData = new SPRITE_DATA(pixels, columns, rows);

	return spriteData;
}
