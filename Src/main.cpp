#include <iostream>
#include <fstream>
//#include "LessParser.h"
#include "Parser.h"
int	main() 
{
	std::ifstream fs;
	fs.open("test1.less", std::ios::in);
	//Tokenizer(fs);
	Parser lesparser = Parser(Tokenizer(fs));
	lesparser.printTree(lesparser.getRootNode());
	//lesparser.showTokens();
	return 0;
}