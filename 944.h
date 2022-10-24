//
// Created by 17336 on 2022/5/12.
//

#ifndef HOT100_944_H
#define HOT100_944_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_set<int> s;
public:
    int minDeletionSize(vector<string> &strs) {
        int res = 0;
        for (int i = 1; i < strs.size(); ++i) {
            isAsc(strs[i-1],strs[i]);
        }
        return s.size();
    }

    void isAsc(string &a, string &b) {
        int len = a.size();
        for (int i = 0; i < len; ++i) {
            if (a[i] > b[i]) s.insert(i);
        }
    }
};

#endif //HOT100_944_H
