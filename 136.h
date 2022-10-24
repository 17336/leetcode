//
// Created by 17336 on 2022/3/2.
//

#ifndef HOT100_136_H
#define HOT100_136_H

#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        array<int, 32> countBits{};
        for (const auto &item: nums) {
            unsigned temp = item;
            for (int i = 0; i < 32 && temp != 0; ++i) {
                countBits[i] += temp % 2;
                temp >>= 1;
            }
        }
        unsigned x = 1, res = 0;
        for (int i = 0; i < 32; ++i) {
            res += (countBits[i] % 2) * x;
            x *= 2;
        }
        return res;
    }
};

#endif //HOT100_136_H
