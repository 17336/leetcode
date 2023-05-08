//
// Created by 17336 on 2022/4/6.
//

#ifndef HOT100_6055_H
#define HOT100_6055_H

#include <string>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int gap= toMin(current)-toMin(correct),res=0;
        res+=gap/60;
        gap%=60;

        res+=gap/15;
        gap%=15

        res+=gap/5;
        gap%=5;.

        res+=gap;
        return res;
    }

    int toMin(string &time){
        return (time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+time[4]-'0';
    }
};

#endif //HOT100_6055_H
