//
// Created by 17336 on 2022/5/8.
//

#ifndef HOT100_442_H
#define HOT100_442_H

#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i;
            while (nums[j] - 1 != j) {
                if (nums[nums[j] - 1] == nums[j]) {
                    s.insert(nums[j]);
                    break;
                }
                swap(nums[j], nums[nums[j] - 1]);
            }
        }
        return vector<int>(s.begin(),s.end());
    }
};

#endif //HOT100_442_H
