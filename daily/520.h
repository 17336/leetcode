//
// Created by 17336 on 2021/11/13.
//

#ifndef HOT100_520_H
#define HOT100_520_H

#endif //HOT100_520_H

#include "string"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) return true;
        if (word[0] >= 'A' && word[0] <= 'Z') {
            if (word[1] >= 'A' && word[1] <= 'Z') {
                for (const auto &item: word) {
                    if (item < 'A' || item > 'Z') return false;
                }
                return true;
            } else {
                for (int i = 1; i < word.size(); ++i) {
                    if(word[i]<'a'||word[i]>'z') return false;
                }
                return true;
            }
        }else{
            for (const auto &item: word) {
                if (item < 'a' || item > 'z') return false;
            }
            return true;
        }
    }
};