//
// Created by 17336 on 2021/11/10.
//

#ifndef HOT100_495_H
#define HOT100_495_H

#endif //HOT100_495_H

#include "vector"

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int sum_sec=0,last_sec=-1;
        for (const auto &timeSery: timeSeries) {
            if(timeSery<=last_sec){
                sum_sec+=(timeSery+duration-last_sec-1);
            }
            else {
                sum_sec+=duration;
            }
            last_sec=timeSery+duration-1;
        }
        return sum_sec;
    }
};