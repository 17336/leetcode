//
// Created by 17336 on 2021/12/11.
//

#ifndef HOT100_911_H
#define HOT100_911_H

#include "vector"
#include "unordered_map"

using namespace std;

class TopVotedCandidate {
    //记录times中每个时刻领先的候选人
    vector<pair<int, int>> winner;
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times) {
        unordered_map<int, int> count;
        //记录最多票数及其对应候选人
        int cmax = 0, cperson;
        for (int i = 0; i < times.size(); ++i) {
            if (++count[persons[i]] >= cmax) {
                cmax = count[persons[i]];
                cperson = persons[i];
            }
            winner.push_back({times[i], cperson});
        }
    }

    int q(int t) {
        //二分搜索t或刚好小于t时刻的领先者
        int left = 0, right = min(t,(int)winner.size()-1), index;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (winner[mid].first > t) {
                right=mid-1;
            } else {
                index=mid;
                left=mid+1;
            }
        }
        return winner[index].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

#endif //HOT100_911_H
