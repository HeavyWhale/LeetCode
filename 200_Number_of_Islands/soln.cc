#include <bits/stdc++.h>

using namespace std;

// struct IntPairHash {
//     inline size_t operator()(const pair<int, int>& p) const {
//         hash<int> int_hasher;
//         return int_hasher(p.first) ^ int_hasher(p.second);
//     }
// };

class Solution {
public:
    static int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();

        auto getNeighbours = [&](const pair<int, int>& pos) {
            vector<pair<int, int>> result;
            pair<int, int> 
                left = {pos.first, pos.second - 1},
                right = {pos.first, pos.second + 1},
                top = {pos.first - 1, pos.second},
                bottom = {pos.first + 1, pos.second};

            if (left.second >= 0) result.emplace_back(left);
            if (right.second < m) result.emplace_back(right);
            if (top.first >= 0)   result.emplace_back(top);
            if (bottom.first < n) result.emplace_back(bottom);

            return result;
        }; // lambda getNeighbours

        // for (const auto pos : getNeighbours({0, 1})) {
        //     cout << pos.first << ' ' << pos.second << endl;
        // }

        struct IntPairHash {
            inline size_t operator()(const pair<int, int>& p) const {
                hash<int> int_hasher;
                return int_hasher(p.first) ^ int_hasher(p.second);
            }
        };
        unordered_set<pair<int, int>, IntPairHash> visited;
        std::function<void(pair<int, int>)> dfs = [&](const pair<int, int>& pos) {
            for ( const auto & npos : getNeighbours(pos) ) {
                if ( grid[npos.first][npos.second] == '0' ) 
                    continue;   // ignore water
                if ( visited.insert( npos ).second ) {
                    // insertion succeed, i.e. not visited
                    dfs( npos );
                } // if
            } // for
        }; // lambda dfs

        int count = 0;
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( grid[i][j] == '0' ) 
                    continue;   // ignore water
                if ( visited.insert( {i,j} ).second ) {
                    dfs( {i,j} );
                    count++;
                } // if
            } // for
        } // for
        
        return count;
    } // Solution::numIslands

}; // Solution


int main() {

    vector<vector<char>> ex1 {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> ex2 {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << Solution::numIslands(ex1) << endl;
}
