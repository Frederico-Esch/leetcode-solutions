#include<bits/stdc++.h>
typedef std::string string;
int P[2500]; //The buffer outside the class on leetcode, does not work, even though locally it does

class Solution {
public:

    std::pair<int, int> solve(string& s){
        std::pair<int, int> longest = std::make_pair(0,-2);
        int C = 0, R = 0;

        for (int i = 1; i < s.size() - 1; i ++ ){

            int mirr = C*2 - i;
            if (i < R) {
                P[i] = std::min(R-i, P[mirr]);
            }

            while (i+P[i]+1 < s.size() && i - (1+P[i]) >= 0 && s[i + P[i] + 1] == s[i - (1 + P[i])]) {
                P[i]++;
            }

            if (i + P[i] > R) {
                C = i;
                R = i+P[i];
                if (P[i] > longest.second){
                    longest = {C, P[i]};
                    std::cout << "C = " << longest.first << " P[i] = " << longest.second << std::endl;
                }
            }

        }
        return longest;
    }

    string longestPalindrome(string s){
        if (s.size() == 1) return s;

        std::stringstream ss;
        ss << '#';
        for (size_t i = 0; i < s.size() ; i++){
            ss << s[i]; ss << '#';
        }

        string new_string = ss.str();
        std::memset(P, 0, 2500);
        auto [c, size] = solve(new_string);

        std::pair<int, int> parity = {!(c%2), size%2};
        c    /= 2;
        size /= 2;

        return s.substr(c-size, 2*size + parity.second);
    }
};


auto main() -> int {
    Solution s;
    std::cout << s.longestPalindrome("babad") << '\n';
    std::cout << s.longestPalindrome("cbbd") << '\n';
    std::cout << s.longestPalindrome("bb") << '\n';
    std::cout << s.longestPalindrome("ac") << '\n';
    std::cout << s.longestPalindrome("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel") << '\n';
    return 0;
}















