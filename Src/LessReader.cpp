#include "LessReader.h"
#include <iostream>

LessReader::LessReader(std::string filename)
{
	std::fstream fs;
	fs.open(filename, std::ios::in);

}

LessReader::~LessReader()
{
}
