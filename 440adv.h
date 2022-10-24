//
// Created by 17336 on 2022/4/19.
//

#ifndef HOT100_440ADV_H
#define HOT100_440ADV_H

#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1, cur = 1;
        while (cur != k) {
            long l = res*10l, r = l+9, count = 0;
            //找出当前节点res的子孙节点个数
            while (l <= n) {
                count += min(r, (long )n) - l + 1;
                l = 10 * l;
                r = 10 * r + 9;
            }
            //如果算上所有子孙够了，则搜索res的子树
            if (cur + count >= k) {
                res *= 10;
                ++cur;
            }
            //如果不够则跳到res的兄弟节点
            else {
                ++res;
                cur += count + 1;
            }
        }
        return res;
    }
};

#endif //HOT100_440ADV_H
