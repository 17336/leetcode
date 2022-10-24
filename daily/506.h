//
// Created by 17336 on 2021/12/2.
//

#ifndef HOT100_506_H
#define HOT100_506_H

#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score) {
        vector<string> res(score.size());
        unordered_map<int,int> index;
        for (int i = 0; i < score.size(); ++i) {
            index[score[i]]=i;
        }
        sort(score.begin(),score.end(),greater<int>());
        int i=0;
        for (; i < 3&&i<score.size(); ++i) {
            if(i==0) res[index[score[i]]]="Gold Medal";
            else if(i==1) res[index[score[i]]]="Silver Medal";
            else if(i==2) res[index[score[i]]]="Bronze Medal";
        }
        for (; i < score.size(); ++i) {
            res[index[score[i]]]= to_string(i+1);
        }
        return res;
    }
};

#endif //HOT100_506_H
