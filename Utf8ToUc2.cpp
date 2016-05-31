#include "Common.h"
#include <stdexcept>
#include <iostream>

int UtfToUc2(
	const U_TF8* utfarray,
	size_t utf8len,
	U_NIC* uc2dest,
	size_t uc2space) {

	try {
		if (utfarray == nullptr || uc2dest == nullptr)
			throw std::runtime_error("Check your file source");
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		abort();
	}
	const U_TF8* utf8pos = utfarray;
	const U_TF8* utf8end = utfarray + utf8len;

	U_NIC* uc2pos = uc2dest;
	U_NIC* uc2end = uc2dest + uc2space;
	while (utf8pos < utf8end && uc2pos < uc2end)
	{
		if (*utf8pos < 0x80)
		{
			*uc2pos++ = *utf8pos++;
		}
		else if ((*utf8pos & 0xF0) == 0xE0)
		{
			if (uc2space < 3)
				break;
			*uc2pos |= (*utf8pos++ & 0x0F) << 12;
			*uc2pos |= (*utf8pos++ & 0x3F) << 6;
			*uc2pos++ |= (*utf8pos++ & 0x3F);
		}
		else if ((*utf8pos & 0xF0) == 0xC0)
		{
			if (uc2space < 2)
				break;
			*uc2pos |= (*utf8pos++ & 0x1F) << 6;
			*uc2pos++ |= (*utf8pos++ & 0x3F);
		}
		else
			utf8pos++;
	}

	return (uc2pos - uc2dest);
}
