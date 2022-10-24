//
// Created by 17336 on 2021/11/22.
//

#ifndef HOT100_384BAOLI_H
#define HOT100_384BAOLI_H

#endif //HOT100_384BAOLI_H

#include "vector"
#include "list"
#include "cstdlib"
using namespace std;

class Solution {
    list<int> waiting;
    vector<int> val;
public:
    Solution(vector<int>& nums) {
        for (const auto &item: nums) {
            val.push_back(item);
            waiting.push_back(item);
        }
    }

    vector<int> reset() {
        return val;
    }

    vector<int> shuffle() {
        //temp存储给定数组nums的副本，用链表结构，方便删除在nums中选中的数
        list<int> temp=waiting;
        //结果数组
        vector<int> res;
        //依次填满res的所有空位
        for (int i = 0; i < val.size(); ++i) {
            //取list中随机的一个数
            auto p=temp.begin();
            int r=rand()%(temp.size());
            int j=0;
            while (j++<r) p++;
            //插入到res中，并在list中删去
            res.push_back(*p);
            temp.erase(p);
        }
        return res;
    }
};