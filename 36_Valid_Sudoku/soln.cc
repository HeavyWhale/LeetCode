#include "../utils.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < N; ++i) {
            if (!checkCol(board, i)) return false;
            if (!checkRow(board, i)) return false;
        }
        for (int i = 0; i < n; ++i) {
            if (!checkSubBox(board, n * i, 0)) return false;
            if (!checkSubBox(board, n * i, 3)) return false;
            if (!checkSubBox(board, n * i, 6)) return false;
        }
        return true;
    }

private:
    const int N = 9;
    const int n = 3;

    bool checkCol(const vector<vector<char>>& board, int x) {
        bool visited[10] = {0};
        for (int i = 0; i < N; ++i) {
            char ch = board[i][x];
            if (ch == '.') continue;
            int n = ch - '0';
            if (visited[n]) return false;
            visited[n] = true;
        } // for
        return true;
    }

    bool checkRow(const vector<vector<char>>& board, int y) {
        bool visited[10] = {0};
        for (int i = 0; i < N; ++i) {
            char ch = board[y][i];
            if (ch == '.') continue;
            int n = ch - '0';
            if (visited[n]) return false;
            visited[n] = true;
        } // for
        return true;
    }

    // starting top-left cell at pos (x, y)
    bool checkSubBox(const vector<vector<char>>& board, int x, int y) {
        // cout << "checking @ x = " << x << ", y = " << y << '\n';
        bool visited[10] = {0};
        for (int i = x; i < x + n; ++i) {
            for (int j = y; j < y + n; ++j) {
                char ch = board[i][j];
                if (ch == '.') continue;
                int n = ch - '0';
                if (visited[n]) return false;
                visited[n] = true;
            } // for
        } // for
        // cout << arr_repr(visited, 10) << "\n\n";
        return true;
    } // checkSubBox
};

int main() {
    vector<vector<char>> board = {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };

    Solution s = Solution();
    assert(!s.isValidSudoku(board));
}
