//
// Created by 17336 on 2022/1/3.
//

#ifndef HOT100_1185_H
#define HOT100_1185_H

#include "string"

using namespace std;


class Solution {
    string weeks[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    int monthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
public:
    string dayOfTheWeek(int day, int month, int year) {
        int dayGap=0;
        //首先不考虑闰年和year当年的天数，计算过了多少天
        dayGap+=(year-1971)*365;
        //考虑上中间闰年
        dayGap+=(year-1969)/4;
        //如果当年是闰年
        if(year!=2100&&month>2&&year%4==0) dayGap+=1;
        for (int i = 0; i < month-1; ++i) {
            dayGap+=monthDays[i];
        }
        dayGap+=day;
        return weeks[(3+dayGap)%7];
    }
};

#endif //HOT100_1185_H
