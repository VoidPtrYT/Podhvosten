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
			while (wstr[wcslen(wstr) - 1] == '\r' || wstr[wcslen(wstr) - 1] == '\n')
				wstr[wcslen(wstr) - 1] = '\0';
			std::wstring _wstr(wstr);
			
			std::size_t iPos = _wstr.find('@');
			while (iPos != std::wstring::npos)
			{
				_wstr[iPos] = '\n';
				iPos = _wstr.find('@');
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