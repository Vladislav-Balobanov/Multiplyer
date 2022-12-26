#pragma once
#include <vector>

#ifdef MYLIB_EXPORTS
#define MYLIB_API _declspec(dllexport)
#else
#define MYLIB_API _declspec(dllimport)
#endif

extern MYLIB_API std::vector<int>& multiply(std::vector<int>& vector, int countOfElements, double factor);
