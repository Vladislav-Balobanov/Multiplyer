#include "pch.h" 
#include <utility>
#include <limits.h>
#include <vector>
#include "functions.h"

static unsigned long long previous_;
static unsigned long long current_;
static unsigned index_;

std::vector<double>& multiply(std::vector<int>& vector, int countOfElements, double factor)
{
	std::vector<double> resultVector;

	for (int i = 0; i < countOfElements; i++)
	{
		resultVector[i] = vector[i] * factor;
	}

	return resultVector;
}