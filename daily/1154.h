//
// Created by 17336 on 2021/12/21.
//

#ifndef HOT100_1154_H
#define HOT100_1154_H

#include "string"

using namespace std;

class Solution {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int dayOfYear(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0'), month =
                (date[6] - '0') + (date[5] - '0') * 10, day = (date[8] - '0') * 10 + (date[9] - '0');
        int d=0;
        if(month>2&&((year%4==0&&year%100!=0)||(year%400==0))) d=1;
        for (int i = 0; i < month-1; ++i) {
            d+=days[i];
        }
        d+=day;
        return d;
    }
};

#endif //HOT100_1154_H
