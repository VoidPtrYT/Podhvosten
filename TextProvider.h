#pragma once
#include "GlobalHeader.h"
#include <vector>
#include <string>
#include <stdio.h>

#define PATH_TEXT L"..//src//text.ptf"
#define ERR_ID L"Wrong id of text!"
#define ERROR_FILE L"Can't found file with text!!! Try reinstall game!"
#define SIZE_STR 1024
#define RETURN_CARET '\r'
#define NEW_STR '\n'
#define ZERO_SYMB '\0'
#define NEW_STR_ALT '@'

namespace Text
{
	class TextProvider
	{
		std::vector<std::wstring> text;
		TextProvider();
		static TextProvider* instance;
	public:
		~TextProvider();
		static TextProvider* getInstance(void);
		std::wstring getStrById(std::size_t id) const;
	};
}
