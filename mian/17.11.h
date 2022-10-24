//
// Created by 17336 on 2022/5/27.
//

#ifndef HOT100_17_11_H
#define HOT100_17_11_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, vector<int>> indexs;
public:
    int findClosest(vector<string> &words, string word1, string word2) {
        int len = words.size();
        if (indexs.size() == 0)
            for (int i = 0; i < len; ++i) {
                indexs[words[i]].push_back(i);
            }
        int len1 = indexs[word1].size(), len2 = indexs[word2].size(), res = INT_MAX;
        for (int i = 0; i < len1; ++i) {
            int left = 0, right = len2 - 1, curdis = INT_MAX, curpos1 = indexs[word1][i];
            auto &w2index=indexs[word2];
            while (left <= right) {
                int mid = (left + right) / 2, curpos2 = w2index[mid];
                if (curpos2 < curpos1) {
                    curdis = min(curdis, curpos1 - curpos2);
                    left = mid + 1;
                } else {
                    curdis = min(curdis, curpos2 - curpos1);
                    right = mid - 1;
                }
            }
            res= min(res,curdis);
        }
        return res;
    }
};

#endif //HOT100_17_11_H
