#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>
#include <exception>
#include <string>
#define SWAPBYTE(x)\
	((x & 0xff00)>>8) |\
	((x & 0x00ff)<<8)
//#ifdef DLL_EXPORTTAG
//#define DLL_EXPORT __declspec(dllexport)
//#else
//#define DLL_EXPORT __declspec(dllimport)
//#endif
#define DLL_EXPORT __declspec(dllexport)

typedef char U_GB;
typedef unsigned short U_NIC;
typedef unsigned char U_TF8;

DLL_EXPORT int Uc2ToUtf8(const U_NIC*, size_t, U_TF8*, size_t);
DLL_EXPORT int UtfToUc2(const U_TF8*, size_t, U_NIC*, size_t);
DLL_EXPORT int GbkToUtf8(const U_NIC*, size_t, U_TF8*, size_t);
DLL_EXPORT int TraditionGbkToUtf8(const U_NIC*, size_t, U_TF8*, size_t);
DLL_EXPORT int Utf8ToGbk(const U_TF8*, size_t, U_NIC*, size_t);
DLL_EXPORT int Utf8ToTraditionGbk(const U_TF8*, size_t, U_NIC*, size_t);
DLL_EXPORT void ToUpper(std::string&);
DLL_EXPORT void ToLower(std::string&);

DLL_EXPORT void InitializeCodeFormatTransformer();
#endif