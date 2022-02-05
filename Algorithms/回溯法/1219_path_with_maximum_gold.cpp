#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // 1、网格类题目定义方向数组
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    int record = grid[i][j];
                    grid[i][j] = 0;
                    res = max(res, record + dfs(grid, i, j));
                    grid[i][j] = record;
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        // 2、定义一个变量维护最大化收益
        int res = 0;
        // 进行DFS遍历
        for (int d = 0; d < 4; d++) {
            int nx = x + dirs[d][0];
            int ny = y + dirs[d][1];
            // 4、如果满足题目的边界条件或者其他条件，再进行DFS遍历。
            if (inArea(nx, ny, grid) && grid[nx][ny] != 0) {
                // 3、为了不使用访问数组，这里用一个变量进行记录访问过的元素不再访问
                int record = grid[nx][ny];
                grid[nx][ny] = 0;
                res = max(res, record + dfs(grid, nx, ny));
                grid[nx][ny] = record;
            }
        }
        return res;
    }

    bool inArea(int nx, int ny, vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
         return nx >=0 && ny >=0 && nx < m && ny < n; 
    }
};

int test01() {
    vector<vector<int>> grid = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
    Solution s;
    return s.getMaximumGold(grid);
}

int main() {
    cout << test01() << endl;
    return 0;
}

