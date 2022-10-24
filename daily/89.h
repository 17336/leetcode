//
// Created by 17336 on 2022/1/8.
//

#ifndef HOT100_89_H
#define HOT100_89_H

#include "vector"

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0,1};
        //采用动态规划的思想
        //如n=1时，有序列{0,1}
        //当n=2时，最高位置1，低位选{0,1}的逆序低位
        //      即{11,10}，合并即得{0,1,11,10}
        //n=3时，同理{0,1,11,10,110,111,101,100}

        //high维护本次要置的最高位：2^i
        int high=1;
        for (int i = 1; i < n; ++i) {
            high<<=1;
            //temp为第i次边界
            int temp=high<<1;
            for (int j = high; j < temp; ++j) {
                res.push_back(res[temp-1-j]+high);
            }
        }
        return res;
    }
};

#endif //HOT100_89_H
