// tstring.h

#ifndef _TSTRING_H
#define _TSTRING_H

#include <string>

using namespace std;


// Unicode�̸�	tstring -> wstring
// MBCD			tstring -> string
#ifdef _UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif




#endif