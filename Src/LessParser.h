#pragma once
#ifndef __LESSPARSER_H_
#define __LESSPARSER_H_

#include "Tokenizer_fake.h"

class LessParser 
{
public:
	LessParser(Tokenizer* tokenizer);
	~LessParser();
	void showTokens();
private:
	Tokenizer* m_tokenizer;
};



#endif 