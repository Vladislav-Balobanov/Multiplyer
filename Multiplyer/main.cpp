#include <iostream>
#include <vector>
#include <Windows.h>
#include <errhandlingapi.h>

typedef std::vector<int>& (* MultiplyFuncPointer)(std::vector<int>, int, double);

int main()
{
	HINSTANCE LoadingDLL = LoadLibrary(L"C:\\Users\\balobanov_va\\source\\repos\\Multiplyer\\x64\\Release\\MultiplyerLib.dll");

	if (!LoadingDLL)
		return EXIT_FAILURE;

	MultiplyFuncPointer multFuncPtr = (MultiplyFuncPointer)GetProcAddress(LoadingDLL, "multiply");

	int countOfElements = 0;
	double factor = 0;

	std::cout << "Insert count of elements: ";
	std::cin >> countOfElements;

	std::vector<int> vector;

	for (int i = 0; i < countOfElements; i++)
	{
		vector.push_back(rand() % 100);
		std::cout << vector[i] << ' ';
	}

	std::cout << "\nInsert factor: ";
	std::cin >> factor;

	std::vector<int> resultVector = multFuncPtr(vector, countOfElements, factor);

	std::cout << "Result: ";
	for (auto element : resultVector)
	{
		std::cout << element << ' ';
	}

	return 0;
}