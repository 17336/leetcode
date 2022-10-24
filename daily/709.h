//
// Created by 17336 on 2021/12/12.
//

#ifndef HOT100_709_H
#define HOT100_709_H

#include "string"

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (auto &item: s) {
            if(item>='A'&&item<='Z') item-='A'-'a';
        }
        return s;
    }
};

#endif //HOT100_709_H
