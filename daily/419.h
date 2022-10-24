//
// Created by 17336 on 2021/12/18.
//

#ifndef HOT100_419_H
#define HOT100_419_H

#include "vector"

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        int sum = 0, m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') {
                    int temp=i;
                    sum++;
                    while (j + 1 < n && board[i][j + 1] == 'X') board[i][++j] = '.';
                    while (i + 1 < m && board[i + 1][j] == 'X') board[++i][j] = '.';
                    i=temp;
                }
            }
        }
        return sum;
    }
};

#endif //HOT100_419_H
