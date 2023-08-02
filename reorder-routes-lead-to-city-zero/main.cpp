#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

typedef std::string string;

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& conections) {
        std::unordered_map<int, std::vector<int>> reversed_grid;
        std::unordered_map<int, std::vector<int>> direct_grid;
        std::unordered_set<int> visited;

        for (auto con : conections) {
            if (reversed_grid.find(con[1]) == reversed_grid.end()) reversed_grid[con[1]] = std::vector<int>();
            reversed_grid[con[1]].push_back(con[0]);

            if (direct_grid.find(con[0]) == direct_grid.end()) direct_grid[con[0]] = std::vector<int>();
            direct_grid[con[0]].push_back(con[1]);
        }

        std::deque<int> next_reversed;
        std::deque<int> next_direct;

        if (reversed_grid.find(0) != reversed_grid.end()) for (auto r : reversed_grid[0]) next_reversed.push_back(r);

        if (direct_grid.find(0) != direct_grid.end()) for (auto d : direct_grid[0]) next_direct.push_back(d);
        visited.insert(0);


        int reorders = 0;
        while (next_direct.size() > 0 || next_reversed.size() > 0) {
            if (next_reversed.size() > 0) {
                int cur = next_reversed.front();
                next_reversed.pop_front();
                visited.insert(cur);
                std::cout << "let alone: " << cur << std::endl;

                if (reversed_grid.find(cur) != reversed_grid.end())
                    for (auto r : reversed_grid[cur])
                        if (visited.find(r) == visited.end())
                            next_reversed.push_back(r);
                if (direct_grid.find(cur) != direct_grid.end())
                    for (auto d : direct_grid[cur])
                        if (visited.find(d) == visited.end())
                            next_direct.push_back(d);
            }
            else {
                int cur = next_direct.front();
                next_direct.pop_front();
                if (visited.find(cur) != visited.end()) continue;
                reorders++;
                visited.insert(cur);
                std::cout << "reversed: " << cur << std::endl;

                if (reversed_grid.find(cur) != reversed_grid.end())
                    for (auto r : reversed_grid[cur])
                        if (visited.find(r) == visited.end())
                            next_reversed.push_back(r);
                if (direct_grid.find(cur) != direct_grid.end())
                    for (auto d : direct_grid[cur])
                        if (visited.find(d) == visited.end())
                            next_direct.push_back(d);
            }
        }

        return reorders;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> v = {{0,2},{0,3},{4,1},{4,5},{5,0}};
    std::cout << sol.minReorder(6, v) << std::endl;

    return 0;
}
