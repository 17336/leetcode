//
// Created by 17336 on 2021/12/18.
//

#ifndef HOT100_5_H
#define HOT100_5_H

#include "string"
#include "vector"

using namespace std;

/**
 * 中心扩展法 O(n2)
 * 马杀鸡 O(n)
 *      技巧：
 *          1.维护一个已遍历回文串中最右边界
 *          2.维护每个回文串的半径
 *          3.将回文串babadd加工成$#b#a#b#a#d#d#%这样可以避免边界检查、回文中心单字符还是双字符的判断
 */
class Solution {
public:
    string longestPalindrome(string s) {
        //对回文串加工
        string p = "$";
        for (const auto &item: s) {
            p.push_back('#');
            p.push_back(item);
        }
        p.push_back('#');
        p.push_back('%');
        //维护最右边界及其回文中心,最大回文串左右边界
        int margin = -1, center = -1, left_max = 1, right_max = 0;
        vector<int> dp(p.size());
        for (int i = 2; i < p.size(); ++i) {
            int left = i, right = i;
            //当i在margin内，对称找其左右边界
            if (i < margin) {
                int radix = min(dp[2 * center - i], margin - i + 1);
                right = i + radix - 1;
                left = i - radix + 1;
            }
            //中心扩展
            while (p[left - 1] == p[right + 1]) {
                --left;
                ++right;
            }
            dp[i]=right - i + 1;
            if (margin < right) {
                margin = right;
                center = i;
            }
            if (right - left > right_max - left_max) {
                right_max = right;
                left_max = left;
            }
        }
        string res;
        for (int i = p[left_max] == '#' ? left_max + 1 : left_max; i <= right_max; i += 2) {
            res.push_back(p[i]);
        }
        return res;
    }
};

#endif //HOT100_5_H
