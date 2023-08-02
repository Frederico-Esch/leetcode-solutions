#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <deque>
class pair_hasher {
public:
    size_t operator()(const std::pair<int, int>& pair) const {
        size_t hash = (pair.first << 9) + pair.second;
        //std::cout << hash << std::endl;
        return hash;
    }
};

typedef std::vector<std::vector<int>> grid_t;
typedef std::pair<int, int> coord;
typedef std::unordered_set<coord, pair_hasher> pair_set;

void bfs(grid_t& grid, coord ponto, std::deque<coord>& next, pair_set& visited) {
    if (visited.find(ponto) != visited.end()) return;

    visited.insert(ponto);

    if (ponto.first - 1 >= 0)
        if(grid[ponto.second][ponto.first-1])
            next.push_back({ ponto.first - 1, ponto.second });

    if (ponto.first + 1 < grid[0].size())
        if (grid[ponto.second][ponto.first+1])
            next.push_back({ ponto.first + 1, ponto.second });

    if (ponto.second - 1 >= 0)
        if(grid[ponto.second-1][ponto.first])
            next.push_back({ ponto.first, ponto.second - 1 });

    if (ponto.second + 1 < grid.size())
        if(grid[ponto.second+1][ponto.first])
            next.push_back({ ponto.first, ponto.second + 1 });
}

void scan_horizontal (grid_t& grid, int vertical_coord, pair_set& visited) {
    std::deque<coord> next;
    for (int i = 0; i < grid[vertical_coord].size(); i++) if (grid[vertical_coord][i]) next.push_back({ i, vertical_coord });

    while (next.size() > 0) {
        coord ponto = next.front();
        next.pop_front();

        bfs(grid, ponto, next, visited);
    }
}

void scan_vertical (grid_t& grid, int horizontal_coord, pair_set& visited) {
    std::deque<coord> next;
    for (int i = 0; i < grid.size(); i++) if (grid[i][horizontal_coord]) next.push_back({ horizontal_coord, i });

    while (next.size() > 0) {
        coord ponto = next.front();
        next.pop_front();

        bfs(grid, ponto, next, visited);
    }
}

int numEnclaves(grid_t& grid) {
    pair_set visited;
    int total_landmass = 0;
    int landmass_not_enclaved = 0;
    for (auto& row : grid) for (auto& value : row) total_landmass += value;

    int top = 0; int bottom = grid.size() - 1;

    scan_horizontal(grid, top, visited);
    scan_horizontal(grid, bottom, visited);

    int left = 0; int right = grid[0].size() - 1;

    scan_vertical(grid, left, visited);
    scan_vertical(grid, right, visited);

    for (auto& v : visited) landmass_not_enclaved += grid[v.second][v.first];

    return total_landmass - landmass_not_enclaved;
}


int main() {
    grid_t grid {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    auto num = numEnclaves(grid);
    std::cout << num << std::endl;

    return 0;
}
