//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_557_H
#define HOT100_557_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
//        reverse(s.begin(),s.end());
        for (int i = 0; i < s.size(); ++i) {
            int j=i;
            while (j+1<s.size()&&s[j+1]!=' ') ++j;
            reverse(s.begin()+i,s.begin()+j+1);
            i=j+1;
        }
        return s;
    }
};

#endif //HOT100_557_H
