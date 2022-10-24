//
// Created by 17336 on 2022/1/7.
//

#ifndef HOT100_1614_H
#define HOT100_1614_H

#include "string"

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int mDepth=0,depth=0;
        for (const auto &item: s) {
            if(item=='(') ++depth;
            else if(item==')'){
                mDepth= max(mDepth,depth);
                --depth;
            }
        }
        mDepth= max(mDepth,depth);
        return mDepth;
    }
};

#endif //HOT100_1614_H
