//
// Created by 17336 on 2022/5/9.
//

#ifndef HOT100_942_H
#define HOT100_942_H

#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size(),mn=0,mx=n;
        vector<int> res;
        for (const auto &item: s) {
            if(item=='I') {
                res.push_back(mn++);
            } else{
                res.push_back(mx--);
            }
        }
        res.push_back(mn);
        return res;
    }
};

#endif //HOT100_942_H
