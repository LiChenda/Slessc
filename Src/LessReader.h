#pragma once
#ifndef __LESSREADER_H_
#define __LESSREADER_H_

#include <fstream>
#include <string>


class LessReader
{
public:
	LessReader(std::string filename);
	~LessReader();

private:
	std::string lesscontex;

};



#endif