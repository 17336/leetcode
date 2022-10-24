//
// Created by 17336 on 2022/1/9.
//

#ifndef HOT100_1629_H
#define HOT100_1629_H

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        int tMax = releaseTimes[0];
        char key = keysPressed[0];
        for (int i = 1; i < keysPressed.size(); ++i) {
            int temp=releaseTimes[i]-releaseTimes[i-1];
            if(temp>tMax) {
                tMax=temp;
                key=keysPressed[i];
            } else if(temp==tMax) key= max(key,keysPressed[i]);
        }
        return key;
    }
};

#endif //HOT100_1629_H
