//
// Created by 17336 on 2021/11/1.
//

#ifndef HOT100_17_H
#define HOT100_17_H

#endif //HOT100_17_H

#include "string"
#include "vector"

using namespace std;

class Solution {
    const string keyboard[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return res;
        string state;
        backtrack(digits,state,0);
        return res;
    }
    //回溯法
    void backtrack(string &digits,string &state,int i){
        if(i==digits.size()) {
            res.push_back(state);
            return;
        }
        for (const auto &item: keyboard[digits[i]-'0']) {
            state.push_back(item);
            backtrack(digits,state,i+1);
            state.pop_back();
        }
    }
};