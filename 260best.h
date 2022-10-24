//
// Created by 17336 on 2021/10/30.
//

#ifndef HOT100_260BEST_H
#define HOT100_260BEST_H

#endif //HOT100_260BEST_H

#include "vector"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        //结果数组
        vector<int> res;
        int bit[32] = {0};
        //对于nums中所有的num，计算32位中各位出现的次数
        for (const auto &num: nums) {
            for (int i = 0; i < 32; ++i) {
                bit[i] += ((1 << i) & num) == 0 ? 0 : 1;
            }
        }
        //因为有两个不同的数x,y在nums中都只出现了一次，
        // 那么x,y一定有某一二进制位一个为0（否则x=y），一个为1，假设x某一位为1，y对应那位为0
        //可以用x为1的那一位（用temp记录）找到y并把y从bit中除去，就可以根据bit算出剩下的x
        int temp = 0;
        for (int i = 0; i < 32; ++i) {
            if (bit[i] % 2) {
                temp += 1 << i;
                break;
            }
        }
        //除去temp位不为1的所有数
        for (const auto &num: nums) {
            if ((temp & num) == 0) {
                for (int i = 0; i < 32; ++i) {
                    bit[i] -= ((1 << i) & num) == 0 ? 0 : 1;
                }
            }
        }
        //剩下的只有出现两次的数和出现一次的x即r1
        int r1 = 0;
        for (int i = 0; i < 32; ++i) {
            if (bit[i] % 2) r1 += 1 << i;
        }
        res.push_back(r1);
        //再把y恢复到bit中
        for (const auto &num: nums) {
            if (num != r1)
                for (int i = 0; i < 32; ++i) {
                    bit[i] += ((1 << i) & num) == 0 ? 0 : 1;
                }
            else
                for (int i = 0; i < 32; ++i) {
                    bit[i] -= ((1 << i) & num) == 0 ? 0 : 1;
                }
        }
        //计算y
        int r2 = 0;
        for (int i = 0; i < 32; ++i) {
            if (bit[i] % 2) r2 += 1 << i;
        }
        res.push_back(r2);
        return res;
    }
};