#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <errhandlingapi.h>

typedef std::vector<double>& (*MultiplyFuncPointer)(std::vector<int>, int, double);

MultiplyFuncPointer loadFunctionFromDLL()
{
	HINSTANCE LoadingDLL = LoadLibrary(L"MultiplyerLib.dll");

	if (!LoadingDLL)
		return NULL;

	MultiplyFuncPointer multFuncPtr = (MultiplyFuncPointer)GetProcAddress(LoadingDLL, "multiply");

	return multFuncPtr;
}