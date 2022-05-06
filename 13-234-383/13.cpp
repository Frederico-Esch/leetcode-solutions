#pragma once
#include<unordered_map>
#include "13.h"

std::unordered_map<char, int> values {
	std::make_pair('I', 1),
	std::make_pair('V', 5),
	std::make_pair('X', 10),
	std::make_pair('L', 50),
	std::make_pair('C', 100),
	std::make_pair('D', 500),
	std::make_pair('M', 1000),
};

int romanToInt(string s) {
	int last = 0;
	int result = 0;
	for (char c : s) {
		int current = values.at(c);
		if (last != 0 && last < current) {
			result -= 2 * last;
		}
		last = current;
		result += current;
	}
	return result;
}

