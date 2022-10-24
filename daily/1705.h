//
// Created by 17336 on 2021/12/24.
//

#ifndef HOT100_1705_H
#define HOT100_1705_H

#include "map"
#include "vector"
#include "deque"
using namespace std;

class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        //last前一天可以吃的苹果数,sum为总共吃了的苹果数
        int last=0,n=apples.size(),sum=0,i=0;
        //map[day]=apples,即第day天可以吃的苹果数
        map<int,int> map;
        for (; i < n; ++i) {
            //第i+days[i]可食用的苹果会减少apples[i]个
            if(apples[i])map[i+days[i]]-=apples[i];
            //第i天可食用苹果数为前一天加上今天长出来的在减去腐烂的（再减去吃的一个）
            if((last=(last+apples[i]+(map.count(i)==0?0:map[i])))>0) {
                map.erase(i);
                ++sum;
                --last;
                if(++(map.begin()->second)==0)map.erase(map.begin());
            }
            map.erase(i);
        }
        //当这一天还有苹果可以吃
        while (last>0){
            if((last=last+(map.count(i)==0?0:map[i]))>0) {
                map.erase(i);
                ++sum;
                --last;
                if(++(map.begin()->second)==0)map.erase(map.begin());
            }
            map.erase(i);
            ++i;
        }
        return sum;
    }
};

#endif //HOT100_1705_H
