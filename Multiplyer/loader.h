#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <errhandlingapi.h>

typedef std::vector<int>& (*MultiplyFuncPointer)(std::vector<int>, int, double);

MultiplyFuncPointer loadFunctionFromDLL()
{
	HINSTANCE LoadingDLL = LoadLibrary(L"C:\\Users\\balobanov_va\\source\\repos\\Multiplyer\\x64\\Release\\MultiplyerLib.dll");

	if (!LoadingDLL)
		return NULL;

	MultiplyFuncPointer multFuncPtr = (MultiplyFuncPointer)GetProcAddress(LoadingDLL, "multiply");

	return multFuncPtr;
}