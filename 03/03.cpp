#include <iostream>
#include <string>
#include <cctype>
#include <utility>
#include <unordered_set>
#include "data.h"

bool testIfTriangle(int a, int b, int c)
{
	if (a >= b && a >= c && a < b + c) return true;
	else if (b >= a && b >= c && b < a + c)  return true;
	else if (c >= a && c >= b && c < a + b)  return true;
	return false;
}

int main()
{
	// Part 1
	{
		int triangle{ 0 };
		for (auto tri : triplets)
		{
			int a{ std::stoi(tri.substr(0,5)) };
			int b{ std::stoi(tri.substr(5,5)) };
			int c{ std::stoi(tri.substr(10,5)) };

			if (testIfTriangle(a,b,c)) ++triangle;
		}
		std::cout << "Triangles " << triangle << std::endl;
	}

	// Part 2
	{
		int triangle{ 0 };
		size_t size{ sizeof(triplets) / sizeof(triplets[0]) };
		for (auto i = 0; i!= size; )
		{
			auto &tri = triplets[i];
			++i;
			int a1{ std::stoi(tri.substr(0,5)) };
			int b1{ std::stoi(tri.substr(5,5)) };
			int c1{ std::stoi(tri.substr(10,5)) };

			tri = triplets[i];
			++i;
			int a2{ std::stoi(tri.substr(0,5)) };
			int b2{ std::stoi(tri.substr(5,5)) };
			int c2{ std::stoi(tri.substr(10,5)) };

			tri = triplets[i];
			++i;
			int a3{ std::stoi(tri.substr(0,5)) };
			int b3{ std::stoi(tri.substr(5,5)) };
			int c3{ std::stoi(tri.substr(10,5)) };

			if (testIfTriangle(a1, a2, a3)) ++triangle;
			if (testIfTriangle(b1, b2, b3)) ++triangle;
			if (testIfTriangle(c1, c2, c3)) ++triangle;
		}
		std::cout << "Triangles " << triangle << std::endl;
	}

	return 0;
}