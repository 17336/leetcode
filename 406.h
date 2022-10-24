//
// Created by 17336 on 2021/11/29.
//

#ifndef HOT100_406_H
#define HOT100_406_H

#include "vector"
#include "algorithm"

using namespace std;

struct myless {
    bool operator()(vector<int> const &a,vector<int> const &b)const{
        return a[0]==b[0]?(a[1]>b[1]):(a[0]<b[0]);
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        vector<vector<int>> queue(people.size());
        //先排序，如果身高不等，身高小的排前面；身高相等则ki大的排前面
        sort(people.begin(), people.end(),myless());
        //对于people中每一个人，找他的插入位置：第ki+1个空位
        for (const auto &person: people) {
            int i=-1,j=-1;
            while (i!=person[1]){
                if(queue[++j].size()==0) i++;
            }
            queue[j]=person;
        }
        return queue;
    }
};

#endif //HOT100_406_H
