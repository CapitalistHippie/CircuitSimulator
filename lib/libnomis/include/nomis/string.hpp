#ifndef _NOMIS_STRING_HPP_
#define _NOMIS_STRING_HPP_

#include <string>
#include <cctype>

namespace nomis
{
	inline int istrcmp(const char* a, const char* b) noexcept
	{
		for (;; a++, b++)
		{
			int d = tolower(*a) - tolower(*b);
			if (d != 0 || !*a)
				return d;
		}
		return 0;
	}

	inline std::string& ltrim(std::string& string, const char* characters)
	{
		string.erase(0, string.find_first_not_of(characters));
	    return string;
	}

	inline std::string& rtrim(std::string& string, const char* characters)
	{
		string.erase(string.find_last_not_of(characters) + 1);
	    return string;
	}

	inline std::string& trim(std::string& string, const char* characters)
	{
	    return ltrim(rtrim(string, characters), characters);
	}

	inline std::string ltrim_copy(std::string string, const char* characters)
	{
	    return ltrim(string, characters);
	}

	inline std::string rtrim_copy(std::string string, const char* characters)
	{
	    return rtrim(string, characters);
	}

	inline std::string trim_copy(std::string string, const char* characters)
	{
	    return trim(string, characters);
	}
}

#endif // _NOMIS_STRING_HPP_
