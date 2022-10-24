//
// Created by 17336 on 2022/5/14.
//

#ifndef HOT100_691_H
#define HOT100_691_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<int> tar;
    vector<vector<int>> stis;
public:
    int minStickers(vector<string> &stickers, string target) {
        tar.resize(26, 0);
        for (const auto &item: target) {
            ++tar[item - 'a'];
        }
        for (const auto &sticker: stickers) {
            stis.emplace_back(26, 0);
            for (const auto &item: sticker) {
                ++stis.back()[item - 'a'];
            }
        }
    }
};

#endif //HOT100_691_H
