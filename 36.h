//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_36_H
#define HOT100_36_H

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<int> count(10, 0);
        for (const auto &item: board) {
            std::fill(count.begin(), count.end(), 0);
            for (const auto &item2: item) {
                if (item2 == '.') continue;
                if (count[item2 - '0']) return false;
                count[item2 - '0'] = 1;
            }
        }
        for (int i = 0; i < 9; ++i) {
            std::fill(count.begin(), count.end(), 0);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;
                if (count[board[j][i] - '0']) return false;
                count[board[j][i] - '0'] = 1;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                std::fill(count.begin(), count.end(), 0);
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (board[i + k][j + l] == '.') continue;
                        if (count[board[i + k][j + l] - '0']) return false;
                        count[board[i + k][j + l] - '0'] = 1;
                    }
                }
            }
        }
        return true;
    }
};

#endif //HOT100_36_H
