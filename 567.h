//
// Created by 17336 on 2022/3/13.
//

#ifndef HOT100_567_H
#define HOT100_567_H

#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        //arr统计s1中各字母出现次数
        array<int, 26> arr{0};
        for (const auto &item: s1) {
            ++arr[item - 'a'];
        }
        int len1 = s1.size(), len2 = s2.size();
        //滑动窗口左边界左移
        for (int i = 0; i < len2 - len1 + 1; ++i) {
            int right = i;
            array<int, 26> temp{0};
            //当滑动窗口右边界字母在s1中时
            while (right < s2.size() && arr[s2[right] - 'a'] > 0) {
                //如果没溢出，加入滑动窗口
                if (arr[s2[right] - 'a'] - temp[s2[right] - 'a'] > 0) {
                    ++temp[s2[right] - 'a'];
                    if (temp == arr) return true;
                    ++right;
                }
                    //如果c是所需，但是溢出了已经,从左边界找溢出的元素踢出窗口
                else{
                    while (i < right && s2[i] != s2[right]) {
                        --temp[s2[i] - 'a'];
                        ++i;
                    }
                    ++i;
                    ++right;
                }
            }
            i=right;
        }
        return false;
    }
};

#endif //HOT100_567_H
