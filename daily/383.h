//
// Created by 17336 on 2021/12/4.
//

#ifndef HOT100_383_H
#define HOT100_383_H

#include "string"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()) return false;
        int count[26]={0};
        for (const auto &item: magazine) {
            count[item-'a']++;
        }
        for (const auto &note: ransomNote) {
            if(--count[note-'a']<0) return false;
        }
        return true;
    }
};

#endif //HOT100_383_H
