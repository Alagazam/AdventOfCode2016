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
	std::string max_message;
	std::string min_message;
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
		max_message += maxfreqchar;

		uint32_t minfreq{ 99999 };
		char minfreqchar{ '_' };
		char c{ 'a' };
		for (auto f : freq)
		{
			if (minfreq > f)
			{
				minfreq = f;
				minfreqchar = c;
			}
			++c;
		}
		min_message += minfreqchar;

	}
	std::cout << "Max message:" << max_message << std::endl;
	std::cout << "Min message:" << min_message << std::endl;
	return 0;
}