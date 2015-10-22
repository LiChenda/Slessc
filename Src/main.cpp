#include <iostream>
#include "LessParser.h"
int	main() 
{
	Tokenizer* fake = new Tokenizer();
	LessParser lesparser((Tokenizer*)fake);
	lesparser.showTokens();
	return 0;
}