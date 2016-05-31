#include "common.h"
#include <stdexcept>
#include <iostream>

int Uc2ToUtf8(
	const U_NIC* uc2arrray,
	size_t uc2len,
	U_TF8* utfdest,
	size_t utfspace) {
	try {
		if (uc2arrray == nullptr || utfdest == nullptr)
			throw std::runtime_error("Check your file source!");
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		abort();
	}

	const U_NIC* uc2pos = uc2arrray;
	const U_NIC* uc2end = uc2arrray + uc2len;

	U_TF8* utf8pos = utfdest;
	U_TF8* utf8end = utfdest + utfspace;
	while (uc2pos < uc2end && utf8pos < utf8end)
	{
		if (*uc2pos < 0x80)
		{
			*utf8pos++ = *uc2pos++;
		}
		else if (*uc2pos < 0x800)
		{
			if (utfspace < 2)
				break;
			*utf8pos++ = ((*uc2pos & 0x07C0) >> 6) | 0xc0;
			*utf8pos++ = (*uc2pos++ & 0x003F) | 0x80;
		}
		else
		{
			if (utfspace < 3)
				break;
			*utf8pos++ = ((*uc2pos & 0xF000) >> 12) | 0xE0;
			*utf8pos++ = ((*uc2pos & 0x0FC0) >> 6) | 0x80;
			*utf8pos++ = (*uc2pos++ & 0x003F) | 0x80;
		}
	}

	return (utf8pos - utfdest);
}