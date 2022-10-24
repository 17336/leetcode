//
// Created by 17336 on 2021/11/22.
//

#ifndef HOT100_384_H
#define HOT100_384_H

#endif //HOT100_384_H

#include "vector"
#include "cstdlib"
using namespace std;

class Solution {
    vector<int> val;
public:
    Solution(vector<int> &nums):val(nums) {

    }

    vector<int> reset() {
        return val;
    }

    vector<int> shuffle() {
        vector<int> res= val;
        for (int i = 0; i < val.size(); ++i) {
            int r=rand()%(i+1);
            if(r!=i){
                swap(res[i],res[r]);
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */