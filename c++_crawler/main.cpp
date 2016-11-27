#include "include/cpr/cpr.h"
#include "parse.h"
#include <iostream>

int main(void)
{
	//get request
	auto r = cpr::Get(cpr::Url{ "http://127.0.0.1:3000" },
		cpr::Authentication{ "user", "pass" },
		cpr::Parameters{ { "anon", "true" },{ "key", "value" } });
	r.status_code;                  // 200
	r.header["content-type"];       // application/json; charset=utf-8
	r.text;                         // JSON text string
		
	std::cout << r.status_code << endl;
	std::cout << r.header["content-type"] << endl;
	std::cout << r.text << endl;


	//post request
	auto rr = cpr::Post(cpr::Url{ "http://127.0.0.1:3000" },
		cpr::Body{ "This is raw POST data" },
		cpr::Header{ { "accept", "application/json" },{ "content-type", "text/plain" } });

	std::cout << rr.text << std::endl;

	return 0;
}