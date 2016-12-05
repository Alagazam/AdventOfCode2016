#include <iostream>
#include <string>
#include <array>
#include <cctype>
#include <utility>
#include <algorithm>
#include "data.h"

const std::string testrooms[]
{ "aaaaa-bbb-z-y-x-123[abxyz]"	// real
, "a-b-c-d-e-f-g-h-987[abcde]"	// real
, "not-a-real-room-404[oarel]"	// real
, "totally-real-room-200[decoy]"// not real
};

template<class T>
size_t findMax(const T& a)
{
	auto max = std::max_element(a.begin(), a.end());
	return max - a.begin();
}

int main()
{
	{
		int validIdSum{ 0 };
		for (auto &room : rooms)
		{
			enum class Mode { roomName, roomId, roomCheck } mode{ Mode::roomName };
			std::array<uint16_t, 'z' - 'a' + 1>  charCount{ 0 };
			uint16_t id{ 0 };
			std::string check;
			for (auto c : room)
			{
				switch (mode)
				{
				case Mode::roomName:
				{
					if (isalpha(c))
					{
						++charCount[c - 'a'];
						break;
					}
					else if (c == '-')
						break;
					else 
						mode = Mode::roomId;
						// fallthrough
				}
				case Mode::roomId:
				{
					if (isdigit(c))
					{
						id *= 10;
						id += (c - '0');
						break;
					}
					else
						mode = Mode::roomCheck;
						// fallthrough
				}
				case Mode::roomCheck:
				{
					if (isalpha(c))
						check += c;
					break;
				}
				}
			}
			std::cout << "Room: " << room << " Id:" << id << " Check:" << check << "  ";

			auto max= findMax(charCount);
			std::cout << char(max + 'a');
			if (check[0] != (max + 'a'))  std::cout << "  Invalid" << std::endl;
			else
			{
				charCount[max] = 0;
				auto max = findMax(charCount);
				std::cout << char(max + 'a');
				if (check[1] != (max + 'a'))  std::cout << "  Invalid" << std::endl;
				else
				{
					charCount[max] = 0;
					auto max = findMax(charCount);
					std::cout << char(max + 'a');
					if (check[2] != (max + 'a'))  std::cout << "  Invalid" << std::endl;
					else
					{
						charCount[max] = 0;
						auto max = findMax(charCount);
						std::cout << char(max + 'a');
						if (check[3] != (max + 'a'))  std::cout << "  Invalid" << std::endl;
						else
						{
							charCount[max] = 0;
							auto max = findMax(charCount);
							std::cout << char(max + 'a');
							if (check[4] != (max + 'a'))  std::cout << "  Invalid" << std::endl;
							else
							{
								std::cout << "  Valid" << std::endl;
								validIdSum += id;
							}
						}
					}
				}
			}
		}
		std::cout << "Valid rooms Id sum: " << validIdSum << std::endl;
	}
	return 0;
}