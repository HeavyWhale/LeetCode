#include <../utils.h>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int M = grid.size(), N = grid[0].size();

        function<bool(int,int)> isValid = [&](const int x, const int y) {
            return !(x < 0 || x >= M || y < 0 || y >= N) && (grid[x][y] == 1);
        };

        vector<vector<bool>> visited (M, vector<bool> (N, false));
        function<int(int,int)> bfs = [&](const int x, const int y) {
            if (!isValid(x, y) || visited[x][y]) return 0;
            visited[x][y] = true;
            return 1 + bfs(x+1, y) + bfs(x-1, y) + bfs(x, y+1) + bfs(x, y-1);
        };

        int maxArea = -1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != 1)
                    maxArea = max( bfs(i,j), maxArea );
            }
        }

        return maxArea;
    }
};

int main() {
    vector<vector<int>> grid (1, vector<int> (8, 0));
    grid[0][1] = 1;

    auto s = Solution();
    cout << s.maxAreaOfIsland(grid) << endl;
}

