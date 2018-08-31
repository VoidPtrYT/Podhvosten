#include "TextProvider.h"

namespace Text
{
	TextProvider::TextProvider()
	{
		FILE* f = NULL;
		if (_wfopen_s(&f, PATH_TEXT, L"rb"))
		{
			MessageBox(NULL, ERROR_FILE, NULL, MB_ICONERROR);
			return;
		}
		wchar_t* wstr = (wchar_t*)calloc(SIZE_STR + 1, sizeof(wchar_t));

		while (!feof(f))
		{
			fgetws(wstr, SIZE_STR, f);
			while (wstr[wcslen(wstr) - 1] == RETURN_CARET
				|| wstr[wcslen(wstr) - 1] == NEW_STR)
				wstr[wcslen(wstr) - 1] = ZERO_SYMB;
			std::wstring _wstr(wstr);
			
			std::size_t iPos = _wstr.find(NEW_STR_ALT);
			while (iPos != std::wstring::npos)
			{
				_wstr[iPos] = NEW_STR;
				iPos = _wstr.find(NEW_STR_ALT);
			}

			this->text.push_back(_wstr);
		}
		free(wstr);
		fclose(f);
	}

	TextProvider::~TextProvider()
	{
		this->text.clear();
	}

	TextProvider* TextProvider::getInstance(void)
	{
		if (TextProvider::instance == nullptr)
			TextProvider::instance = new TextProvider();
		return TextProvider::instance;
	}
	std::wstring TextProvider::getStrById(std::size_t id) const
	{
		if (id >= this->text.size())
			return std::wstring(ERR_ID);
		return std::wstring(this->text[id]);
	}
}