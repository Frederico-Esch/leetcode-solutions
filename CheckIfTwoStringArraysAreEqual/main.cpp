#include <iostream>
#include <vector>

using std::vector;
using std::string;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int word_index1 = 0, word_index2 = 0, char_index1 = 0, char_index2 = 0;
    char c1;
    char c2;

    if(word1.size() != word2.size()) return false;

    while(word_index1 < word1.size() && word_index2 < word2.size()) {
        c1 = word1[word_index1][char_index1];
        c2 = word2[word_index2][char_index2];

        if (c1 != c2) return false;

        char_index1 += 1;
        char_index2 += 1;

        if(char_index1 >= word1[word_index1].size()) {
            char_index1 = 0;
            word_index1 += 1;
        }
        if(char_index2 >= word2[word_index2].size()) {
            char_index2 = 0;
            word_index2 += 1;
        }
    }
    return (word_index1 == word1.size() && word_index2 == word2.size());
}

int main() {

    vector<string> word1 { "abc", "d", "defg" };
    vector<string> word2 { "abcddef" };

    std::cout << arrayStringsAreEqual(word1, word2) << std::endl;

    return 0;
}
