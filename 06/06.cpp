#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "data.h"

const std::string testmessage[]
{ "eedadn"
,"drvtee"
,"eandsr"
,"raavrd"
,"atevrs"
,"tsrnev"
,"sdttsa"
,"rasrtv"
,"nssdts"
,"ntnada"
,"svetve"
,"tesnvt"
,"vntsnd"
,"vrdear"
,"dvrsen"
,"enarar"
};

int main()
{
	for (uint32_t i = 0; i != message[0].length(); ++i)
	{
		uint32_t freq['z' - 'a' + 1]{ 0 };
		uint32_t maxfreq{ 0 };
		char maxfreqchar{ '_' };
		for (auto m : message)
		{
			size_t c = m[i] - 'a';
			++freq[c];
			if (freq[c] > maxfreq)
			{
				maxfreqchar = m[i];
				maxfreq = freq[c];
			}
		}
		std::cout << maxfreqchar;
	}
	std::cout << std::endl;
	return 0;
}