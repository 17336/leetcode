//
// Created by 17336 on 2022/5/13.
//

#ifndef HOT100_01_05_H
#define HOT100_01_05_H

#include <string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.size(), len2 = second.size();
        if (abs(len1 - len2) > 1) return false;
        if (len2 == len1) {
            int diff = 0;
            for (int i = 0; i < len1; ++i) {
                if (first[i] != second[i]) ++diff;
                if (diff > 1) return false;
            }
            return true;
        }
        int l = max(len1, len2), diff = 0, i = 0, j = 0;
        while (i < len1 && j < len2) {
            if(first[i]!=second[j]){
                if(diff>0) return false;
                if(len1>len2) ++i;
                else ++j;
                ++diff;
            } else{
                ++i;
                ++j;
            }
        }
        return true;
    }
};

#endif //HOT100_01_05_H
