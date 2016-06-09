#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>
#include <exception>
#include <string>
#define SWAPBYTE(x)\
	((x & 0xff00)>>8) |\
	((x & 0x00ff)<<8)

#if defined(_WIN32) && defined(_MSC_VER)

#if defined (CC_DLL_EXPORT_BUILD)
#define CC_DLL_EXPORT __declspec(dllexport)
#else
#ifdef CC_LIB_BUILD //静态库
#define CC_DLL_EXPORT
#else
#define CC_DLL_EXPORT __declspec(dllimport)
#endif
#endif

#endif

typedef char U_GB;
typedef unsigned short U_NIC;
typedef unsigned char U_TF8;

//************************************
// @Method:    Uc2ToUtf8
// @Returns:   int 返回 转换后的字符串长度
// @Parameter: uc2Array unicode16源字符串
// @Parameter: uc2Len 源字符串长度
// @Parameter: utf8Buf utf8字符串存放buf
// @Parameter: utf8BufSize utf8字符串buf大小
// @Brief:
//************************************
CC_DLL_EXPORT int Uc2ToUtf8(const U_NIC* uc2Array, size_t uc2Len, U_TF8* utf8Buf, size_t utf8BufSize);
//************************************
// @Method:    UtfToUc2
// @Returns:   int 返回转换后的字符串长度
// @Parameter: utf8Array 源utf8字符串
// @Parameter: utf8Len 源utf8字符串长度
// @Parameter: uc2Buf uc2字符串存放缓冲
// @Parameter: uc2BufSize 存放缓冲区大小
// @Brief:
//************************************
CC_DLL_EXPORT int UtfToUc2(const U_TF8* utf8Array, size_t utf8Len, U_NIC* uc2Buf, size_t uc2BufSize);
//************************************
// @Method:    GbkToUtf8
// @Returns:   int 转换后的字符串长度
// @Parameter: gbkArray 源gbk字符串
// @Parameter: gbkArrayLen 源gbk字符串长度
// @Parameter: utf8Buffer utf8存放缓冲
// @Parameter: utf8BufferSize utf8存放缓冲大小
// @Brief:
//************************************
CC_DLL_EXPORT int GbkToUtf8(const U_NIC* gbkArray, size_t gbkArrayLen, U_TF8* utf8Buffer, size_t utf8BufferSize);
//************************************
// @Method:    TraditionGbkToUtf8
// @Returns:   int 转换后字符串长度
// @Parameter: traGbkArray 源繁体中文字符串
// @Parameter: arrayLen 源字串长度
// @Parameter: utf8Buffer utf8存储区
// @Parameter: utf8BufferSize utf8存储缓冲大小
// @Brief:
//************************************
CC_DLL_EXPORT int TraditionGbkToUtf8(const U_NIC* traGbkArray, size_t arrayLen, U_TF8* utf8Buffer, size_t utf8BufferSize);
//************************************
// @Method:    Utf8ToGbk
// @Returns:   int 返回转换后字符串长度
// @Parameter: utf8SrcArray utf8源字串
// @Parameter: utf8Len 源字串长度
// @Parameter: gbkBuffer gbk缓冲
// @Parameter: gbkBufferSize gbk缓冲大小
// @Brief:
//************************************
CC_DLL_EXPORT int Utf8ToGbk(const U_TF8* utf8SrcArray, size_t utf8Len, U_NIC* gbkBuffer, size_t gbkBufferSize);
//************************************
// @Method:    Utf8ToTraditionGbk
// @Returns:   int 转换后字串长度
// @Parameter: utf8SrcArray utf8源字串
// @Parameter: utf8Len 源字串长度
// @Parameter: traGbkBuffer tragbk缓冲
// @Parameter: traGbkBufferSz traGbk缓冲长度
// @Brief:
//************************************
CC_DLL_EXPORT int Utf8ToTraditionGbk(const U_TF8* utf8SrcArray, size_t utf8Len, U_NIC* traGbkBuffer, size_t traGbkBufferSz);
//************************************
// @Method:    ToUpper
// @Returns:   void
// @Parameter: str 转换的字串
// @Brief:
//************************************
CC_DLL_EXPORT void ToUpper(std::string& str);
//************************************
// @Method:    ToLower
// @Returns:   void
// @Parameter: str 转换的字串
// @Brief:
//************************************
CC_DLL_EXPORT void ToLower(std::string& str);

//************************************
// @Method:    InitializeCodeFormatTransformer
// @Returns:   void
// @Brief:	初始化字符转换器
//************************************
CC_DLL_EXPORT void InitializeCodeFormatTransformer();
#endif