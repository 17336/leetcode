//
// Created by 17336 on 2022/3/22.
//

#ifndef HOT100_229_H
#define HOT100_229_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int res1 = -1, res2 = -1, count1 = 0, count2 = 0;
        for (const auto &item: nums) {
            if (count1 && item == res1) ++count1;
            else if (count2 && item == res2) ++count2;
            else if (count1 == 0) {
                res1 = item;
                count1 = 1;
            } else if (count2 == 0) {
                res2 = item;
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }
        vector<int> res;
//        if(count1) res.push_back(res1);
//        if(count2) res.push_back(res2);
        count1 = count2 = 0;
        for (const auto &item: nums) {
            if (item == res1) ++count1;
            if (item == res2) ++count2;
        }
        if (count1 > nums.size() / 3) res.push_back(res1);
        if (res2!=res1&&count2 > nums.size() / 3) res.push_back(res2);
        return res;
    }
};

#endif //HOT100_229_H
