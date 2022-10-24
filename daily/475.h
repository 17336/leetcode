//
// Created by 17336 on 2021/12/20.
//

#ifndef HOT100_475_H
#define HOT100_475_H

#include "vector"
#include "stack"
#include "algorithm"
using namespace std;

class Solution {
    vector<pair<int, int>> hh;
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        //思路：
        //      对于每一件房子：分别找它左边和右边最近的供暖器到它的距离，
        //      所有房子最近距离中的最大值即为radius
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        myMerge(houses, heaters);
        int last = -1,mRadius=0;
        //栈存储未确定右边最近供暖器的房子下标和左边距离
        stack<pair<int,int>> s;
        for (int i = 0; i < hh.size(); ++i) {
            //如果遍历到一个房子
            if (hh[i].first == 0) {
                s.push({hh[i].second,last==-1?INT_MAX:hh[i].second-last});
            }
            //如果遍历到一个供暖器
            else {
                //修改上一个供暖器为当前供暖器
                last=hh[i].second;
                while (!s.empty()){
                    mRadius= max(mRadius, min(s.top().second,last-s.top().first));
                    s.pop();
                }
            }
        }
        while (!s.empty()){
            mRadius= max(mRadius,s.top().second);
            s.pop();
        }
        return mRadius;
    }

    void myMerge(vector<int> &houses, vector<int> &heaters) {
        int i = 0, j = 0;
        while (i < houses.size() && j < heaters.size()) {
            if (houses[i] < heaters[j]) {
                hh.push_back({0, houses[i++]});
            } else hh.push_back({1, heaters[j++]});
        }
        for (; i < houses.size(); ++i) {
            hh.push_back({0, houses[i]});
        }
        for (; j < heaters.size(); ++j) {
            hh.push_back({1, heaters[j]});
        }
    }
};

#endif //HOT100_475_H
