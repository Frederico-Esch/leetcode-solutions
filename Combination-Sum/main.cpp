#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target, int index) {
    std::vector<std::vector<int>> result;

    for (; index < candidates.size(); index++) {

        int new_value = target - candidates[index];
        if (new_value == 0) result.push_back(std::vector<int> { candidates[index] });
        else if (target < candidates[index]) continue;
        else for (auto combinations : combinationSum(candidates, new_value, index)) {
            combinations.push_back(candidates[index]);
            result.push_back(combinations);
        }

    }

    return result;
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    return combinationSum(candidates, target, 0);
}

void print_vec(std::vector<int>& vec) {
    for (auto& values : vec) std::cout << values << " ";
    std::cout << std::endl;
}

int main() {

    std::vector<int> candidates { 2 };
    int target = 1;

    for (auto& vec : combinationSum(candidates, target)) print_vec(vec);

    return 0;
}
