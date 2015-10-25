#include <iostream>
#include <fstream>
//#include "LessParser.h"
#include "Tokenizer.h"
#include "Parser.h"
int	main(int argc, char **argv) 
{
	std::ifstream fs;
	//fs.open(argv[1], std::ios::in);
	fs.open("test1.less", std::ios::in);
	Tokenizer tokenizer = Tokenizer(fs);
	Parser lesparser = Parser(tokenizer);
	lesparser.printTree(lesparser.getRootNode());
	//lesparser.showTokens();
	return 0;
}
