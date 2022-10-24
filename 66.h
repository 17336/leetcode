//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_66_H
#define HOT100_66_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry=1;
        for (int i = digits.size()-1; i >=0 ; --i) {
            int temp=digits[i];
            digits[i]=(digits[i]+carry)%10;
            carry=(temp+carry)/10;
            if (carry==0) return digits;
        }
        if (carry==1) digits.insert(digits.begin(),1);
        return digits;
    }
};

#endif //HOT100_66_H
