//
// Created by 17336 on 2022/3/13.
//

#ifndef HOT100_567BEST_H
#define HOT100_567BEST_H

#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        array<int, 26> arr{0}, cur{0};
        for (const auto &item: s1) {
            ++arr[item - 'a'];
        }
        int len1 = s1.size(), len2 = s2.size(), diff = len1;
        //初始化滑动窗口[left,right]=[0,len1-1]
        int left = 0, right = 0;
        for (; right < len1; ++right) {
            ++cur[s2[right] - 'a'];
            if (arr[s2[right] - 'a'] >= cur[s2[right] - 'a']) --diff;
        }
        //如果初始化滑动窗口满足条件，直接返回
        if (diff == 0) return true;
        //每次滑动窗口整体向右移一
        while (right < len2) {
            //左移一
            if (cur[s2[left] - 'a'] <= arr[s2[left] - 'a']) ++diff;
            --cur[s2[left] - 'a'];
            ++left;

            //右移一
            ++cur[s2[right] - 'a'];
            if (cur[s2[right] - 'a'] <=arr[s2[right]-'a']) --diff;
            ++right;
            if(diff==0) return true;
        }
        return false;
    }
};

#endif //HOT100_567BEST_H
