//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_344_H
#define HOT100_344_H

#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        for (int i = 0; i < len/2; ++i) {
            swap(s[i],s[len-i-1]);
        }
    }
};

#endif //HOT100_344_H
