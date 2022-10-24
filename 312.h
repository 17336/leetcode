//
// Created by 17336 on 2021/11/21.
//

#ifndef HOT100_312_H
#define HOT100_312_H

#endif //HOT100_312_H

#include "vector"
#include "queue"

using namespace std;

struct mygreater {
    bool operator()(pair<int,int> const &a, pair<int,int> const &b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, mygreater> heap;
        vector<pair<int,int>> linked(nums.size());
        int last_not_0=-1;
        for (int i = 0; i < nums.size(); ++i) {
            //寻找下一个不为0的邻接点
            int j=i+1;
            for (; j < nums.size(); ++j) {
                if(nums[j]) break;
            }
            //如果当前结点不为0，则插入
            if(nums[i]!=0){
                pair<int,int> temp{i,nums[i]};
                heap.push(temp);
                //存储i的邻接点下标
                linked[i].first=last_not_0;
                linked[i].second=j;
                last_not_0=i;
            }
            i=j;
        }
        int sum=0;
        while (!heap.empty()){
            pair<int,int> now=heap.top(),link;
            //如果队头结点左邻不为边界,则扎破当前结点
            if((link=linked[now.first]).first!=-1){
                heap.pop();
                sum+=now.second*(nums[link.first])*(link.second==-1?1:nums[link.second]);
                linked[link.first].second=link.second;
                if(link.second!=-1) linked[link.second].first=link.first;
            }
            else if(heap.size()==1){
                heap.pop();
                sum+=now.second;
                return sum;
            }
            else if(heap.size()==2){
                heap.pop();
                sum+=now.second*heap.top().second+heap.top().second;
                return sum;
            }
            else {
                heap.pop();
                pair<int,int> next=heap.top();
                heap.pop();
                sum+=
            }
        }
    }
};