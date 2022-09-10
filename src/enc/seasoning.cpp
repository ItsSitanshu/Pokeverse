/*
    filename: seasoning.cpp
    author: Sitanshu Shrestha at (bit.ly/sitanshu)
    licence: BSD 3-Clause License
*/

#include "enc/seasoning.hpp"
#include "enc/sha526.hpp"

#include "cstring"
#include "string"

std::string generate_salt(char* src) {
    int str_len = strlen(src);
	CTX ctx;
	unsigned char hash[32];
	std::string hash_str;

	sha_init(&ctx);
	sha_update(&ctx, (unsigned char*)src, str_len);
	sha_final(&ctx, hash);

	char s[3];
	for (int i = 0; i < 32; i++) {
		sprintf(s, "%02x", hash[i]);
		hash_str += s;
	}

	return hash_str;
}