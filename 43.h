//
// Created by 17336 on 2022/4/2.
//

#ifndef HOT100_43_H
#define HOT100_43_H

#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int begin=0;
        string res;
        for (int i = num1.size() - 1; i >= 0; --i) {
            int mulc = 0, curBegin = begin,addc=0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int temp = (mulc + (num1[i] - '0') * (num2[j] - '0'));
                if(curBegin >= res.size()){
                    res.push_back((temp%10+addc)%10+'0');
                    addc=(temp%10+addc)/10;
                } else {
                    char x=res[curBegin];
                    res[curBegin]= (res[curBegin] - '0' + temp % 10 + addc) % 10 + '0';
                    addc=(x-'0'+temp%10+addc)/10;
                }
                mulc = temp / 10;
                ++curBegin;
            }
            if(addc>0 || mulc > 0){
                res.push_back(addc + mulc + '0');
            }
            ++begin;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

#endif //HOT100_43_H
