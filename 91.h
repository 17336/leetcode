//
// Created by 17336 on 2022/4/22.
//

#ifndef HOT100_91_H
#define HOT100_91_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<int> memo;
    int len;
public:
    int numDecodings(string s) {
        memo.resize(s.size(), -1);
        len = s.size();
        return decode(s,0);
    }

    int decode(string &s, int begin) {
        if (begin == len) return 1;
        if (memo[begin] != -1) return memo[begin];
        if (s[begin] == '0') return memo[begin] = 0;
        if (begin == len - 1) return 1;
        int res=0;
        res+= decode(s,begin+1);
        if((s[begin]-'0')*10+s[begin+1]-'0'<=26) res+= decode(s,begin+2);
        return memo[begin]=res;
    }
};

#endif //HOT100_91_H
