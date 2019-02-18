#ifndef STRING_ALGORITHM_H
#define STRING_ALGORITHM_H

#include "string_def.h"

extern int KMP(const char* cstr, const char* pattern);
extern int KMP(const std::string& str, const std::string& pattern);

#endif