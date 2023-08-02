//Looks very much like the CombinationSum1 so yeah, deal with that
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target, int index) {
    std::vector<std::vector<int>> result;

    int last = -1;
    for (; index < candidates.size(); index++) {
        int candidate = candidates[index];
        int new_value = target - candidate;

        if (candidate == last) continue;
        if (new_value == 0) result.push_back({ candidate });
        else if (new_value > 0) {
            for (auto comb : combinationSum2(candidates, new_value, index+1)) {
                comb.push_back(candidate);
                result.push_back(comb);
            }
        }
        last = candidate;
    }

    return result;
}
std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    auto combinations = combinationSum2(candidates, target, 0);
    for (auto& combination : combinations) std::reverse(combination.begin(), combination.end());

    return combinations;
}

int main() {

    std::vector<int> candidates { 10,1,2,7,6,1,5 };
    int target = 8;

    auto result = combinationSum2(candidates, target);
    for (auto& combination : result) {
        for (auto& value : combination) std::cout << value << " ";
        std::cout << std::endl;
    }

    return 0;
}
