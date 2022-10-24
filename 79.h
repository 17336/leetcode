//
// Created by 17336 on 2021/11/15.
//

#ifndef HOT100_79_H
#define HOT100_79_H

#endif //HOT100_79_H

#include "vector"
#include "string"
#include "deque"

using namespace std;

class Solution {
    int step[5] = {0, 1, 0, -1, 0};
    //deque<deque<bool>> memo
public:
    bool exist(vector<vector<char>> &board, string word) {
        //deque<deque<bool>> memo = deque<deque<bool>>(board.size(), deque<bool>(board[0].size(), false));
        vector<vector<int>> memo(board.size(),vector<int>(board[0].size(),0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(memo, board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<int>> &memo, vector<vector<char>> &board, int p, int q, string &word, int i) {
        if (word[i] != board[p][q]) return false;
        if (i == word.size() - 1) return true;
        memo[p][q] = true;
        for (int j = 0; j < 4; ++j) {
            int np = p + step[j], nq = q + step[j + 1];
            if (np >= 0 && np < board.size() && nq >= 0 && nq < board[p].size() && !memo[np][nq] &&
                dfs(memo, board, np, nq, word, i + 1))
                return true;
        }
        memo[p][q] = false;
        return false;
    }
};