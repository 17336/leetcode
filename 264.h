//
// Created by 17336 on 2022/3/27.
//

#ifndef HOT100_264_H
#define HOT100_264_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> urgys;
        unordered_set<int> set;
        urgys.push_back(1);
        set.insert(1);
        int i=0,j=0,k=0,count=1;
        while (count<n){
            int ui=urgys[i]*2,uj=urgys[j]*3,uk=urgys[k]*5;
            if(ui<=uj&&ui<=uk){
                if(set.count(ui)==0){
                    urgys.push_back(ui);
                    set.insert(ui);
                    ++count;
                }
                ++i;
            } else if(uj<=ui&&uj<=uk){
                if(set.count(uj)==0){
                    urgys.push_back(uj);
                    set.insert(uj);
                    ++count;
                }
                ++j;
            } else {
                if(set.count(uk)==0){
                    urgys.push_back(uk);
                    set.insert(uk);
                    ++count;
                }
                ++k;
            }
        }
        return urgys.back();
    }
};

#endif //HOT100_264_H
