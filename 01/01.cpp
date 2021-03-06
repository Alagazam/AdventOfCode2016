#include <iostream>
#include <string>
#include <cctype>
#include <utility>
#include <unordered_set>

using position = std::pair<int, int>;

struct HashPosition
{
	size_t operator()(const position p) const
	{
		return p.first << 16 | p.second;
	}
};

int main()
{
	const std::string input{ "L1, L3, L5, L3, R1, L4, L5, R1, R3, L5, R1, L3, L2, L3, R2, R2, L3, L3, R1, L2, R1, L3, L2, R4, R2, L5, R4, L5, R4, L2, R3, L2, R4, R1, L5, L4, R1, L2, R3, R1, R2, L4, R1, L2, R3, L2, L3, R5, L192, R4, L5, R4, L1, R4, L4, R2, L5, R45, L2, L5, R4, R5, L3, R5, R77, R2, R5, L5, R1, R4, L4, L4, R2, L4, L1, R191, R1, L1, L2, L2, L4, L3, R1, L3, R1, R5, R3, L1, L4, L2, L3, L1, L1, R5, L4, R1, L3, R1, L2, R1, R4, R5, L4, L2, R4, R5, L1, L2, R3, L4, R2, R2, R3, L2, L3, L5, R3, R1, L4, L3, R4, R2, R2, R2, R1, L4, R4, R1, R2, R1, L2, L2, R4, L1, L2, R3, L3, L5, L4, R4, L3, L1, L5, L3, L5, R5, L5, L4, L2, R1, L2, L4, L2, L4, L1, R4, R4, R5, R1, L4, R2, L4, L2, L4, R2, L4, L1, L2, R1, R4, R3, R2, R2, R5, L1, L2" };

	int xpos{ 0 };
	int ypos{ 0 };
	int dx{ 0 };
	int dy{ 1 };
	bool crossed{ false };
	std::unordered_set<position, HashPosition> visited;
	std::string::const_iterator pos = input.begin();
	while (pos != input.end())
	{
		char turn{ *pos };
		++pos;
		if (turn == 'L')
		{
			//left: dnx=-dy, dny = dx;      1,0  ->  0,1  ->  -1,0  ->  0,-1  ->  1,0
			int temp = dx;
			dx = -dy;
			dy = temp;
		}
		else if (turn == 'R')
		{
			//right: dnx=dy, dny = -dx     1,0  ->  0,-1  ->  -1,0  ->  0,1  ->  1,0
			int temp = dx;
			dx = dy;
			dy = -temp;
		}

		int steps{ 0 };
		while (pos != input.end() && std::isdigit(*pos))
		{
			steps *= 10;
			steps += (*pos - '0');
			++pos;
		}
		for (int i = 0; i != steps; ++i)
		{
			xpos += dx;
			ypos += dy;
			if (!crossed)
			{
				auto insRes = visited.insert(std::make_pair(xpos, ypos));
				if (!insRes.second)
				{
					crossed = true;
					std::cout << "crossing at " << xpos << ":" << ypos << " Dist=" << abs(xpos + ypos) << std::endl;
				}
			}
		}

		while (pos != input.end() && !std::isalpha(*pos))
		{
			++pos;
		}

	}
	std::cout << "end at " << xpos << ":" << ypos << " Dist=" << abs(xpos + ypos) << std::endl;
	return 0;
}