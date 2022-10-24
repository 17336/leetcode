//
// Created by 17336 on 2021/12/30.
//

#ifndef HOT100_846_H
#define HOT100_846_H

#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
    unordered_map<int, int> counts;
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        sort(hand.begin(),hand.end());
        for (const auto &item: hand) {
            ++counts[item];
        }
        for (int i = 0; i < hand.size(); ++i) {
            if(counts[hand[i]]&&!trimCounts(hand[i],groupSize)) return false;
        }
        return true;
    }
    bool trimCounts(int begin,int groupSize){
        for (int i = begin; i < groupSize+begin; ++i) {
            --counts[i];
            if(counts[i]<0) return false;
            else if(counts[i]==0) counts.erase(i);
        }
        return true;
    }
};

#endif //HOT100_846_H
