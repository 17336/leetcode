//
// Created by 17336 on 2022/4/23.
//

#ifndef HOT100_678_H
#define HOT100_678_H

#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int left=0,star=0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='(') ++left;
            else if(s[i]=='*') ++star;
            else {
                if(left>0) --left;
                else if(star>0) --star;
                else return false;
            }
        }
        int right=0;
        star=0;
        for (int i = s.size()-1; i >=0 ; --i) {
            if(s[i]==')') ++right;
            else if(s[i]=='*') ++star;
            else{
                if(right) --right;
                else if(star) --star;
                else return false;
            }
        }
        return true;
    }
};

#endif //HOT100_678_H
