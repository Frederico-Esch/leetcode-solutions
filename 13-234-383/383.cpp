#include"383.h"



bool canConstruct(string ransomNote, string magazine) {
	std::unordered_map<char, int> letters;
	for (auto letter : magazine) {
		auto iter = letters.find(letter);
		if(iter != letters.end()){
			iter->second++;
		}
		else {
			letters.insert(std::make_pair(letter, 1));
		}
	}

	for (auto letter : ransomNote) {
		auto iter = letters.find(letter);
		if (iter != letters.end()) {
			iter->second--;
			if (iter->second < 0) {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}