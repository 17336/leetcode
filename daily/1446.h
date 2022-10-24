//
// Created by 17336 on 2021/12/1.
//

#ifndef HOT100_1446_H
#define HOT100_1446_H

#include "string"

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int i = 0, power = 0;
        for (int j = 0; j < s.size(); ++j) {
            int temp = 1;
            while (j < s.size() - 1 &&s[j+1]==s[j]){
                j++;
                temp++;
            }
            power= max(power,temp);
        }
        return power;
    }
};

#endif //HOT100_1446_H
