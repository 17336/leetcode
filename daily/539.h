//
// Created by 17336 on 2022/1/18.
//

#ifndef HOT100_539_H
#define HOT100_539_H

#include "vector"
#include "string"
#include "algorithm"

using namespace std;

struct myless {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        int ahour = stoi(a.substr(0, 2)), aminute = stoi(a.substr(3, 2));
        if ()
    }
};

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        vector<pair<int, int>> timeP;
        for (const auto &item: timePoints) {
            timeP.push_back({stoi(item.substr(0, 2)), stoi(item.substr(3, 2))});
        }
        sort(timeP.begin(), timeP.end(), less<pair<int, int>>());
        int res = interval(timeP.front(),timeP.back());
        for (int i = 0; i < timeP.size() - 1; ++i) {
            res= min(res, interval(timeP[i],timeP[i+1]));
        }
        return res;
    }

    int interval(pair<int, int> &a, pair<int, int> &b) {
        int mintue = (b.first - a.first) * 60 + b.second - a.second;
        if (mintue > 720) return 1440 - mintue;
        return mintue;
    }
};

#endif //HOT100_539_H
