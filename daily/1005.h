//
// Created by 17336 on 2021/12/3.
//

#ifndef HOT100_1005_H
#define HOT100_1005_H

#include "vector"
#include "queue"

using namespace std;

struct mygreater{
    bool operator()(pair<int,int> const &a,pair<int,int> const &b)const{
        return a.first>b.first;
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int sum = 0,Nmin=INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mygreater> heap;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]<0){
                heap.push({nums[i],i});
            }
            Nmin= min(Nmin, abs(nums[i]));
            sum+=nums[i];
        }
        for ( ;k>0&&!heap.empty(); --k) {
            nums[heap.top().second]=-nums[heap.top().second];
            sum+=2*nums[heap.top().second];
            heap.pop();
        }
        if(k%2) sum-=2*Nmin;
        return sum;
    }
};

#endif //HOT100_1005_H
