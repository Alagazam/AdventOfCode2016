#include <iostream>
#include <string>
#include "data.h"

const std::string testaddresses[]
{ "abba[mnop]qrst"	// supports TLS (abba outside square brackets).
, "abcd[bddb]xyyx"	// does not support TLS(bddb is within square brackets, even though xyyx is outside square brackets).
, "aaaa[qwer]tyui"	// does not support TLS(aaaa is invalid; the interior characters must be different).
, "ioxxoj[asdfgh]zxcvbn"	// supports TLS(oxxo is outside square brackets, even though it's within a larger string).
};

int main()
{
	uint32_t tlsSupported{ 0 };

	for (auto &s : addresses)
	{
		bool insideBrackets{ false };
		bool tls{ false };
		size_t pos{ 0 };
		while (pos + 3 < s.length())
		{
			if (s[pos] == '[')
			{
				insideBrackets = true;
			}
			else if (s[pos] == ']')
			{
				insideBrackets = false;
			}
			else if (s[pos] == s[pos + 3] && s[pos + 1] == s[pos + 2] && s[pos] != s[pos + 1])
			{
				if (insideBrackets)
				{
					tls = false;
					break;
				}
				else
				{
					tls = true;
				}
			}
			++pos;
		};
		if (tls)
		{
			++tlsSupported;
			std::cout << "TLS Supported:" << s << std::endl;
		}
	}
	std::cout << "TLS Supported:" << tlsSupported << std::endl;

	return 0;
}