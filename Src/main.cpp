#include <iostream>
#include <fstream>
#include "LessParser.h"
int	main() 
{
	std::ifstream fs;
	fs.open("test1.less", std::ios::in);
	Tokenizer* fake = new Tokenizer(fs);
	LessParser lesparser((Tokenizer*)fake);
	lesparser.showTokens();
	return 0;
}