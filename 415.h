//
// Created by 17336 on 2022/3/26.
//

#ifndef HOT100_415_H
#define HOT100_415_H

#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string s;
        while (carry!=0||i >= 0 || j >= 0) {
            int v1 = i >= 0 ? num1[i] - '0' : 0, v2 = j >= 0 ? num2[j] - '0' : 0;
            s.push_back((v1 + v2 + carry) % 10+'0');
            carry = (v1 + v2 + carry) / 10;
            --i;
            --j;
        }
        i=0;
        while (i<s.size()/2){
            swap(s[i],s[s.size()-1-i]);
            ++i;
        }
        return s;
    }
};

#endif //HOT100_415_H
