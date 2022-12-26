﻿#include <iostream>
#include "functions.h"

std::vector<int> generateRandVector()
{
	int countOfElements = 0;
	std::cout << "Insert count of elements: ";
	std::cin >> countOfElements;

	std::vector<int> vector;

	for (int i = 0; i < countOfElements; i++)
	{
		vector.push_back(rand() % 100);
	}

	return vector;
}

void print(std::vector<int>& vector, std::string vectorName)
{
	std::cout << vectorName << ": ";

	for (auto element : vector)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		std::vector<int> generatedVector = generateRandVector();
		print(generatedVector, "generatedVector");

		double factor = 0;

		std::cout << "Введите множитель для массива factor: ";
		std::cin >> factor;

		std::vector<int> resultVector = multiply(generatedVector, generatedVector.size(), factor);
		print(resultVector, "resultVector");
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		exit;
	}

    return 0;
}
