//
// Created by 17336 on 2022/4/1.
//

#ifndef HOT100_14_H
#define HOT100_14_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size()&&prefix[j]==strs[i][j]) ++j;
            prefix.erase(j,prefix.size()-j);
        }
        return prefix;
    }
};

#endif //HOT100_14_H
