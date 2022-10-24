//
// Created by 17336 on 2022/5/21.
//

#ifndef HOT100_242_H
#define HOT100_242_H

#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if (len1 != len2) return false;
        vector<int> counts(26,0);
        for (const auto &item: s) {
            ++counts[item-'a'];
        }
        for (const auto &item: t) {
            if(counts[item-'a']==0) return false;
            --counts[item-'a'];
        }
        return true;
    }
};

#endif //HOT100_242_H
