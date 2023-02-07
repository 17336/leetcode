//
// Created by ByteDance on 2023/1/6.
//

#ifndef HOT100_2180_H
#define HOT100_2180_H

class Solution {
public:
    int countEven(int num) {
        int bit_sum=0,bit_count=0,temp=num,res=0;
        while (temp!=0) {
            int bit=temp%10;
            temp/=10;
            ++bit_count;
            bit_sum+=bit;
        }
    }
};

#endif //HOT100_2180_H
