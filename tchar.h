// tchar.h
#ifndef _TCHAR_H
#define _TCHAR_H


// Unicode�̸�	tchar -> wchar_t
// MBCD			tchar -> char
#ifdef _UNICODE
typedef wchar_t tchar;
#else
typedef char tchar;
#endif


#endif