#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include <Wincrypt.h>
#include "md5.h"

//std::string GetHashText(const void * data, const size_t data_size)
//{
//	HCRYPTPROV hProv = NULL;
//
//	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
//		return "";
//	}
//
//	BOOL hash_ok = FALSE;
//	HCRYPTPROV hHash = NULL;
//	hash_ok = CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash);
//
//	if (!hash_ok) {
//		CryptReleaseContext(hProv, 0);
//		return "";
//	}
//
//	if (!CryptHashData(hHash, static_cast<const BYTE *>(data), DWORD(data_size), 0)) {
//		CryptDestroyHash(hHash);
//		CryptReleaseContext(hProv, 0);
//		return "";
//	}
//
//	DWORD cbHashSize = 0, dwCount = sizeof(DWORD);
//	if (!CryptGetHashParam(hHash, HP_HASHSIZE, (BYTE *)&cbHashSize, &dwCount, 0)) {
//		CryptDestroyHash(hHash);
//		CryptReleaseContext(hProv, 0);
//		return "";
//	}
//
//	std::vector<BYTE> buffer(cbHashSize);
//	if (!CryptGetHashParam(hHash, HP_HASHVAL, reinterpret_cast<BYTE*>(&buffer[0]), &cbHashSize, 0)) {
//		CryptDestroyHash(hHash);
//		CryptReleaseContext(hProv, 0);
//		return "";
//	}
//
//	std::ostringstream oss;
//
//	for (std::vector<BYTE>::const_iterator iter = buffer.begin(); iter != buffer.end(); ++iter) {
//		oss.fill('0');
//		oss.width(2);
//		oss << std::hex << static_cast<const int>(*iter);
//	}
//
//	CryptDestroyHash(hHash);
//	CryptReleaseContext(hProv, 0);
//	return oss.str();
//}

int main()
{
	// f97c354d  -- less than 9 800 000 hashes
	// 863dde27  --          25 100 000 
	std::string s{ "reyedfim" };
	uint32_t number{ 0 };
	std::string password;
	std::string password2{ "********" };
	uint32_t pass2chars{ 0 };
	do
	{
		std::string hash;
		do {
			std::string ss{ s + std::to_string(number++) };
			hash = md5(ss);
			if (number % 100000 == 0) std::cout << number << std::endl;
		} while (hash.substr(0, 5) != "00000");
		std::cout << hash << std::endl;
		password += hash[5];
		if (hash[5] < '8' && password2[hash[5]-'0']=='*')
		{
			password2[hash[5] - '0'] = hash[6];
			++pass2chars;
		}
		std::cout << "Password1:" << password.substr(0, 8) << std::endl;
		std::cout << "Password2:" << password2 << std::endl;
	} while (pass2chars != 8);
	return 0;
}