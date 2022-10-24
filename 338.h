//
// Created by 17336 on 2021/12/1.
//

#ifndef HOT100_338_H
#define HOT100_338_H

#include "vector"

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res{0};
        for (int i = 1; i <= n; ++i) {
            if(i%2) res.push_back(res.back()+1);
            else res.push_back(countBit(i));
        }
        return res;
    }
    int countBit(int i){
        int count=0;
        while (i!=0){
            i&=(i-1);
            count++;
        }
        return count;
    }
};

#endif //HOT100_338_H
