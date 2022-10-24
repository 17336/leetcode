//
// Created by 17336 on 2021/12/19.
//

#ifndef HOT100_997_H
#define HOT100_997_H

#include "vector"

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1,0);
        for (const auto &item: trust) {
            count[item[0]]=-1;
            if(count[item[1]]!=-1){
                count[item[1]]++;
            }
        }
        for (int i=1;i<=n;i++) {
            if(count[i]==n-1) return i;
        }
        return -1;
    }
};

#endif //HOT100_997_H
