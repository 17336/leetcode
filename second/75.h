//
// Created by 17336 on 2022/4/17.
//

#ifndef HOT100_75_H
#define HOT100_75_H

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int a = 0, b = 0, c = 0;
        for (const auto &num: nums) {
            switch (num) {
                case 0:
                    ++a;
                    break;
                case 1:
                    ++b;
                    break;
                case 2:
                    ++c;
                    break;
            }
        }
        int i = 0;
        while (a-- > 0) {
            nums[i++] = 0;
        }
        while (b-->0){
            nums[i++]=1;
        }
        while (c-->0){
            nums[i++]=2;
        }
    }
};

#endif //HOT100_75_H
