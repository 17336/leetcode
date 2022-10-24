//
// Created by 17336 on 2021/12/6.
//

#ifndef HOT100_1816_H
#define HOT100_1816_H

#include "string"

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        auto head=s.begin();
        while (head!=s.end()&&k!=0){
            head++;
            if(*head==' ')k--;
        }
        s.erase(head,s.end());
        return s;
    }
};

#endif //HOT100_1816_H
