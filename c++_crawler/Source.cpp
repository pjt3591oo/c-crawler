#include "include/cpr/cpr.h"
#include "parse.h"
#include <iostream>

int main(void)
{
	//get request
	auto r = cpr::Get(cpr::Url{ "http://www.naver.com" },
		cpr::Authentication{ "user", "pass" },
		cpr::Parameters{ { "anon", "true" },{ "key", "value" } });
	r.status_code;                  // 200
	r.header["content-type"];       // application/json; charset=utf-8
	r.text;                         // JSON text string
		
	std::cout << r.status_code;
	std::cout << r.header["content-type"];

	return 0;
}