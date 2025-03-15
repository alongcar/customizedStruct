#include<string>
#include<regex>
#include<iostream>
void regex_practice_1() {
	try {
		std::string s;
		std::cin >> s;
		std::regex r("[^e]*i.*|.*c.*i.*|[^ei]*");//");
		std::cout << regex_match(s, r) << std::endl;
		std::regex r2("([^c]ei");
		for (std::sregex_iterator it(s.begin(), s.end(), r2), end; it != end; it++) {
			std::cout << it->prefix().str() << " >> " << it->str() << " << " << it->suffix().str() << std::endl;
		}
	}
	catch (std::regex_error e) {
		std::cout << e.what() << " " << e.code() << std::endl;
	}
}
