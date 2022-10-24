//
// Created by 17336 on 2022/4/12.
//

#ifndef HOT100_79_H
#define HOT100_79_H

#include <vector>
#include <string>

using namespace std;

class Solution {
//    vector<vector<vector<vector<int>>>> memo;
    int steps[5] = {0, 1, 0, -1, 0};
    int m, n, len;
public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        len = word.size();
        if (len > m * n) return false;
        //0代表未判断，1代表不存在
//        memo.resize(m, vector<vector<vector<int>>>(n, vector<vector<int>>(len, vector<int>(4, 0))));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int begin) {
        if (board[i][j] != word[begin]) return false;
        if (begin == len - 1) return true;
        char temp=board[i][j];
        board[i][j] = ' ';
        for (int k = 0; k < 4; ++k) {
            int ni = i + steps[k], nj = j + steps[k + 1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] != ' ' /*&& memo[i][j][begin][k] == 0*/) {
                if (dfs(board, ni, nj, word, begin + 1)) return true;
//                memo[i][j][begin][k]=1;
            }
        }
        board[i][j] = temp;
        return false;
    }
};

#endif //HOT100_79_H
