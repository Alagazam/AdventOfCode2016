#include <iostream>
#include <string>
#include <cctype>
#include <utility>
#include <unordered_set>
#include "data.h"

int main()
{
	int triangle{ 0 };
	for (auto tri : triplets)
	{
		int a{ std::stoi(tri.substr(0,5)) };
		int b{ std::stoi(tri.substr(5,5)) };
		int c{ std::stoi(tri.substr(10,5)) };

		if (a >= b && a >= c && a < b + c) ++triangle;
		else if (b >= a && b >= c && b < a + c) ++triangle;
		else if (c >= a && c >= b && c < a + b) ++triangle;
	}
	std::cout << "Triangles " << triangle << std::endl;
	return 0;
}